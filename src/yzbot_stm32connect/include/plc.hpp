#ifndef PLC_HPP_
#define PLC_HPP_

#include "rclcpp/rclcpp.hpp"

// 定义一个机器人位子结构体
struct Robot_pose
{
    float robot_x;      // X坐标
    float robot_y;      // Y坐标
    float robot_yaw;    // 角度
};

class PLC
{
public:
    PLC(RobotSerial *pRobotserial);
    ~PLC();

    //机器人的当前坐标  估计
    float g_x, g_y;
    //这个是 cmd_vel 中的速度 
    float g_vx, g_vy, g_vth;

private:
    RobotSerial *mRobotSerial;


};
#endif