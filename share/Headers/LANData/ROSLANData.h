#ifndef ROSLANDATA_H
#define ROSLANDATA_H
#include "../RBSharedMemory.h"
#include "JointInformation.h"

#ifndef __LAN_STRUCT_GENERAL_COMMAND_DEF__
#define __LAN_STRUCT_GENERAL_COMMAND_DEF__

typedef struct __LAN_STRUCT_GENERAL_COMMAND_
{
    char    param_c[10];
    int     param_i[10];
    float   param_f[10];
    int     cmd;
} LAN_GENERAL_COMMAND, *pLAN_GENERAL_COMMAND;

#endif

typedef struct __LAN_STRUCT_ROS2PODO__
{
    float   vx;
    float   vth;

    float   pos[3];
    float   desired_footsteps[15];
    unsigned int jh_step_phase;
    int     footstep_flag;
    int     lr_state;
} LAN_ROS2PODO,*pLAN_ROS2PODO;

typedef struct __LAN_STRUCT_PODO2ROS__
{
    float   JointReference[NO_OF_JOINTS];
    float   JointEncoder[NO_OF_JOINTS];

    float   odom_x;
    float   odom_y;
    float   odom_theta;
    float   vx;
    float   vy;
    float   vth;
    float   target_foot[6];
    int     robot_state;
    unsigned int step_phase;
    float   pel_pos_est[3];
    IMU_SENSOR IMU_ROS[MAX_IMU];
    FT_SENSOR FT_ROS[MAX_FT];

    LAN_GENERAL_COMMAND cmd;

} LAN_PODO2ROS, *pLAN_PODO2ROS;

#endif // ROSLANDATA_H
