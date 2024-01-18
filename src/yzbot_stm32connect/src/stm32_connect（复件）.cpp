#include "rclcpp/rclcpp.hpp"
#include "serial/serial.h"
#include <string>
#include <iostream>

using namespace std;

class Stm32_Connect : public rclcpp::Node
{
public:
    Stm32_Connect() : Node("stm32_connect")
    {
        initSerial();

        // 创建定时器，定期读取串口
        RCLCPP_INFO(this->get_logger(), "创建定时器，定期读取串口");
        timer_ = this->create_wall_timer(
            std::chrono::microseconds(100),
            std::bind(&Stm32_Connect::timerCallback, this));
    }

    void initSerial()
    {
        // 初始化串口
        try
        {
            RCLCPP_INFO(this->get_logger(), "初始化串口");
            serial_.setPort("/dev/ttyUSB0");
            serial_.setBaudrate(9600);
            serial::Timeout to = serial::Timeout::simpleTimeout(1000);
            serial_.setTimeout(to);
            serial_.open();
        } 
        catch(serial::IOException& e)
        {
            RCLCPP_INFO(this->get_logger(), "无法打开串口");
            exit(-1);
        }
    }

private:
    void timerCallback()
    {
        if(serial_.available())
        {
            std::string read_data = serial_.read(serial_.available());
            RCLCPP_INFO(this->get_logger(), "Received: %s", read_data.c_str());
        }
    }
    rclcpp::TimerBase::SharedPtr timer_;
    // 实例化串口对象
    serial::Serial serial_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    // 产生节点
    auto node = std::make_shared<Stm32_Connect>();
    // 运行节点，并检测退出信号
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}