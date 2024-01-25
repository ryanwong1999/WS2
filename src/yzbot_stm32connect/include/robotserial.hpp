#ifndef ROBOTSERIAL_HPP_
#define ROBOTSERIAL_HPP_

#include "rclcpp/rclcpp.hpp"
#include <boost/bind.hpp> 
#include <boost/thread.hpp>
#include <netinet/in.h>
#include <time.h>
#include <sys/timeb.h>
#include <serial/v8stdint.h>
#include <serial/serial.h>

#define TIME_OUT        10
#define MAX_RX_LEN      64
#define PRE_RATE        0.0174532925

class RobotSerial : public rclcpp::Node
{
public:
    RobotSerial(std::shared_ptr<serial::Serial> serial_l);
    ~RobotSerial();


    unsigned char index;
    unsigned char RecvBUF[MAX_RX_LEN];

    int neck_height = 0;
    float pulse_sec = 0;
    float wheel_diameter = 0;
    float wheel_distance = 0;

    unsigned char CRC8_Table(unsigned char *p, char counter);

    int autoCharge(int chargeFlag);
    int getPms(int &charging_flag, int &battary_level);
    int setSpeed(short int st1, short int st2, short int tag, double yaw, double d);
    int8_t getOdom(unsigned char &frameIndex, int16_t &t1, int16_t &t2, float &dbVth, float &dbVth_l, float &dbTh, int fmq, int16_t &vx, int16_t &vth);
    int8_t getHeadPose(int &level, int &pitch, int &switch_flag);
    int8_t getNeckPose(int &height, int &limit, int &done, int light, int bebebe);
    int8_t getRobotButton(int &audio_button, int &power_button, int &zs);
    int8_t setSensorEn(int carLight, int turnLight);
    int8_t getAutoSpeed(void);
    int getUltrasoundResult(int &cs_obs, int &fz_obs);
    int sendHeadCtrl(int direction);
    int sendHeadAngle(int level, int pitch);
    int sendNeckCtrl(int direction);
    int sendNeckHeight(int height);
    // void GetonlineStateCallback(const yzbot_msgs::walk_state msg);
    // void set_hand_callback(const yzbot_msgs::testt msg);
    int setAngleOffset(int8_t &level_offset, int8_t pitch_offset);


    int8_t robotSerialRead(void);


};

#endif
