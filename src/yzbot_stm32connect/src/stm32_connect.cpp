#include "stm32_connect.hpp"


std::shared_ptr<serial::Serial> serial_;
RobotSerial *RobotSerial_ = NULL;
PLC *PLC_ = NULL;
PMS *PMS_ = NULL;
// PSC *PSC_ = NULL;

using namespace std;


Stm32_Connect::Stm32_Connect() : Node("stm32_connect")
{
    initSerial();

    // 创建定时器
    timer_ = create_wall_timer(
        std::chrono::microseconds(100),
        std::bind(&Stm32_Connect::timerCallback, this));
    RCLCPP_INFO(get_logger(), "创建定时器");
}

Stm32_Connect::~Stm32_Connect()
{

}

void Stm32_Connect::initSerial()
{
    // 初始化串口
    serial_ = std::make_shared<serial::Serial>("/dev/ttyUSB0", 9600, serial::Timeout::simpleTimeout(1000));
    if(serial_->isOpen())
    {
        RCLCPP_INFO(get_logger(), "\033[32m串口打开成功!!\033[0m");
    }
    else
    {
        RCLCPP_WARN(get_logger(), "无法打开串口");
        rclcpp::shutdown();
    }
}

void Stm32_Connect::timerCallback()
{
    if(serial_->available())
    {
        std::string read_data = serial_->read(serial_->available());
        // RCLCPP_INFO(get_logger(), "Received: %s", read_data.c_str());
    }
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    // 产生节点
    auto node = std::make_shared<Stm32_Connect>();

    RobotSerial_ = new RobotSerial(serial_);
    PLC_ = new PLC(RobotSerial_);
    PMS_ = new PMS(RobotSerial_);
    // PSC_ = new PSC(RobotSerial_);
    // 运行节点，并检测退出信号
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
