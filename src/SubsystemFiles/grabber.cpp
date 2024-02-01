#include "main.h"

pros::Motor grabberLeft(17,pros::E_MOTOR_GEARSET_18,false);
pros::Motor grabberRight(16,pros::E_MOTOR_GEARSET_18,true);

void setGrabberBrake(){
    grabberLeft.set_brake_mode(MOTOR_BRAKE_HOLD);
    grabberRight.set_brake_mode(MOTOR_BRAKE_HOLD);
}

void moveGrabber(){
    if((master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == 1) && (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) != 1)){
        grabberLeft = -80;
        grabberRight = -80;
    }
    else if((master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) != 1) && (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == 1)){
        grabberLeft = 80;
        grabberRight = 80;
    }
    else{
        grabberLeft = 0;
        grabberRight = 0;
        grabberLeft.brake();
        grabberRight.brake();
    }
    pros::delay(20);
}