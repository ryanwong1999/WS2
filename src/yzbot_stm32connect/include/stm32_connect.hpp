#ifndef __STM32_CONNECT_HPP__
#define __STM32_CONNECT_HPP__

#include "rclcpp/rclcpp.hpp"
#include "robotserial.hpp"
#include "plc.hpp"
// #include "pms.hpp"
// #include "psc.hpp"
#include "serial/serial.h"
#include <string>
#include <iostream>

class Stm32_Connect : public rclcpp::Node
{
public:
    Stm32_Connect();
    ~Stm32_Connect();


    void initSerial();

private:
    void timerCallback();

    rclcpp::TimerBase::SharedPtr timer_;
};

#endif