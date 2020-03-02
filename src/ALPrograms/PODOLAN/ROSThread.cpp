#include "ROSThread.h"
#include "../../Gazelle_Ankle_Kine/Gazelle_kine.h"


extern pRBCORE_SHM_COMMAND     sharedCMD;
extern pRBCORE_SHM_REFERENCE   sharedREF;
extern pRBCORE_SHM_SENSOR      sharedSEN;
extern pUSER_SHM               sharedUSER;

extern int     __IS_GAZEBO;


ROSWorker::ROSWorker()
{
    ROSflag = false;
    serverROS = new ROSServer();
    serverROS->RBServerOpen(QHostAddress::AnyIPv4, 6000);
    serverRST = new RSTServer();
    serverRST->RBServerOpen(QHostAddress::AnyIPv4, 6001);
    sendTimer = new QTimer(this);

    ROSflag = true;

    connect(serverROS, SIGNAL(SIG_NewConnection()), this, SLOT(ROSConnected()));
    connect(serverROS, SIGNAL(SIG_DisConnected()), this, SLOT(ROSDisconnected()));
    connect(serverRST, SIGNAL(SIG_NewConnection()), this, SLOT(RSTConnected()));
    connect(serverRST, SIGNAL(SIG_DisConnected()), this, SLOT(RSTDisconnected()));
    connect(serverROS, SIGNAL(ROS_UPDATE(char*)), this, SLOT(readCMD(char*)));
}

ROSWorker::~ROSWorker()
{
    printf("delete ROSWorker\n");
    if(ROSflag == true)
    {
        delete serverROS;
        delete serverRST;
        ROSflag = false;
    }
}

void ROSWorker::ROSConnected()
{
    connect(sendTimer, SIGNAL(timeout()), this, SLOT(sendSTATUS()));
    connect(sendTimer, SIGNAL(timeout()), this, SLOT(sendRESULT()));
    sendTimer->start(10);
    sharedUSER->M2G.ROSflag = true;
}

void ROSWorker::ROSDisconnected()
{
    sendTimer->stop();
    if(!serverROS->isListening())
        sharedUSER->M2G.ROSflag = false;
}

void ROSWorker::RSTConnected()
{
    emit RST_Connected();
}

void ROSWorker::RSTDisconnected()
{
    if(!serverRST->isListening())
        emit RST_Disconnected();
}

void ROSWorker::sendSTATUS()
{
    for(int i=0; i<NO_OF_JOINTS; i++)
    {
        status.joint_reference[i] = sharedSEN->ENCODER[MC_GetID(i)][MC_GetCH(i)].CurrentReference;
        status.joint_encoder[i] = sharedSEN->ENCODER[MC_GetID(i)][MC_GetCH(i)].CurrentPosition;
    }

    status.ft_sensor[0] = sharedSEN->FT[0].Mx;
    status.ft_sensor[1] = sharedSEN->FT[0].My;
    status.ft_sensor[2] = sharedSEN->FT[0].Mz;
    status.ft_sensor[3] = sharedSEN->FT[0].Fx;
    status.ft_sensor[4] = sharedSEN->FT[0].Fy;
    status.ft_sensor[5] = sharedSEN->FT[0].Fz;
    status.ft_sensor[6] = sharedSEN->FT[1].Mx;
    status.ft_sensor[7] = sharedSEN->FT[1].My;
    status.ft_sensor[8] = sharedSEN->FT[1].Mz;
    status.ft_sensor[9] = sharedSEN->FT[1].Fx;
    status.ft_sensor[10]= sharedSEN->FT[1].Fy;
    status.ft_sensor[11]= sharedSEN->FT[1].Fz;

    status.imu_sensor[0] = sharedSEN->IMU[0].Roll;
    status.imu_sensor[1] = sharedSEN->IMU[0].Pitch;
    status.imu_sensor[2] = sharedSEN->IMU[0].Yaw;
    status.imu_sensor[3] = sharedSEN->IMU[0].RollVel;
    status.imu_sensor[4] = sharedSEN->IMU[0].PitchVel;
    status.imu_sensor[5] = sharedSEN->IMU[0].YawVel;
    status.imu_sensor[6] = sharedSEN->IMU[0].AccX;
    status.imu_sensor[7] = sharedSEN->IMU[0].AccY;
    status.imu_sensor[8] = sharedSEN->IMU[0].AccZ;

    status.step_phase=sharedUSER->step_phase;

    for(int i=0;i<15;i++)
        status.given_footsteps[i] = sharedUSER->given_footsteps[i];

    status.lr_state = sharedUSER->lr_state;

    char *buf = new char[sizeof(P2R_status)];
    memcpy(buf, &status, sizeof(P2R_status));
    serverROS->RBSendData(buf, sizeof(P2R_status));
    delete [] buf;
}

void ROSWorker::sendRESULT()
{
    if(sharedUSER->FLAG_sendROS != CMD_BREAK && sharedUSER->FLAG_receivedROS == ROS_RX_EMPTY)
    {
        printf("send ros : %d\n",sharedUSER->FLAG_sendROS);
        result.gazelle_result = sharedUSER->FLAG_sendROS;
        result.step_phase = sharedUSER->step_phase;
        result.lr_state = sharedUSER->lr_state;

        char *buf = new char[sizeof(P2R_result)];
        memcpy(buf, &result, sizeof(P2R_result));
        serverRST->RBSendData(buf, sizeof(P2R_result));
        delete [] buf;
        sharedUSER->FLAG_sendROS = CMD_BREAK;
        sharedUSER->FLAG_receivedROS = ROS_RX_FALSE;
    }
}

void ROSWorker::readCMD(char* _data)
{
    printf("\n==========New Command for ROS received===========\n");
    memcpy(&command, _data, serverROS->RXSize);

    sharedUSER->ros_walking_cmd=command.ros_cmd;
    sharedUSER->ros_lr_state=command.lr_state;
    sharedUSER->ros_step_num=command.step_num;
    sharedUSER->ros_footstep_flag = command.footstep_flag;

    for(int i=0;i<15;i++)
        sharedUSER->ros_footsteps[i] = command.des_footsteps[i];

    switch(sharedUSER->ros_walking_cmd)
    {
    case ROSWALK_NORMAL_START:
        printf("    * ros_cmd = Normal_walking Start\n");
        break;
    case ROSWALK_SINGLELOG_START:
        printf("    * ros_cmd = SingleLog_walking Start\n");
        break;
    case ROSWALK_STOP:
        printf("    * ros_cmd = Walking Stop\n");
        break;
    }

    if(sharedUSER->ros_footstep_flag == true)
    {
        for(int m=0; m<15; m++)
        {
            sharedUSER->given_footsteps[m]=command.des_footsteps[m];
        }

        printf("    * flag is on. next 3 steps is\n");
        printf("    [%.2f, %.2f, %.2f], [%.2f, %.2f, %.2f], [%.2f, %.2f, %.2f]\n",
               sharedUSER->ros_footsteps[0],sharedUSER->ros_footsteps[1],sharedUSER->ros_footsteps[2],
                sharedUSER->ros_footsteps[3],sharedUSER->ros_footsteps[4],sharedUSER->ros_footsteps[5],
                sharedUSER->ros_footsteps[6],sharedUSER->ros_footsteps[7],sharedUSER->ros_footsteps[8]);

        if(sharedUSER->ros_lr_state == -1)
            printf("    * lr_state = RIGHT\n");
        else if(sharedUSER->ros_lr_state == 1)
            printf("    * lr_state = LEFT\n");

    }else
    {
        printf("    * flag is off\n");
    }
    printf("=====================================================\n");
    sharedUSER->FLAG_receivedROS = ROS_RX_TRUE;

}

ROSServer::ROSServer()
{
    TXSize = sizeof(P2R_status);
    RXSize = sizeof(R2P_command);
    data = new char[RXSize];
}

ROSServer::~ROSServer()
{
    printf("delete ROSserver\n");
    if(RBConnectionState == RBLAN_CS_CONNECTED)
        RBTcpClient->abort();
    RBTcpServer->close();
}

void ROSServer::ReadData()
{
    if(RBTcpClient->bytesAvailable() < RXSize)
        return;

    RBTcpClient->read(data, RXSize);
    emit ROS_UPDATE(data);
}

RSTServer::RSTServer()
{
    TXSize = sizeof(P2R_result);
}

RSTServer::~RSTServer()
{
    printf("delete RSTserver\n");
    if(RBConnectionState == RBLAN_CS_CONNECTED)
        RBTcpClient->abort();
    RBTcpServer->close();
}

void RSTServer::ReadData()
{

}
