#include "pms.hpp"

/**
  构造函数初始化
**/
PMS::PMS(RobotSerial *Robotserial_) : Node("pms")
{
    mRobotSerial = Robotserial_;

    pms_status_pub = this->create_publisher<yzbot_msgs::msg::PmsStatus>("pms_status", 10);
}

PMS::~PMS() {}

void PMS::getAutoChargeCallback(const yzbot_msgs::msg::ChargeCtrl::SharedPtr msg)
{
    int auto_charge_flag = 0;

    auto_charge_flag = msg->auto_charge_flag;
    // RCLCPP_INFO(this->get_logger(), "auto_charge_flag: %d", auto_charge_flag);
    
    if(auto_charge_flag == 0) mRobotSerial->autoCharge(0);
    else if(auto_charge_flag == 1) mRobotSerial->autoCharge(1);
}

  int PMS::queryPmsAll()
  {
    int get_pms = mRobotSerial->getPms(charging_flag, battery_level);
    if(get_pms != 0) return -1;

    yzbot_msgs::msg::PmsStatus pms_msg;
    pms_msg.pms_charging_flag = charging_flag;
    pms_msg.pms_battery_level = battery_level;
    // 发布消息
    pms_status_pub->publish(pms_msg);

    return 0;
  }