#include "robotserial.hpp"

std::shared_ptr<serial::Serial> mSerial;

int Time_Count = 0;

void *Timer_Callback(void *arge)
{
  while(1)
  {
    Time_Count++;
    // printf("Time_Count: %d\r\n", Time_Count);
    sleep(1);
  }
}

RobotSerial::RobotSerial(std::shared_ptr<serial::Serial> serial_) : Node("robot_serial")
{
    mSerial = serial_;
    index = 0;  
    memset(RecvBUF, 0, MAX_RX_LEN);  // 初始化接收缓冲 

    pthread_t pid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    int ret = pthread_create(&pid, &attr, Timer_Callback, NULL);
}

RobotSerial::~RobotSerial()
{
  
}

int8_t RobotSerial::robotSerialRead(void)
{
	static unsigned char dat = 0;
  
    RecvBUF[0] = dat;
	mSerial->read(RecvBUF+1, 1);
	dat = RecvBUF[1];
	if(RecvBUF[1] == 0xAA)
	{
		if(RecvBUF[0] == 0x55)
		{
			size_t read_byte = mSerial->read(RecvBUF+2, 17);
			if(((RecvBUF[RecvBUF[3]-2]) == 0x0D) && (RecvBUF[RecvBUF[3]-1]))
			{
     			// 校验CRC
     	 		uint8_t crc = CRC8_Table(RecvBUF, 16);
      		    //ROS_INFO("%02X", crc);
                if(RecvBUF[16] == crc) return 0;  // 校验正确返回0
                else
                {
                    RCLCPP_WARN(get_logger(), "校验错误! crc:%02X\r\n", crc);
                    return 1;   // 校验错误返回1
                }
		    }
            else return 1;      // 结束符检验错误
		}
	}
    else return -1;
}

int RobotSerial::autoCharge(int chargeFlag)
{
    RCLCPP_INFO(get_logger(), "Auto_Charging----%d", chargeFlag);
    uint8_t SendBUF[MAX_RX_LEN];
    memset(SendBUF, 0, MAX_RX_LEN);
    SendBUF[0] = 0x55;
    SendBUF[1] = 0xAA;
    SendBUF[2] = index;
    SendBUF[3] = 0x13;  // 长度
    SendBUF[4] = 0xFF;  // 源地址
    SendBUF[5] = 0x01;  // 目的地址
    SendBUF[6] = 0x08;  // 命令
    SendBUF[7] = 0x08;
    SendBUF[8] = chargeFlag;
    SendBUF[16] = CRC8_Table(SendBUF, 16);
    SendBUF[17] = 0x0D;
    SendBUF[18] = 0x0A;
    mSerial->write(SendBUF, 19);  

    Time_Count = 0;
    while(1)
    {
        if(Time_Count == TIME_OUT) return 1;
        
        int8_t tmp = robotSerialRead();   // 读数据
        if(!(tmp < 0))   // tmp= -1 // 未收到任何无线数据
        {
            if(tmp) return 1;
            else
            {
                int gongneng = RecvBUF[6];
                if(gongneng != 0x08) return -1;    
                RCLCPP_INFO(get_logger(), "--------Autocharging--------");
                return 0;
            }
        }
    } 
}

int RobotSerial::setSpeed(short int st1, short int st2, short int tag, double yaw, double d)   
{
    RCLCPP_INFO(get_logger(), "SetSpeed----");
    uint8_t SendBUF[MAX_RX_LEN];
    memset(SendBUF, 0, MAX_RX_LEN);    // 初始化
    memset(RecvBUF, 0, MAX_RX_LEN);

    SendBUF[0] = 0x55;
    SendBUF[1] = 0xAA;
    SendBUF[2] = index;
    SendBUF[3] = 0x13;  // 长度
    SendBUF[4] = 0xFF;  // 源地址
    SendBUF[5] = 0x01;  // 目的地址
    SendBUF[6] = tag;   // 命令
    SendBUF[7] = 0x08;

    st1 = (int16_t) htons(st1);
    st2 = (int16_t) htons(st2);
    int32_t mYaw = yaw * 100; 
    int32_t mDD  = d * 100;
    mYaw = (int32_t)htons(mYaw);
    mDD = (int32_t)htons(mDD);
    memcpy(&SendBUF[8], &st1, sizeof(short int));
    memcpy(&SendBUF[10], &st2, sizeof(short int));
    memcpy(&SendBUF[12], &mYaw, sizeof(short int));
    memcpy(&SendBUF[14], &mDD, sizeof(short int));

    int temp1 = 0;
    int temp2 = 0;
    memcpy(&temp1, &SendBUF[8], sizeof(short int));
    memcpy(&temp2, &SendBUF[10], sizeof(short int));

    SendBUF[16] = CRC8_Table(SendBUF, 16);
    SendBUF[17] = 0x0D;
    SendBUF[18] = 0x0A;
    mSerial->write(SendBUF, 19); 

    Time_Count = 0;
    while(1)
    {
        if(Time_Count == TIME_OUT) return 1;

        int8_t tmp = robotSerialRead();   // 读数据
        if(!(tmp<0))   // tmp= -1 // 未收到任何无线数据
        {
            if(tmp) return 1;
            else
            {
                int gongneng = RecvBUF[6];
                if(gongneng != tag) return -1;

                return 0;
            }
        }
    } 
}

int RobotSerial::getPms(int &Charging_Flag, int &Battary_Level)
{
    RCLCPP_INFO(get_logger(), "SetSpeed----");
    uint8_t SendBUF[MAX_RX_LEN];
    memset(SendBUF, 0, MAX_RX_LEN);
    memset(SendBUF, 0, MAX_RX_LEN);
    SendBUF[0] = 0x55;
    SendBUF[1] = 0xAA; 
    SendBUF[2] = index;
    SendBUF[3] = 0x13;
    SendBUF[4] = 0xFF;
    SendBUF[5] = 0x01;
    SendBUF[6] = 0x09;
    SendBUF[7] = 0x08;
    SendBUF[16] = CRC8_Table(SendBUF, 16);
    SendBUF[17] = 0x0D;
    SendBUF[18] = 0x0A;
    mSerial->write(SendBUF, 19);

    Time_Count = 0;
    while(1)
    {
        if(Time_Count == TIME_OUT) return 1;
        {
            int8_t tmp = robotSerialRead();   // 读数据
            if(!(tmp<0))   // tmp= -1 // 未收到任何无线数据
            {
                if(tmp) return 1;
                else
                {
                    /**
                    for(int k = 0; k < 19; k++)
                    {
                        RCLCPP_INFO(get_logger(), "pms %x", RecvBUF[k]);
                    }
                    **/
                    unsigned char recvFrameIndex=0;
                    unsigned char length;
                    unsigned char s_devid;
                    unsigned char p_devid;
                    unsigned char cmd;
                    int charging_flag = 0;
                    int battary_level = 0;
                    int gongneng = RecvBUF[6];
                    if(gongneng != 0x09)
                    {
                        return -1;
                    }
                    recvFrameIndex =  RecvBUF[2];
                    Charging_Flag = RecvBUF[11];
                    Battary_Level = RecvBUF[15];
                    // for(int t = 0; t < 19; t++)
                    // {
                    //     RCLCPP_INFO(get_logger(), "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@pms  %d",Charging_Flag);
                    // }
                    RCLCPP_INFO(get_logger(), "PMS_______: %d, %d", Charging_Flag, Battary_Level);
                    return 0;
                }
            }
        }
    }
}

int RobotSerial::sendNeckCtrl(int direction)
{ 
    RCLCPP_INFO(get_logger(), "SendNeckCtrl----");
    uint8_t SendBUF[MAX_RX_LEN];
    memset(SendBUF, 0, MAX_RX_LEN);    // 初始化
    memset(RecvBUF, 0, MAX_RX_LEN);
    SendBUF[0] = 0x55;
    SendBUF[1] = 0xAA;
    SendBUF[2] = index;
    SendBUF[3] = 0x13;  // 长度
    SendBUF[4] = 0xFF;  // 源地址
    SendBUF[5] = 0x01;  // 目的地址
    SendBUF[6] = 0x81;  // 命令
    SendBUF[7] = 0x08;
    SendBUF[8] = direction;
    memset(RecvBUF+9, 0, 7);
    SendBUF[16] = CRC8_Table(SendBUF, 16);
    SendBUF[17] = 0x0D;
    SendBUF[18] = 0x0A;
    RCLCPP_INFO(get_logger(), "SendNeckCtrl %d", direction);
    mSerial->write(SendBUF, 19);    

    while(1)
    {
        if(Time_Count == TIME_OUT) return 1;
        
        int8_t tmp = robotSerialRead();   // 读数据
        if(!(tmp<0))   // tmp= -1 // 未收到任何无线数据
        {
            if(tmp) return 1;
            else
            {
                int gongneng = RecvBUF[6];
                if(gongneng != 0x81) return -1;
                RCLCPP_INFO(get_logger(), "-----Send neck ctrl------");
                return 0;
            }
        }
    }
}


int RobotSerial::sendNeckHeight(int height)
{
    RCLCPP_INFO(get_logger(), "SendNeck_Height----");
    //height = height - 71;
    if(height <= 0) height = 0;
    if(height >= 120) height = 120;
    uint8_t SendBUF[MAX_RX_LEN];
    memset(SendBUF, 0, MAX_RX_LEN);
    memset(RecvBUF, 0, MAX_RX_LEN);
    SendBUF[0] = 0x55;
    SendBUF[1] = 0xAA;
    SendBUF[2] = index;
    SendBUF[3] = 0x13;  // 长度
    SendBUF[4] = 0xFF;  // 源地址
    SendBUF[5] = 0x01;  // 目的地址
    SendBUF[6] = 0x71;  // 命令
    SendBUF[7] = 0x08;
    SendBUF[8] = height >> 8;
    SendBUF[9] = height & 0xFF;
    SendBUF[16] = CRC8_Table(SendBUF, 16);
    SendBUF[17] = 0x0D;
    SendBUF[18] = 0x0A;
    RCLCPP_INFO(get_logger(), "neck height-----> %d", height);
    mSerial->write(SendBUF, 19);   

    while(1)
    {
        if(Time_Count == TIME_OUT) return 1;

        int8_t tmp = robotSerialRead();   // 读数据
        if(!(tmp<0))   // tmp= -1 // 未收到任何无线数据
        {
            if(tmp) return 1;
            else
            {
                int gongneng = RecvBUF[6];
                if(gongneng != 0x71) return -1;
                RCLCPP_INFO(get_logger(), "-----Send neck height-----");

                return 0;
            }
        }
    } 
}

int ttt1, ttt2;
int8_t RobotSerial::getOdom(unsigned char &frameIndex, int16_t &t1, int16_t &t2,
                           float &dbVth, float &dbVth_l, float &dbTh, int fmq, int16_t &vx, int16_t &vth)                       
{
    RCLCPP_INFO(get_logger(), "GetOdom----");
    static float angle_per = 0;
    uint8_t SendBUF[MAX_RX_LEN];
    memset(SendBUF, 0, MAX_RX_LEN);    // 初始化
    memset(RecvBUF, 0, MAX_RX_LEN);
    SendBUF[0] = 0x55;
    SendBUF[1] = 0xAA;
    SendBUF[2] = index;
    SendBUF[3] = 0x13;  // 长度
    SendBUF[4] = 0xFF;  // 源地址
    SendBUF[5] = 0x01;  // 目的地址
    SendBUF[6] = 0x01;  // 命令
    SendBUF[7] = 0x08;
    SendBUF[9] = fmq;
    memset(SendBUF+11, 0, 6);
    SendBUF[16] = CRC8_Table(SendBUF, 16);
    SendBUF[17] = 0x0D;
    SendBUF[18] = 0x0A;
    mSerial->write(SendBUF, 19);

    Time_Count = 0;
    memset(RecvBUF, 0, MAX_RX_LEN);
    while(1)
    {
        if(Time_Count == TIME_OUT)
        {
            // cmd_vel.linear.x = 0;
            // cmd_vel.linear.y = 0;
            // cmd_vel.linear.z = 0;
            // pub_cmd.publish(cmd_vel);
            // RCLCPP_INFO(get_logger(), "GetOdom timeout");
            // emerg_msg.Emergency_flag = 2;
            // Emergency_pub.publish(emerg_msg); 
            return 1;
        }
        //这个地方加 一个计时
        int8_t tmp = robotSerialRead();   // 读数据
        if(!(tmp<0))   // tmp= -1 // 未收到任何无线数据
        {
            if(tmp) return 1;  // 失败
            else
            {   
                // 返回0,表示接收到有效数据
                // 解析数据
                static float per_Angle = 0;
                static float per_Angle_l = 0;
                static float per_get_Angle = 0; 
                unsigned char recvFrameIndex = 0;
                unsigned char length;
                unsigned char s_devid;
                unsigned char p_devid;
                unsigned char cmd;
                int16_t mTick1 = 0;
                int16_t mTick2 = 0;
                int16_t mYaw = 0;  // 航向角
                int16_t mAngular_Rate = 0;
                recvFrameIndex =  RecvBUF[2];
                int gongneng = RecvBUF[6];
                // for(int t = 0; t < 19; t++)
                // {
                //     RCLCPP_INFO(get_logger(), "* %x",RecvBUF[t]);
                // }
                // RCLCPP_INFO(get_logger(), "get gongneng -----------%d", RecvBUF[6]);
                if(gongneng != 1) return 1;

                mTick1 = (int)RecvBUF[8]<<8 | RecvBUF[9];   // 转速脉冲1
                mTick2 = (int)RecvBUF[10]<<8 | RecvBUF[11]; // 转速脉冲2
                vx = (int16_t)RecvBUF[12]<<8 | RecvBUF[13];
                vth = (int16_t)RecvBUF[14]<<8 | RecvBUF[15];
                // if(ttt1 % 10 == 0 && mTick1 > 0) mTick1 = mTick1+1;
                ttt1 += mTick1;
                ttt2 += mTick2;
                // RCLCPP_INFO(get_logger(), "mTick1 = %d  --  mTick2 = %d  %d", mTick1, mTick2, ttt1);
                // RCLCPP_INFO(get_logger(), "pwm = %d pwm = %d ",(int)RecvBUF[12]<<8 | RecvBUF[13], (int)RecvBUF[14]<<8 | RecvBUF[15]);        
                memcpy(&mYaw, &RecvBUF[12], sizeof(int16_t));
                memcpy(&mAngular_Rate, &RecvBUF[14], sizeof(int16_t));
                mYaw = ntohs(mYaw);
                mAngular_Rate = ntohs(mAngular_Rate);
                // RCLCPP_INFO(get_logger(), "mTick1=%d, mTick2=%d, mYaw=%.2lf, mAngular_Rate=%.2lf\r\n", mTick1, mTick2, mYaw/100.0, mAngular_Rate/100.0);
                frameIndex = recvFrameIndex;
                t1 = mTick1;
                t2 = mTick2;

                struct tm *ptm;
                struct timeb stTimeb;
                static char szTime[19];

                ftime(&stTimeb);
                ptm = localtime(&stTimeb.time);
                sprintf(szTime, "%02d:%02d:%02d.%03d", ptm->tm_hour, ptm->tm_min, ptm->tm_sec, stTimeb.millitm);
                szTime[18] = 0;

                // RCLCPP_INFO(get_logger(), "@@@@@mAngular_Rate:%d vth:%d RecvBUF[14]:%d RecvBUF[15]:%d", mAngular_Rate, vth, RecvBUF[14], RecvBUF[15]);
                // RCLCPP_INFO(get_logger(), "%s %x %d @ %x %d--odom ma %x %d", szTime, t1, t1, t2, t2, RecvBUF[6], RecvBUF[6]);
                
                int16_t maichong = 0;  // 航向角
                memcpy(&maichong, &RecvBUF[8], 8);
                int16_t maichong2 = 0;  // 航向角
                memcpy(&maichong2, &RecvBUF[9], 8);
                // RCLCPP_INFO(get_logger(), "@@@@@@@@@@@@@  %d @@@@@ %d", maichong, maichong2);

                dbTh = mAngular_Rate;
                // RCLCPP_INFO(get_logger(), "############## %f  %f",mYaw/100.0, mAngular_Rate/100.0);

                dbVth =per_Angle + ((t2 - t1) * pulse_sec/( wheel_distance * PRE_RATE)) * 100;
                dbVth_l = per_Angle_l + ((t2 - t1) * pulse_sec/( wheel_distance * PRE_RATE)) * 100;

                if(dbVth > (180 * 100)) dbVth -= 360 * 100;
                else if(dbVth < (-180 * 100)) dbVth += 360 * 100;
                // RCLCPP_INFO(get_logger(), "@@@@@@@@@@@@@ t1:%d t2%d %f", t1, t2, dbVth/100.0);
                per_get_Angle = mYaw;
                per_Angle = dbVth;
                per_Angle_l = dbVth_l;

                return 0;
            }
        }
    }
}

// 获取自动充电时stm32给的速度
int8_t RobotSerial::getAutoSpeed()
{
    RCLCPP_INFO(get_logger(), "GetOdom----");
    uint8_t SendBUF[MAX_RX_LEN];
    memset(SendBUF, 0, MAX_RX_LEN);    // 初始化
    memset(RecvBUF, 0, MAX_RX_LEN);
    SendBUF[0] = 0x55;
    SendBUF[1] = 0xAA;
    SendBUF[2] = index;
    SendBUF[3] = 0x13;  // 长度
    SendBUF[4] = 0xFF;  // 源地址
    SendBUF[5] = 0x01;  // 目的地址
    SendBUF[6] = 0x04;  // 命令
    SendBUF[7] = 0x08;
    memset(SendBUF+8, 0, 8);
    SendBUF[16] = CRC8_Table(SendBUF, 16);
    SendBUF[17] = 0x0D;
    SendBUF[18] = 0x0A;
    mSerial->write(SendBUF, 19);

    Time_Count = 0;
    while(1)
    {
        if(Time_Count == TIME_OUT) return 1;
        
        int8_t tmp = robotSerialRead();
        if(!(tmp<0))
        {
            if(tmp)return 1;   // error
            else
            {
                // 解析数据
                double linear = (short)((RecvBUF[8]<<8) + RecvBUF[9]);     // 线速度
                double angular = (short)((RecvBUF[10]<<8) + RecvBUF[11]);  // 角速度
                int autoChargeTaskFlag = RecvBUF[12];
                int Emergency_flag = RecvBUF[13];
                int reChargeFlag = RecvBUF[14];

                // emerg_msg.Emergency_flag = Emergency_flag;
                // Emergency_pub.publish(emerg_msg); 

                // autocharge_msg.linear = (linear/1000)*0.7;
                // autocharge_msg.angular = (angular/1000)*0.7;
                // autocharge_msg.task_flag = autoChargeTaskFlag;
                // autocharge_msg.recharge_flag = reChargeFlag;
                // autocharge_pub.publish(autocharge_msg);

                // RCLCPP_INFO(get_logger(), "@@@ linear:%.2f  angular:%.2f  autoChargeTaskFlag:%d", autocharge_msg.linear, autocharge_msg.angular, autoChargeTaskFlag);
                return 0;
            }
        }
    }
}

int8_t RobotSerial::setSensorEn(int carLight, int turnLight)
{
  RCLCPP_INFO(get_logger(),"SetSensorEn---- carLight: %d  turnLight: %d", carLight, turnLight);
  uint8_t SendBUF[MAX_RX_LEN];
  memset(SendBUF, 0, MAX_RX_LEN);    // 初始化
  memset(RecvBUF, 0, MAX_RX_LEN);
  SendBUF[0] = 0x55;
  SendBUF[1] = 0xAA;
  SendBUF[2] = index;
  SendBUF[3] = 0x13;  // 长度
  SendBUF[4] = 0xFF;  // 源地址
  SendBUF[5] = 0x01;  // 目的地址
  SendBUF[6] = 0x77;  // 命令
  SendBUF[7] = 0x08;
  SendBUF[11] = carLight;
  SendBUF[12] = turnLight;
  memset(SendBUF+13, 0, 8);
  SendBUF[16] = CRC8_Table(SendBUF, 16);
  SendBUF[17] = 0x0D;
  SendBUF[18] = 0x0A;
  mSerial->write(SendBUF, 19);

  Time_Count = 0;
  while(1)
  {
    if(Time_Count == TIME_OUT) return 1;
    
    int8_t tmp = robotSerialRead();
    if(!(tmp<0))
    {
      if(tmp) return 1;   // error
      else
      {
        // 解析数据
        int carLight_result = RecvBUF[9];
        int turnLight_result = RecvBUF[10];
        // ROS_INFO("@@@ linear:%.2f  angular:%.2f  autoChargeTaskFlag:%d", autocharge_msg.linear, autocharge_msg.angular, autoChargeTaskFlag);
        return 0;
      }
    }
  }
}

// 获取按钮开关状态和噪声分贝值
int8_t RobotSerial::getRobotButton(int &audio_button, int &power_button, int &zs)
{
    RCLCPP_INFO(get_logger(), "get_robot_button----");
    uint8_t SendBUF[MAX_RX_LEN];
    memset(SendBUF, 0, MAX_RX_LEN);    // 初始化
    memset(RecvBUF, 0, MAX_RX_LEN);
    SendBUF[0] = 0x55;
    SendBUF[1] = 0xAA;
    SendBUF[2] = index;
    SendBUF[3] = 0x13;  // 长度
    SendBUF[4] = 0xFF;  // 源地址
    SendBUF[5] = 0x01;  // 目的地址
    SendBUF[6] = 0x09;  // 命令
    SendBUF[7] = 0x08;
    memset(SendBUF+8, 0, 8);
    SendBUF[16] = CRC8_Table(SendBUF, 16);
    SendBUF[17] = 0x0D;
    SendBUF[18] = 0x0A;
    mSerial->write(SendBUF, 19);
    Time_Count = 0;

    while(1)
    {
        if(Time_Count == TIME_OUT) return 1;
        
        int8_t tmp = robotSerialRead();
        if(!(tmp<0))
        {
            if(tmp) return 1;   // error
            else
            {
                // 解析数据
                audio_button = RecvBUF[10];
                power_button = RecvBUF[9];
                zs = (int)RecvBUF[12]<<8 | RecvBUF[13];
                zs = zs/10;
                return 0;
            }
        }
    }
}

int RobotSerial::getUltrasoundResult(int &cs_obs, int &fz_obs)
{
    RCLCPP_INFO(get_logger(), "get_ultrasound_result----");
    static int tmp = 0;
    uint8_t SendBUF[MAX_RX_LEN];
    memset(SendBUF, 0, MAX_RX_LEN);    // 初始化
    memset(RecvBUF, 0, MAX_RX_LEN);
    SendBUF[0] = 0x55;
    SendBUF[1] = 0xAA;
    SendBUF[2] = index;
    SendBUF[3] = 0x13;  // 长度
    SendBUF[4] = 0xFF;  // 源地址
    SendBUF[5] = 0x01;  // 目的地址
    SendBUF[6] = 0x07;  // 命令
    SendBUF[7] = 0x08;  //数据长度
    SendBUF[16] = CRC8_Table(SendBUF, 16);
    SendBUF[17] = 0x0D;
    SendBUF[18] = 0x0A;
    mSerial->write(SendBUF, 19);

    Time_Count = 0;
    while(1)
    {
        if(Time_Count == TIME_OUT) return 1;
        
        int8_t tmp = robotSerialRead();   // 读数据
        if(!(tmp<0))   // tmp= -1 // 未收到任何无线数据
        {
            if(tmp) return 1;  // 失败
            else
            {   
                // 返回0,表示接收到有效数据
                // 解析数据
                unsigned char recvFrameIndex=0;
                unsigned char length;
                unsigned char s_devid;
                unsigned char p_devid;
                unsigned char cmd;
                short int font_t = 0, left_t = 0, right_t = 0, back_t = 0;
                memcpy(&right_t, &RecvBUF[8], sizeof(int16_t));
                memcpy(&font_t, &RecvBUF[10], sizeof(int16_t));
                memcpy(&left_t, &RecvBUF[12], sizeof(int16_t));
                memcpy(&back_t, &RecvBUF[14], sizeof(int16_t));
                // RCLCPP_INFO(get_logger(), "ultra +++  %d, %d, %d", right_t, font_t, left_t);
                font_t = ntohs(font_t);
                left_t = ntohs(left_t);
                right_t = ntohs(right_t);
                back_t = ntohs(back_t);
                // RCLCPP_INFO(get_logger(), "ultra====  %d, %d, %d", right_t, font_t, left_t);
                cs_obs = 0, fz_obs = 0;
                cs_obs = RecvBUF[8];
                fz_obs = RecvBUF[9];
                // RCLCPP_INFO(get_logger(), "cs %d", cs_obs);
                // RCLCPP_INFO(get_logger(), "fz %d", fz_obs);
                double moto_cur = (short)((RecvBUF[11]<<8) + RecvBUF[12]);
                double bettery_vol = (short)((RecvBUF[14]<<8) + RecvBUF[15]);
                RCLCPP_INFO(get_logger(), "moto_cur %f, bettery_vol %f", moto_cur, bettery_vol);
                return 0;
            }
        }
    }
}

// 获取升降干状态
int8_t RobotSerial::getNeckPose(int &height, int &limit, int &done, int light, int bebebe)
{
    RCLCPP_INFO(get_logger(), "GetNeckPose----");
    uint8_t SendBUF[MAX_RX_LEN];
    memset(SendBUF, 0, MAX_RX_LEN);    // 初始化
    memset(RecvBUF, 0, MAX_RX_LEN);
    SendBUF[0] = 0x55;
    SendBUF[1] = 0xAA;
    SendBUF[2] = index;
    SendBUF[3] = 0x13;  // 长度
    SendBUF[4] = 0xFF;  // 源地址
    SendBUF[5] = 0x01;  // 目的地址
    SendBUF[6] = 0x61;  // 命令
    SendBUF[7] = 0x08;
    SendBUF[8] = light;
    SendBUF[9] = bebebe;
    memset(SendBUF+10, 0, 6);
    SendBUF[16] = CRC8_Table(SendBUF, 16);
    SendBUF[17] = 0x0D;
    SendBUF[18] = 0x0A;
    mSerial->write(SendBUF, 19);
    
    Time_Count = 0;
    while(1)
    {
        if(Time_Count == TIME_OUT) return 1;
        
        int8_t tmp = robotSerialRead();
        if(!(tmp<0))
        {
            if(tmp) return 1; // error
            else
            {
                // 解析数据
                short int mheight = 0;
                short int mlimit = 0;
                short int mdone = 0;

                height = (int)RecvBUF[8]<<8 | RecvBUF[9];

                limit = RecvBUF[10];
                done = RecvBUF[11];
                neck_height = height;

                return 0;
            }
        }
    }
}

int8_t RobotSerial::getHeadPose(int &Level, int &Vertical, int &switch_flag)
{
    RCLCPP_INFO(get_logger(), "GetHeadPose----");
    uint8_t SendBUF[MAX_RX_LEN];
    memset(SendBUF, 0, MAX_RX_LEN);
    memset(RecvBUF, 0, MAX_RX_LEN);
    SendBUF[0] = 0x55;
    SendBUF[1] = 0xAA;
    SendBUF[2] = index;
    SendBUF[3] = 0x13;
    SendBUF[4] = 0xFF;
    SendBUF[5] = 0x01;
    SendBUF[6] = 0x10;   //功能吗
    SendBUF[7] = 0x08;   //长度
    memset(SendBUF+8,0,8);
    SendBUF[16] = CRC8_Table(SendBUF, 16);
    SendBUF[17] = 0x0D;
    SendBUF[18] = 0x0A;
    mSerial->write(SendBUF, 19);

    Time_Count = 0;
    while(1)
    {
        if(Time_Count == TIME_OUT) return 1;
        
        int8_t tmp = robotSerialRead();
        if(!(tmp<0))
        {
            if(tmp) return 1; // error
            else
            {
                // 解析数据
                short int mlevel = 0;
                short int mpitch = 0;
                short int mSwitch_flag = 0;
                int gongneng = RecvBUF[6];
                
                if(gongneng != 0x10) return -1;

                memcpy(&mlevel, &RecvBUF[8], sizeof(int16_t));
                memcpy(&mpitch, &RecvBUF[10], sizeof(int16_t));
                // memcpy(&mSwitch_flag, &RecvBUF[13], sizeof(int8_t));
                // 急停按键
                switch_flag = RecvBUF[13];
                Level = ntohs(mlevel);
                Vertical = ntohs(mpitch);
                RCLCPP_INFO(get_logger(), "switch_flag: %d", switch_flag);
                return 0;
            }
        }
    }
}

int RobotSerial::sendHeadAngle(int level, int pitch)
{
    RCLCPP_INFO(get_logger(), "SendHead_angle----");
    uint8_t SendBUF[MAX_RX_LEN];
    memset(SendBUF, 0, MAX_RX_LEN);
    memset(RecvBUF, 0, MAX_RX_LEN);
    SendBUF[0] = 0x55;
    SendBUF[1] = 0xAA;
    SendBUF[2] = index;
    SendBUF[3] = 0x13;  // 长度
    SendBUF[4] = 0xFF;  // 源地址
    SendBUF[5] = 0x01;  // 目的地址
    SendBUF[6] = 0x11;  // 命令
    SendBUF[7] = 0x08;
    SendBUF[8] = level >> 8;
    SendBUF[9] = level & 0xFF;
    SendBUF[10] = pitch >> 8;
    SendBUF[11] = pitch & 0xFF;
    SendBUF[16] = CRC8_Table(SendBUF, 16);
    SendBUF[17] = 0x0D;
    SendBUF[18] = 0x0A;
    mSerial->write(SendBUF, 19);   

    while(1)
    {
        if(Time_Count == TIME_OUT) return 1;
        
        int8_t tmp = robotSerialRead();   // 读数据
        if(!(tmp<0))   // tmp= -1 // 未收到任何无线数据
        {
            if(tmp) return 1;
            else
            {
                int gongneng = RecvBUF[6];
                if(gongneng != 0x11) return -1;
                RCLCPP_INFO(get_logger(), "-----Send Head Angle ----- ");
                return 0;
            }
        }
    } 
}

int RobotSerial::setAngleOffset(int8_t &level_offset, int8_t pitch_offset)
{
    RCLCPP_INFO(get_logger(), "set_angle_offset----");
    uint8_t SendBUF[MAX_RX_LEN];
    memset(SendBUF, 0, MAX_RX_LEN);    // 初始化
    SendBUF[0] = 0x55;
    SendBUF[1] = 0xAA;
    SendBUF[2] = index;
    SendBUF[3] = 0x13;  // 长度
    SendBUF[4] = 0xFF;  // 源地址
    SendBUF[5] = 0x01;  // 目的地址
    SendBUF[6] = 0x75;  // 命令
    SendBUF[7] = 0x08;
    SendBUF[8] = 0x00;
    SendBUF[9] = 0x00;
    SendBUF[16] = CRC8_Table(SendBUF, 16);
    SendBUF[17] = 0x0D;
    SendBUF[18] = 0x0A;
    mSerial->write(SendBUF, 19); 

    Time_Count = 0;
    while(1)
    {
        if(Time_Count == TIME_OUT) return 1;
        
        int8_t tmp = robotSerialRead();   // 读数据
        if(!(tmp<0))   // tmp= -1 // 未收到任何无线数据
        {
            if(tmp) return 1;
            else
            {
                int gongneng = RecvBUF[6];
                if(gongneng != 0x75)
                {
                    level_offset = RecvBUF[8];
                    pitch_offset = RecvBUF[9];
                    return -1;
                }      
                RCLCPP_INFO(get_logger(), "set angle offset----   level_offset: %d, pitch_offset: %d", level_offset, pitch_offset);
                return 0;
            }
        }
    }  
}

int RobotSerial::sendHeadCtrl(int direction)
{ 
    RCLCPP_INFO(get_logger(), "SendHeadCtrl----");
    uint8_t SendBUF[MAX_RX_LEN];
    memset(SendBUF, 0, MAX_RX_LEN);    // 初始化
    memset(RecvBUF, 0, MAX_RX_LEN);
    SendBUF[0] = 0x55;
    SendBUF[1] = 0xAA;
    SendBUF[2] = index;
    SendBUF[3] = 0x13;  // 长度
    SendBUF[4] = 0xFF;  // 源地址
    SendBUF[5] = 0x01;  // 目的地址
    SendBUF[6] = 0x06;  // 命令
    SendBUF[7] = 0x08;
    switch(direction)
    {
        case 5:
        SendBUF[8]=0x05; 
        break;
        case 6:
        SendBUF[8]=0x06; 
        break;
        case 7:
        SendBUF[8]=0x07; 
        break;
        case 8:
        SendBUF[8]=0x08; 
        case 9:
        SendBUF[8]=0x09; 
        break;
        default:
        SendBUF[8]=0x10; 
        break;
    }
    SendBUF[8] = direction;
    memset(RecvBUF+9, 0, 7);
    SendBUF[16] = CRC8_Table(SendBUF, 16);
    SendBUF[17] = 0x0D;
    SendBUF[18] = 0x0A;
    mSerial->write(SendBUF, 19);   

    while(1)
    {
        if(Time_Count == TIME_OUT) return 1;
        
        int8_t tmp = robotSerialRead();   // 读数据
        if(!(tmp<0))   // tmp= -1 // 未收到任何无线数据
        {
            if(tmp) return 1;
            else
            {
                int gongneng = RecvBUF[6];
                if(gongneng != 0x06) return -1;

                RCLCPP_INFO(get_logger(), "-----Send Head Ctrl-----");
                return 0;
            }
        }
    } 
}


/*****************************************************
* CRC 校验表
*****************************************************/
const unsigned char CRC8Table[]=
{
  0, 94, 188, 226, 97, 63, 221, 131, 194, 156, 126, 32, 163, 253, 31, 65,
  157, 195, 33, 127, 252, 162, 64, 30, 95, 1, 227, 189, 62, 96, 130, 220,
  35, 125, 159, 193, 66, 28, 254, 160, 225, 191, 93, 3, 128, 222, 60, 98,
  190, 224, 2, 92, 223, 129, 99, 61, 124, 34, 192, 158, 29, 67, 161, 255,
  70, 24, 250, 164, 39, 121, 155, 197, 132, 218, 56, 102, 229, 187, 89, 7,
  219, 133, 103, 57, 186, 228, 6, 88, 25, 71, 165, 251, 120, 38, 196, 154,
  101, 59, 217, 135, 4, 90, 184, 230, 167, 249, 27, 69, 198, 152, 122, 36,
  248, 166, 68, 26, 153, 199, 37, 123, 58, 100, 134, 216, 91, 5, 231, 185,
  140, 210, 48, 110, 237, 179, 81, 15, 78, 16, 242, 172, 47, 113, 147, 205,
  17, 79, 173, 243, 112, 46, 204, 146, 211, 141, 111, 49, 178, 236, 14, 80,
  175, 241, 19, 77, 206, 144, 114, 44, 109, 51, 209, 143, 12, 82, 176, 238,
  50, 108, 142, 208, 83, 13, 239, 177, 240, 174, 76, 18, 145, 207, 45, 115,
  202, 148, 118, 40, 171, 245, 23, 73, 8, 86, 180, 234, 105, 55, 213, 139,
  87, 9, 235, 181, 54, 104, 138, 212, 149, 203, 41, 119, 244, 170, 72, 22,
  233, 183, 85, 11, 136, 214, 52, 106, 43, 117, 151, 201, 74, 20, 246, 168,
  116, 42, 200, 150, 21, 75, 169, 247, 182, 232, 10, 84, 215, 137, 107, 53
};


unsigned char RobotSerial::CRC8_Table(unsigned char *p, char counter)
{
  unsigned char crc8 = 0;
  for(; counter > 0; counter--)
  {
    crc8 = CRC8Table[crc8^*p];
    p++;
  }
  return(crc8);
}