#include "main.h"

pros::Motor intakeLeft(19,pros::E_MOTOR_GEAR_GREEN,true);
pros::Motor intakeRight(20,pros::E_MOTOR_GEAR_GREEN,false);
pros::Motor intakeMotor(18,pros::E_MOTOR_GEAR_BLUE,true);

void setIntakeBrake(){
        intakeLeft.set_brake_mode(MOTOR_BRAKE_HOLD);
        intakeRight.set_brake_mode(MOTOR_BRAKE_HOLD);
        intakeMotor.set_brake_mode(MOTOR_BRAKE_COAST);
}

void moveIntake(){

        if(master.get_digital(pros::E_CONTROLLER_DIGITAL_Y) && !master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)){
                intakeLeft=85;
                intakeRight=85;
        }else if(!master.get_digital(pros::E_CONTROLLER_DIGITAL_Y) && master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)){
                intakeLeft=-85;
                intakeRight=-85;
        }else{
                intakeLeft.brake();
                intakeRight.brake();
        }

        pros::delay(20);

}

void spinIntake(){

        if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && !master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){

                intakeMotor = 127;
                
        }else if(!master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){

                intakeMotor = -127;

        }else{
                intakeMotor.brake();
        }

        pros::delay(20);

}