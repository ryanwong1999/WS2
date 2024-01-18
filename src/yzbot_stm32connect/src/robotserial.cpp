#include "robotserial.hpp"

std::shared_ptr<serial::Serial> mSerial;

#define TIME_OUT 10

int Time_Count = 0;

RobotSerial::RobotSerial(std::shared_ptr<serial::Serial> serial_) : Node("robot_serial")
{
    mSerial = serial_;
    index = 0;
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

int RobotSerial::Auto_Charging(int chargeFlag)
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