#include "stm32_connect.hpp"

using namespace std;

#define SERIAL_NAME     "/dev/ttyUSB1"
#define BAUDRATE        9600

Stm32_Connect::Stm32_Connect() : Node("stm32_connect")
{
    if(!initSerial()) 
    {
        RCLCPP_ERROR(get_logger(), "无法打开串口");
        throw std::runtime_error("无法打开串口");
    }

    RobotSerial_ = std::make_shared<RobotSerial>(serial_);
    PLC_ = std::make_shared<PLC>(RobotSerial_.get());
    PMS_ = std::make_shared<PMS>(RobotSerial_.get());
    PSC_ = std::make_shared<PSC>(RobotSerial_.get());
    //PLC
    cmd_vel_sub = this->create_subscription<geometry_msgs::msg::Twist>(
        "cmd_vel", 10, std::bind(&PLC::cmdVelCallback, PLC_, std::placeholders::_1));
    amcl_pose_sub = this->create_subscription<geometry_msgs::msg::PoseWithCovarianceStamped>(
        "amcl_pose", 10, std::bind(&PLC::amclPoseCallback, PLC_, std::placeholders::_1));
    fmq_sub = this->create_subscription<yzbot_msgs::msg::FmqSet>(
        "Fmq_set", 10, std::bind(&PLC::fmqCallback, PLC_, std::placeholders::_1));
    // PMS
    charge_sub = this->create_subscription<yzbot_msgs::msg::ChargeCtrl>(
        "auto_charge", 10, std::bind(&PMS::getAutoChargeCallback, PMS_, std::placeholders::_1));
    // PSC
    neck_control_sub = this->create_subscription<yzbot_msgs::msg::PscNeckControl>(
        "psc_neck_control", 10, std::bind(&PSC::neckControlByHeightCallback, PSC_, std::placeholders::_1));
    head_control_sub = this->create_subscription<yzbot_msgs::msg::PscHeadControl>(
        "psc_head_control", 10, std::bind(&PSC::headControlByAngleCallback, PSC_, std::placeholders::_1));
    key_neck_control_sub = this->create_subscription<yzbot_msgs::msg::PscKeyNeckControl>(
        "psc_key_neck_control", 10, std::bind(&PSC::neckControlByKeyCallback, PSC_, std::placeholders::_1));
    key_head_control_sub = this->create_subscription<yzbot_msgs::msg::PscKeyHeadControl>(
        "psc_key_head_control", 10, std::bind(&PSC::headControlByKeyCallback, PSC_, std::placeholders::_1));
    head_offset_sub = this->create_subscription<yzbot_msgs::msg::PscHeadOffset>(
        "psc_head_offset", 10, std::bind(&PSC::setHeadOffsetCallback, PSC_, std::placeholders::_1));
    // 创建定时器
    timer_ = create_wall_timer(
        std::chrono::microseconds(100),
        std::bind(&Stm32_Connect::timerCallback, this));
    RCLCPP_INFO(get_logger(), "创建定时器");
}

Stm32_Connect::~Stm32_Connect() {}

// 初始化串口
bool Stm32_Connect::initSerial()
{
    serial_ = std::make_shared<serial::Serial>(SERIAL_NAME, BAUDRATE, serial::Timeout::simpleTimeout(1000));
    if(serial_->isOpen())
    {
        RCLCPP_INFO(get_logger(), "\033[32m串口打开成功!!\033[0m");
        return true;
    }
    else
    {
        RCLCPP_WARN(get_logger(), "无法打开串口");
        return false;
    }
}

// 定时器
void Stm32_Connect::timerCallback()
{
    // if(serial_->available())
    // {
    //     std::string read_data = serial_->read(serial_->available());
    //     // RCLCPP_INFO(get_logger(), "Received: %s", read_data.c_str());
    // }
    static int cnt = 0;
    cnt++;
    
    PLC_->odomTimerDeal();  // 驱动器放在上面就注释掉

    switch (cnt)
    {
        case 1:
            // RCLCPP_INFO(get_logger(), "PSC_->queryNeckPose()");
            PSC_->queryNeckPose();
            break;
        case 2:
            // RCLCPP_INFO(get_logger(), "PSC_->queryHeadPose()");
            PSC_->queryHeadPose();
            break;
        case 3:
            // RCLCPP_INFO(get_logger(), "PSC_->queryObsState()");
            PSC_->queryObsState();
            break;
        case 4:
            // RCLCPP_INFO(get_logger(), "PSC_->queryRobotButton()");
            PSC_->queryRobotButton();
            break;
        case 5:
            // RCLCPP_INFO(get_logger(), "PMS_->queryPmsAll()");
            PMS_->queryPmsAll();
            break;
        // case 6:
        //     RCLCPP_INFO(get_logger(), "6");
        //     break;
        default:
            cnt = 0;
            break;
    }
    if(PSC_->psc_key_head_control_flag)
    {
        RobotSerial_->sendHeadCtrl(PSC_->psc_key_head_control_direction);
        PSC_->psc_key_head_control_flag = 0;
    }
    if(PSC_->psc_key_neck_control_flag)
    {
        RobotSerial_->sendNeckCtrl(PSC_->psc_key_neck_control_direction);
        PSC_->psc_key_neck_control_flag = 0;
    }
    if(PSC_->psc_angle_head_control_flag)
    {
        RobotSerial_->sendHeadAngle(PSC_->psc_goal_level, PSC_->psc_goal_pitch);
        PSC_->psc_angle_head_control_flag = 0;
        usleep(1000);
    }
    if(PSC_->psc_height_neck_control_flag)
    {
        RobotSerial_->sendNeckHeight(PSC_->psc_goal_height);
        PSC_->psc_height_neck_control_flag = 0;
        usleep(1000);
    }
    if(PSC_->psc_head_offset_en)
    {
        int8_t level_offset, pitch_offset;
        RobotSerial_->setAngleOffset(level_offset, pitch_offset);
        PSC_->psc_head_offset_en = 0;
    }
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    try
    {    
        // 产生节点
        auto node = std::make_shared<Stm32_Connect>();
        // 运行节点，并检测退出信号
        rclcpp::spin(node);
    }
    catch(const std::exception& e)
    {
        RCLCPP_ERROR(rclcpp::get_logger("stm32_connect"), "异常: %s", e.what());
    }
    rclcpp::shutdown();
    return 0;
}
