#include "ROSThread.h"
#include "../../Gazelle_Ankle_Kine/Gazelle_kine.h"


extern pRBCORE_SHM_COMMAND     sharedCMD;
extern pRBCORE_SHM_REFERENCE   sharedREF;
extern pRBCORE_SHM_SENSOR      sharedSEN;
extern pUSER_SHM               sharedUSER;

extern int     __IS_GAZEBO;

Gazelle_Kine GK;

ROSThread::ROSThread()
{
}

void ROSThread::run(){

    ROSWorker worker;
    QTimer fastTimer;
    QTimer timerPODO2ROS, timerROS2PODO;

    if(__IS_GAZEBO){
        worker.timePeriod = 0.005; // 5ms period for sending
        worker.timePrev = worker.timeCur = sharedSEN->Sim_Time_sec + sharedSEN->Sim_Time_nsec/1000000000.0;

        connect(&fastTimer, SIGNAL(timeout()), &worker, SLOT(onFastTimer()));
        fastTimer.start(1);
    }else{
        connect(&timerPODO2ROS, SIGNAL(timeout()), &worker, SLOT(onPODO2ROS()));
        connect(&timerROS2PODO, SIGNAL(timeout()), &worker, SLOT(onROS2PODO()));

        std::cout<<"JH Communication open!!"<<std::endl;

        timerPODO2ROS.start(50);
        timerROS2PODO.start(50);
    }
    exec();
}



ROSWorker::ROSWorker(){
    serverPODOROS = new PODO_ROS_Server();
    serverPODOROS->RBServerOpen(QHostAddress::AnyIPv4, 5000);
    if(__IS_GAZEBO){
        connect(serverPODOROS, SIGNAL(SIG_NewConnection()), this, SLOT(onNewConnection()));
    }
}

void ROSWorker::onNewConnection(){
    timePrev = timeCur = sharedSEN->Sim_Time_sec + sharedSEN->Sim_Time_nsec/1000000000.0;
}


void ROSWorker::onFastTimer(){
    // read data from ROS
    onROS2PODO();

    // send data to ROS
    timeCur = sharedSEN->Sim_Time_sec + sharedSEN->Sim_Time_nsec/1000000000.0;
    if(timeCur - timePrev >= timePeriod){
        timePrev = timeCur;
        onPODO2ROS();
    }else if(timeCur < timePrev-0.001){
        FILE_LOG(logERROR) << "SimTime Reversed..";
        FILE_LOG(logERROR) << "Probably New Gazebo is turned on..";
        FILE_LOG(logERROR) << "Reset the local timer..";

        timePrev = timeCur = sharedSEN->Sim_Time_sec + sharedSEN->Sim_Time_nsec/1000000000.0;
    }
}


void ROSWorker::SendtoROS(){
//    for(int i=0; i<NO_OF_JOINTS; i++){
//        TXData.JointReference[i] = sharedSEN->ENCODER[MC_GetID(i)][MC_GetCH(i)].CurrentReference;
//        TXData.JointEncoder[i] = sharedSEN->ENCODER[MC_GetID(i)][MC_GetCH(i)].CurrentPosition;
//    }
//    TXData.odom_x = sharedUSER->odom_data[0];
//    TXData.odom_y = sharedUSER->odom_data[1];
//    TXData.odom_theta = sharedUSER->odom_data[2];
//    TXData.vx = sharedUSER->odom_data[3];
//    TXData.vy = sharedUSER->odom_data[4];
//    TXData.vth = sharedUSER->odom_data[5];

//    memcpy(&(TXData.cmd), &(sharedUSER->G2M.ros_cmd), sizeof(LAN_GENERAL_COMMAND));
//    sharedUSER->G2M.ros_cmd.cmd = 0;

//    //FILE_LOG(logWARNING) << "Send to ROS: " << sizeof(LAN_PODO2ROS);
//    QByteArray SendData = QByteArray::fromRawData((char*)&TXData, sizeof(LAN_PODO2ROS));
//    serverPODOROS->RBSendData(SendData);

    for(int i=0; i<NO_OF_JOINTS; i++){
        TXData.JointReference[i] = sharedSEN->ENCODER[MC_GetID(i)][MC_GetCH(i)].CurrentReference;
        TXData.JointEncoder[i] = sharedSEN->ENCODER[MC_GetID(i)][MC_GetCH(i)].CurrentPosition;
    }

    //for gazelle
    double RAP_deg, RAR_deg;
    GK.FK_diff_Ankle_right(sharedSEN->ENCODER[MC_GetID(RAP)][MC_GetCH(RAP)].CurrentReference,
                            sharedSEN->ENCODER[MC_GetID(RAR)][MC_GetCH(RAR)].CurrentReference, 0, 0, RAP_deg, RAR_deg);
    TXData.JointReference[RAP] = RAP_deg;
    TXData.JointReference[RAR] = RAR_deg;

    GK.FK_diff_Ankle_right(sharedSEN->ENCODER[MC_GetID(RAP)][MC_GetCH(RAP)].CurrentPosition,
                            sharedSEN->ENCODER[MC_GetID(RAR)][MC_GetCH(RAR)].CurrentPosition, 0, 0, RAP_deg, RAR_deg);
    TXData.JointEncoder[RAP] = RAP_deg;
    TXData.JointEncoder[RAR] = RAR_deg;

    double LAP_deg, LAR_deg;
    GK.FK_diff_Ankle_left(sharedSEN->ENCODER[MC_GetID(LAP)][MC_GetCH(LAP)].CurrentReference,
                            sharedSEN->ENCODER[MC_GetID(LAR)][MC_GetCH(LAR)].CurrentReference, 0, 0, LAP_deg, LAR_deg);
    TXData.JointReference[LAP] = LAP_deg;
    TXData.JointReference[LAR] = LAR_deg;

    GK.FK_diff_Ankle_left(sharedSEN->ENCODER[MC_GetID(LAP)][MC_GetCH(LAP)].CurrentPosition,
                            sharedSEN->ENCODER[MC_GetID(LAR)][MC_GetCH(LAR)].CurrentPosition, 0, 0, LAP_deg, LAR_deg);
    TXData.JointEncoder[LAP] = LAP_deg;
    TXData.JointEncoder[LAR] = LAR_deg;

    TXData.odom_x = sharedUSER->odom_data[0];
    TXData.odom_y = sharedUSER->odom_data[1];
    TXData.odom_theta = sharedUSER->odom_data[2];
    TXData.vx = sharedUSER->odom_data[3];
    TXData.vy = sharedUSER->odom_data[4];
    TXData.vth = sharedUSER->odom_data[5];
    TXData.IMU_ROS[0] = sharedSEN->IMU[0];
    TXData.FT_ROS[0] = sharedSEN->FT[0];
    TXData.FT_ROS[1] = sharedSEN->FT[1];
    TXData.FT_ROS[2] = sharedSEN->FT[2];
    TXData.FT_ROS[3] = sharedSEN->FT[3];
    TXData.robot_state=sharedUSER->robot_state;
    TXData.pel_pos_est[0] = sharedUSER->pel_pos_estimated[0];
    TXData.pel_pos_est[1] = sharedUSER->pel_pos_estimated[1];
    TXData.pel_pos_est[2] = sharedUSER->pel_pos_estimated[2];

    TXData.step_phase=sharedUSER->step_phase;
    for(int m=0;m<6;m++)
    {
        TXData.target_foot[m]=sharedUSER->target_foot[m];
    }

    //FILE_LOG(logWARNING) << "Send to ROS: " << sizeof(LAN_PODO2ROS);
    QByteArray SendData = QByteArray::fromRawData((char*)&TXData, sizeof(LAN_PODO2ROS));
    serverPODOROS->RBSendData(SendData);

}

void ROSWorker::ReadfromROS(){
//    QByteArray tempData = serverPODOROS->dataReceived[0];
//    serverPODOROS->dataReceived.pop_front();

//    memcpy(&RXData, tempData.data(), sizeof(RXData));

//    sharedUSER->vel_cmd[0] = RXData.vx;
//    sharedUSER->vel_cmd[1] = RXData.vth;
//    sharedUSER->M2G.obj_pos[0] = RXData.pos[0];
//    sharedUSER->M2G.obj_pos[1] = RXData.pos[1];
//    sharedUSER->M2G.obj_pos[2] = RXData.pos[2];

    QByteArray tempData = serverPODOROS->dataReceived[0];
    serverPODOROS->dataReceived.pop_front();

    memcpy(&RXData, tempData.data(), sizeof(RXData));

    sharedUSER->vel_cmd[0] = RXData.vx;
    sharedUSER->vel_cmd[1] = RXData.vth;
    sharedUSER->M2G.obj_pos[0] = RXData.pos[0];
    sharedUSER->M2G.obj_pos[1] = RXData.pos[1];
    sharedUSER->M2G.obj_pos[2] = RXData.pos[2];

    sharedUSER->foot_flag=RXData.footstep_flag;
    sharedUSER->lr_state=RXData.lr_state;
    sharedUSER->jh_step_phase=RXData.jh_step_phase;

    std::cout<<sharedUSER->jh_step_phase<<std::endl;

    //    if(RXData.lr_state==1)
//    {
//        sharedUSER->lr_state=1;
//    }
//    else if(RXData.lr_state==0)
//    {
//        sharedUSER->lr_state=2;
//    }
//    else
//    {
//        sharedUSER->lr_state=-1;
//    }

    RXData.footstep_flag=0;
    if(sharedUSER->foot_flag==1){
        for(int m=0;m<15;m++){
            sharedUSER->given_footsteps[m]=RXData.desired_footsteps[m];
        }
    }

}


void ROSWorker::onPODO2ROS(){
    if(serverPODOROS->RBConnectionState == RBLAN_CS_CONNECTED){
        SendtoROS();
    }
}

void ROSWorker::onROS2PODO(){
    if(serverPODOROS->dataReceived.size() > 0){
        ReadfromROS();
    }
}

