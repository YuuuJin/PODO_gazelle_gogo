#ifndef ROSLANDATA_H
#define ROSLANDATA_H
#include "../RBSharedMemory.h"
#include "JointInformation.h"

enum COMMAND
{
    CMD_BREAK = 0,
    CMD_ACCEPT,
    CMD_DONE,
    CMD_ERROR,
    CMD_WALKING_FINISHED
};

enum RosCommand
{
    ROS_ROSWALK_BREAK = 0,
    ROS_ROSWALK_STOP,
    ROS_ROSWALK_NORMAL_START,
    ROS_ROSWALK_SINGLELOG_START
};

/*----------------------PODO(Gazelle) to ROS-------------------------*/
struct P2R_status
{
    int     robot_state;
    int     step_phase;

    int     lr_state;
    footstep_info   cur_footstep;
    float   pel_pos_est[3];

    float   joint_reference[31];
    float   joint_encoder[31];

    float   ft_sensor[12];
    float   imu_sensor[9];
};

struct P2R_result
{
    int     gazelle_result = CMD_BREAK;
    int     step_phase;
    int     lr_state;
};

/*--------------------------ROS to PODO(Gazelle)--------------------*/

struct R2P_command
{
    int             ros_cmd;

    footstep_info   des_footsteps[4];

    unsigned int    step_num;
    int             footstep_flag;
    int             lr_state;
};


#endif // ROSLANDATA_H
