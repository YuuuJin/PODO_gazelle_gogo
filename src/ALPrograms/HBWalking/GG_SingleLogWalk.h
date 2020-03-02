#ifndef GG_SINGLELOGWALK_H
#define GG_SINGLELOGWALK_H

#include "HB_PreviewWalk.h"

enum{
    NORMAL_WALKING = 0,
    SINGLELOG,
    FOOT_BRIDGE
};

class GG_SingleLogWalk : public HB_PreviewWalk
{
public:
    GG_SingleLogWalk();
    int Preveiw_walking();
    void WindowFill();
    void HB_set_step(vec3 _COM_ini, quat _qPel, vec3 _pRF, quat _qRF, vec3 _pLF, quat _qLF, double _WST_ini_deg, double _t_step, double _N_step, double _step_stride, int _RL_first);
    vec3 FootY_trajectory(double _real_t_step, double _t_foot_now, double _dsp_ratio, vec3 _y_dy_ddy_Foot_old, double _Y_footStep);
    void Set_walkingmode(int _mode) { Walking_mode = _mode;}
    void Calc_del_pos_from_ROS();
public:
    int ROSWalk_flag = false;
    int ROSWalk_off_flag = false;
    int Walking_mode = SINGLELOG;
    const double singlelog_w = 0.05;
    const double MaxFoot_y = 0.2;
    double MaxFoot_y_cur = MaxFoot_y;
    bool flag_send_ros;

    double cur_pos_x;
    double cur_pos_y;
    double cur_deg_z;
};

#endif // GG_SINGLELOGWALK_H
