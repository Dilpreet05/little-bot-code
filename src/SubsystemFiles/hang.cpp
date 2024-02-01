#include "main.h"

pros::Motor hangMotor(5,MOTOR_GEARSET_36,false);


void setHangBrake(){
        hangMotor.set_brake_mode(MOTOR_BRAKE_HOLD);
}

void updateHang(){
 
        if(LimitSwitch.get_value() == 1 && master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1){

                ratchetMotor = 127;
                pros::delay(25);
                hangMotor = 85;

        }else if((master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1) && (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) != 1)){
                // ratchetMotor = 40;
                // pros::delay(50);
                hangMotor = 85;
                // pros::delay(50);
                // ratchetMotor = 0;
        }else if((master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == 1) && (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) != 1) && !(LimitSwitch.get_value() == 1)){
                // ratchetMotor = -127;
                // pros::delay(50);
                hangMotor = -85;
                // pros::delay(50);
                // ratchetMotor = 0;
        }else if(LimitSwitch.get_value() == 1 && master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == 1){
                ratchetMotor = -127;
        }else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)==1){
                hangMotor = -50;
        }else{
                ratchetMotor = 0;
                ratchetMotor.brake();
                hangMotor.brake();
        }


        pros::delay(20);        
}
