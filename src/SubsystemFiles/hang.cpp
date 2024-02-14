#include "main.h"

pros::Motor hangMotor(5,MOTOR_GEAR_RED,false);


void setHangBrake(){
        hangMotor.set_brake_mode(MOTOR_BRAKE_HOLD);
}

void updateHang(){
 



        pros::delay(20);        
}
