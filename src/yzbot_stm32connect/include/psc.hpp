#ifndef PSC_HPP_
#define PSC_HPP_

#include "rclcpp/rclcpp.hpp"

// psc 的状态
struct psc_obs
{
  int cs;
  int fz;
};

// 按钮状态 和 噪声分贝值
struct psc_robot_button
{
  int audio_button;
  int power_button;
  int zs;
};

// psc 的状态
struct psc_status
{
  int level;
  int pitch;
};

struct psc_neck_status
{
  int height;
  int limit;
  int done;
};

// 环境数据
struct psc_envir
{
  float temp;
  float hum;
  float Co2;
  float Voc;
  float Pm25;
  float Pm10;
  float Pm1_0;
  float stata;
};

class PSC : public rclcpp::Node
{
public:
    PSC(RobotSerial *Robotserial_);
    ~PSC();


private:


};

#endif