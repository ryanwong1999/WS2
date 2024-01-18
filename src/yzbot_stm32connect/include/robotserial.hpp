#ifndef ROBOTSERIAL_HPP_
#define ROBOTSERIAL_HPP_

#include "rclcpp/rclcpp.hpp"
#include <serial/v8stdint.h>
#include <serial/serial.h>

#define MAX_RX_LEN    64

class RobotSerial : public rclcpp::Node
{
public:
    RobotSerial(std::shared_ptr<serial::Serial> serial_l);
    ~RobotSerial();


    unsigned char index;
    unsigned char RecvBUF[MAX_RX_LEN];

    unsigned char CRC8_Table(unsigned char *p, char counter);

    int Auto_Charging(int chargeFlag);
    int Get_Pms(int &Charging_Flag, int &Battary_Level);
    int SetSpeed(short int st1, short int st2, short int tag, double yaw, double d);
    int8_t GetOdom(unsigned char &frameIndex, int16_t &t1, int16_t &t2, float &dbVth, float &dbVth_l, float &dbTh, int fmq, int16_t &vx, int16_t &vth);
    int8_t GetHeadPose(int &Level, int &Vertical, int &switch_flag);
    int8_t GetNeckPose(int &height, int &limit, int &done, int light, int bebebe);
    int8_t get_robot_button(int &audio_button, int &power_button, int &zs);
    int8_t SetSensorEn(int carLight, int turnLight);
    int8_t GetAutoSpeed(void);
    int get_ultrasound_result(int &cs_obs, int &fz_obs);
    int SendHeardCtrl(int direction);
    int SendHead_angle(int level, int pitch);
    int SendNeckCtrl(int direction);
    int SendNeck_Height(int height);
    // void GetonlineStateCallback(const yzbot_msgs::walk_state msg);
    // void set_hand_callback(const yzbot_msgs::testt msg);
    int set_angle_offset(int8_t &level_offset, int8_t pitch_offset);


private:
    int8_t robotSerialRead(void);


};

#endif
