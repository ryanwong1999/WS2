#include "plc.hpp"

RobotSerial *mRobotSerial;

/**
  构造函数初始化
**/
PLC::PLC(RobotSerial *Robotserial_) : Node("plc")
{
    th_total_h = 0;
    
    mRobotSerial = Robotserial_;
    // 初始化发布者
    odom_pub = this->create_publisher<nav_msgs::msg::Odometry>("odom", 50);
    robot_pose_pub = this->create_publisher<yzbot_msgs::msg::RobotPose>("robot_pose", 10);
    
    cmd_vel_sub = this->create_subscription<geometry_msgs::msg::Twist>(
        "cmd_vel", 10, std::bind(&PLC::cmd_vel_callback, this, std::placeholders::_1));
    
    // 初始化 last_time
    last_time = this->now();
}

PLC::~PLC()
{

}

void PLC::cmd_vel_callback(const geometry_msgs::msg::Twist::SharedPtr cmd_vel)
{
    g_vx = cmd_vel->linear.x;
    g_vy = cmd_vel->linear.y;
    g_vth = cmd_vel->angular.z;
}


/**
  发布odom话题
**/ 
int PLC::pub_odom(short int vx, short int vy, short int t1, short int t2, float angle_v, float angle, float n_vx, float n_vth)
{
    static int tmp_t1 = 0, tmp_t2 = 0;
    static float per_angle = 0;
    tmp_t1 += t1;
    tmp_t2 += t2;
    rclcpp::Time current_time = this->now();
    double dt = (current_time - last_time).seconds();
    //这个是角速度 （弧度制）
    double vth = (angle - per_angle) * PRE_RATE/dt;   //(angle_v*PRE_RATE)/dt;
    double th_dt_h = (angle -per_angle) * PRE_RATE;

    th_total_h = angle * PRE_RATE;
    if(th_total_h > PI) th_total_h -= 2*PI; 
    else if(th_total_h <= -PI) th_total_h += 2*PI;

    double dt_x = ((t1 + t2) * pulse_sec * cos(th_total_h - th_dt_h + th_dt_h/2.0))/2.0;
    double dt_y = ((t1 + t2) * pulse_sec * sin(th_total_h - th_dt_h + th_dt_h/2.0))/2.0;
    double my_angle = th_total_h*(180/3.1415926);
    
    int left_t = t1, right_t = t2;
    if(-90<my_angle && my_angle<90)
    {
        if((left_t>0 && right_t>0) && dt_x<0)
            dt_x = -1*dt_x;
        if((left_t<0 && right_t<0) && dt_x>0)
            dt_x = -1*dt_x;
    }else{
        if((left_t<0 && right_t<0) && dt_x<0)
            dt_x = -1*dt_x;
        if((left_t>0 && right_t>0) && dt_x>0)
            dt_x = -1*dt_x;
    }

    if(my_angle>0)
    {
        if((left_t>0 && right_t>0) && dt_y<0)
            dt_y = -1*dt_y;
        if((left_t<0 && right_t<0) && dt_y>0)
            dt_y = -1*dt_y;
    }
    else
    {
        if((left_t<0 && right_t<0) && dt_y<0)
            dt_y = -1*dt_y;
        if((left_t>0 && right_t>0) && dt_y>0)
            dt_y = -1*dt_y;
    }
    
    // 累计下  x  y  的坐标 
    g_x += dt_x;
    g_y += dt_y;
    // 四元数转换
    tf2::Quaternion odom_quat;
    odom_quat.setRPY(0, 0, th_total_h);
    // publish the odometry message over Ros
    nav_msgs::msg::Odometry odom;
    odom.header.stamp = current_time;
    odom.header.frame_id = "odom_stm32";
    odom.pose.pose.position.x = g_x;
    odom.pose.pose.position.y = g_y;
    odom.pose.pose.position.z = 0;
    odom.pose.pose.orientation = tf2::toMsg(odom_quat);
    // set velocity
    odom.child_frame_id = "base_link_st32";
    odom.twist.twist.linear.x = (t1 + t2) * pulse_sec/dt/2.0;
    odom.twist.twist.linear.y = 0;
    odom.twist.twist.angular.z = vth;

   if((t1 + t2) * pulse_sec/dt/2.0 != 0 || vth != 0)
   {
        odom.pose.covariance = {0.001, 0, 0, 0, 0, 0, 
                                0, 0.001, 0, 0, 0, 0,
                                0, 0, 1000000, 0, 0, 0,
                                0, 0, 0, 1000000, 0, 0,
                                0, 0, 0, 0, 1000000, 0,
                                0, 0, 0, 0, 0, 1000};
        odom.twist.covariance = {0.001, 0, 0, 0, 0, 0, 
                                0, 0.001, 0, 0, 0, 0,
                                0, 0, 1000000, 0, 0, 0,
                                0, 0, 0, 1000000, 0, 0,
                                0, 0, 0, 0, 1000000, 0,
                                0, 0, 0, 0, 0, 1000};
    }
    else
    {
        odom.pose.covariance = {0.000000001, 0, 0, 0, 0, 0, 
                                0, 0.001, 0.000000001, 0, 0, 0,
                                0, 0, 1000000, 0, 0, 0,
                                0, 0, 0, 1000000, 0, 0,
                                0, 0, 0, 0, 1000000, 0,
                                0, 0, 0, 0, 0, 0.000000001};
        odom.twist.covariance = {0.000000001, 0, 0, 0, 0, 0, 
                                0, 0.001, 0.000000001, 0, 0, 0,
                                0, 0, 1000000, 0, 0, 0,
                                0, 0, 0, 1000000, 0, 0,
                                0, 0, 0, 0, 1000000, 0,
                                0, 0, 0, 0, 0, 0.000000001};
    }
    
    odom_pub->publish(odom);
    last_time = current_time;

    return 0;
}

void PLC::pub_robot_pose(int left_t, int right_t, double angle_t, double angle_l)
{
  static float per_angle = 0;
  static float trueth_angle = 0;

}

// void PLC::plc_Timer_deal_odom()
// {
//   unsigned char frameIndex = 0;
//   int16_t t1 = 0, t2 = 0;
//   float dbTh = 0, dbVth = 0, dbTh_l = 0;
//   int16_t vx = 0, vth = 0;

//   int get_odom = mRobotSerial->GetOdom(frameIndex, t1, t2, dbTh, dbTh_l, dbVth, fmq_status_flag, vx, vth); 
//   pub_odom(g_vx, g_vy, t1, t2, (float)(dbVth/100.0), (float)(dbTh/100.0), (float)(vx/1000.0), (float)(vth/1000.0));  
//   pub_robot_pose(t1, t2, (float)(dbTh/100.0), (float)(dbTh_l/100.0));

//   mRobotSerial->SetSpeed(g_vx*1000, g_vth*1000, 0x15, mRobotPose_yaw, mD);
// }

// void PLC::get_auto_speed()
// {
//   int autospeed = mRobotSerial->GetAutoSpeed();
// }