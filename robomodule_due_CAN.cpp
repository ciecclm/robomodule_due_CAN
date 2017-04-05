//
//  robomodule_due_CAN.cpp
//  
//
//  Created by 朝力萌 on 2016/11/26.
//
//

#include "robomodule_due_CAN.h"
void CRobomodule_due_CAN::resetdrive(int group=0,int number=0)
{
    outgoing.id=((uint32_t)group)<<8|(uint32_t)((number<<4)&0xf0);
    outg.length=8;
    outgoing.pgoing.extended = false;
    outgoinriority = 4; //0-15 lower is higher priority
    outgoing.data.high=0x55555555;
    outgoing.data.low=0x55555555;
    Can0.sendFrame(outgoing);
    delay(500);
}
void CRobomodule_due_CAN::setmode(int group=0,int number=0,int mode=3 )
{
    CAN_FRAME outgoing;
    //outgoing.id = temp;//0x021;
    outgoing.id = ((uint32_t)group)<<8|(uint32_t)(((number<<4)|0x01)&0xf1);
    outgoing.extended = false;
    outgoing.length=8;
    outgoing.priority = 4; //0-15 lower is higher priority
    outgoing.data.high=0x55555555;
    outgoing.data.low=0x55555555;
    outgoing.data.bytes[0]=mode;
    Can0.sendFrame(outgoing);
    delay(500);
}

void CRobomodule_due_CAN::speedwheel(int temp_pwm,int temp_velocity,int group=0,int number=0)
{
    CAN_FRAME outgoing;
    outgoing.id = ((uint32_t)group)<<8|(uint32_t)(((number<<4)|0x04)&0xf4);
    outgoing.extended = false;
    outgoing.length=8;
    outgoing.priority = 4; //0-15 lower is higher priority
    outgoing.data.high=0x55555555;
    outgoing.data.low=0x55555555;
    outgoing.data.bytes[0] = ( char)((temp_pwm>>8)&0xff);
    outgoing.data.bytes[1] = ( char)(temp_pwm & 0xff);
    outgoing.data.bytes[2] = ( char)((temp_velocity>>8) & 0xff);
    outgoing.data.bytes[3] = ( char)(temp_velocity & 0xff);
    Can0.sendFrame(outgoing);
}
CRobomodule_due_CAN::CRobomodule_due_CAN(int baud=CAN_BPS_1000K,int group=0,int number=0,int mode=3)
{
    Can0.begin(baud);
    Can0.watchFor();
    resetdrive(group,number);
    setmode(group,number,mode);
}

