#include "main.h"

pros::Motor ratchetMotor(17,MOTOR_GEARSET_18,false);
pros::ADIDigitalIn LimitSwitch('A');



void updateRatchet(){
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) == 1 && master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) != 1){

        ratchetMotor = -127;
        pros::delay(50);
        ratchetMotor = 0;
    
    }else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) != 1 && master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) == 1){

        ratchetMotor = 127;
        pros::delay(50);
        ratchetMotor = 0;

    }else{
        ratchetMotor.brake();
    }
}

void setRatchetBrake(){
    ratchetMotor.set_brake_mode(MOTOR_BRAKE_COAST);
}