//
//  robomodule_due_CAN.h
//  
//
//  Created by 朝力萌 on 2016/11/26.
//
//

#ifndef robomodule_due_CAN_h
#define robomodule_due_CAN_h
#include "variant.h"
#include "due_can.h"
#endif /* robomodule_due_CAN_h */

class CRobomodule_due_CAN
{
private:
    int driver_group;
    int driver_number;
    int driver_mode;
    CAN_FRAME outgoing;
public:
    CRobomodule_due_CAN(int baud,int group,int number,int mode);
    void initdriver();
    void resetdrive(int group=0,int number=0 );
    void setmode(int group=0,int number=0,int mode=3 );
    void speedwheel(int temp_pwm,int temp_velocity,int group=0,int number=0);
};