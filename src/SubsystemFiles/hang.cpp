#include "main.h"

pros::Motor hangMotor(3,MOTOR_GEARSET_36,false);


void setHangBrake(){
        hangMotor.set_brake_mode(MOTOR_BRAKE_HOLD);
}

void updateHang(){
 

        if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && !master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
                hangMotor = 90;
        }else if(!master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
                hangMotor = -90;
        }else{
                hangMotor.brake();
        }

        pros::delay(20);        
}
