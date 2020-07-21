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
    sendTimer->start(20);
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
    status.step_phase = sharedUSER->step_phase;

    status.pel_pos_est[0] = sharedUSER->pel_pose[0];
    status.pel_pos_est[1] = sharedUSER->pel_pose[1];
    status.pel_pos_est[2] = sharedUSER->pel_pose[2];

    status.pel_quaternion[0] = sharedUSER->pel_quat[0];
    status.pel_quaternion[1] = sharedUSER->pel_quat[1];
    status.pel_quaternion[2] = sharedUSER->pel_quat[2];
    status.pel_quaternion[3] = sharedUSER->pel_quat[3];

    char *buf = new char[sizeof(P2R_status)];
    memcpy(buf, &status, sizeof(P2R_status));
    serverROS->RBSendData(buf, sizeof(P2R_status));
    delete [] buf;
}

void ROSWorker::sendRESULT()
{
    if(sharedUSER->FLAG_sendROS != CMD_BREAK)
    {
        FILE_LOG(logSUCCESS) << "ROSthread::send to ros";
        printf("sendros flag is %d\n",sharedUSER->FLAG_sendROS);

        result.gazelle_result = sharedUSER->FLAG_sendROS;
        result.step_phase = sharedUSER->step_phase;
//        result.lr_state = sharedUSER->lr_state;

        printf("result : %d\n",result.step_phase);
        printf("cur pel pos : %f, %f\n",sharedUSER->pel_pose[0], sharedUSER->pel_pose[1]);

        char *buf = new char[sizeof(P2R_result)];
        memcpy(buf, &result, sizeof(P2R_result));
        serverRST->RBSendData(buf, sizeof(P2R_result));
        delete [] buf;

        sharedUSER->FLAG_sendROS = CMD_BREAK;
        printf("send done kk\n");
    }
}

void ROSWorker::readCMD(char* _data)
{
    /*
     * callback when received data from ros
     *
     * functions :
     *      received data upload to sharedUSER
     *      print data
     *      change flag
    */

    FILE_LOG(logSUCCESS) << "New Command from ROS==================";
    memcpy(&command, _data, serverROS->RXSize);


    // received data upload to sharedUSER
    sharedUSER->ros_walking_cmd=command.ros_cmd;
    sharedUSER->ros_lr_state=command.lr_state;
    sharedUSER->ros_step_num=command.step_num;
    sharedUSER->ros_footstep_flag = command.footstep_flag;

    for(int i=0; i<4; i++)
    {
        sharedUSER->ros_footsteps[i].x = command.des_footsteps[i].x;
        sharedUSER->ros_footsteps[i].y = command.des_footsteps[i].y;
        sharedUSER->ros_footsteps[i].z = command.des_footsteps[i].z;
        sharedUSER->ros_footsteps[i].yaw = command.des_footsteps[i].yaw;
        sharedUSER->ros_footsteps[i].step_phase = command.des_footsteps[i].step_phase;
        sharedUSER->ros_footsteps[i].lr_state = command.des_footsteps[i].lr_state;

        printf("%d, step_phase = %d, lr_State = %d\n",i,sharedUSER->ros_footsteps[i].step_phase, sharedUSER->ros_footsteps[i].lr_state);

    }

    switch(sharedUSER->ros_walking_cmd)
    {
    case ROS_ROSWALK_NORMAL_START:
        printf("    * ros_cmd = Normal_walking Start\n");
        break;
    case ROS_ROSWALK_SINGLELOG_START:
        printf("    * ros_cmd = SingleLog_walking Start\n");
        break;
    case ROS_ROSWALK_STOP:
        printf("    * ros_cmd = Walking Stop\n");
        break;
    }

    if(sharedUSER->ros_footstep_flag == true)
    {
        printf("    * flag is on. next 4 steps is\n");
        printf("    [%dth :%.2f, %.2f, %.2f], [%dth :%.2f, %.2f, %.2f]\n    [%dth :%.2f, %.2f, %.2f], [%dth :%.2f, %.2f, %.2f]\n",
                sharedUSER->ros_footsteps[0].step_phase, sharedUSER->ros_footsteps[0].x, sharedUSER->ros_footsteps[0].y, sharedUSER->ros_footsteps[0].yaw,
                sharedUSER->ros_footsteps[1].step_phase, sharedUSER->ros_footsteps[1].x, sharedUSER->ros_footsteps[1].y, sharedUSER->ros_footsteps[1].yaw,
                sharedUSER->ros_footsteps[2].step_phase, sharedUSER->ros_footsteps[2].x, sharedUSER->ros_footsteps[2].y, sharedUSER->ros_footsteps[2].yaw,
                sharedUSER->ros_footsteps[3].step_phase, sharedUSER->ros_footsteps[3].x, sharedUSER->ros_footsteps[3].y, sharedUSER->ros_footsteps[3].yaw);

        if(sharedUSER->ros_lr_state == -1)
            printf("    * lr_state = RIGHT\n");
        else if(sharedUSER->ros_lr_state == 1)
            printf("    * lr_state = LEFT\n");

    }else
    {
        printf("    * flag is off\n");
    }

    sharedUSER->FLAG_receivedROS = ROS_RX_TRUE;
    FILE_LOG(logSUCCESS)<<"===========================================\n";
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
