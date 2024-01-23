#ifndef PMS_HPP_
#define PMS_HPP_

#include "rclcpp/rclcpp.hpp"
#include "robotserial.hpp"
#include "yzbot_msgs/msg/charge_ctrl.hpp"
#include "yzbot_msgs/msg/pms_status.hpp"

// 电池的电流和电压
struct pms_status
{
  int cur;
  int vol;
};

class PMS : public rclcpp::Node
{
public:
    PMS(RobotSerial *Robotserial_);
    ~PMS();

    int battery_level = 0, charging_flag = 0;
    int back_ = 0;

    int queryPmsAll(void);
    void getAutoChargeCallback(const yzbot_msgs::msg::ChargeCtrl::SharedPtr msg);

private:
    RobotSerial *mRobotSerial;
    rclcpp::Publisher<yzbot_msgs::msg::PmsStatus>::SharedPtr pms_status_pub;
};

#endif