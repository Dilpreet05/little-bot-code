#include "main.h"

bool isRightWingExtended = false;
bool waitingOnReleaseR1 = false;

bool isLeftWingExtended = false;
bool waitingOnReleaseL1 = false;

pros::ADIDigitalOut WingPistonLeft('B');
pros::ADIDigitalOut WingPistonRight('C');

void updatePistons(){
        
    ////////////////////////////
    //LEFT WING PISTON CONTROLS
    ////////////////////////////
    if((master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == 1)&& (isLeftWingExtended == false) && (waitingOnReleaseL1 == false) ) {
       WingPistonLeft.set_value(true);  // Deploy the piston
       isLeftWingExtended = true;   // Indicate it's set
       waitingOnReleaseL1 = true;  // Flag to wait for button release
     }
     else if( (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == 1) && (isLeftWingExtended == true) && (waitingOnReleaseL1 == false) ) {
       WingPistonLeft.set_value(false);  // Retract the piston
       isLeftWingExtended = false;  // Indicate it's not set
       waitingOnReleaseL1 = true;  // Flag to wait for button release
     }
     else if((master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == 0 )) {
       waitingOnReleaseL1 = false;  // Flag that button has been released, so next press will toggle to the opposite state
     }

    ////////////////////////////
    //RIGHT WING PISTON CONTROLS
    ////////////////////////////

    if((master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1)&& (isRightWingExtended == false) && (waitingOnReleaseR1 == false) ) {
       WingPistonRight.set_value(true);  // Deploy the piston
       isRightWingExtended = true;   // Indicate it's set
       waitingOnReleaseR1 = true;  // Flag to wait for button release
     }
     else if( (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1) && (isRightWingExtended == true) && (waitingOnReleaseR1 == false) ) {
       WingPistonRight.set_value(false);  // Retract the piston
       isRightWingExtended = false;  // Indicate it's not set
       waitingOnReleaseR1 = true;  // Flag to wait for button release
     }
     else if((master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 0 )) {
       waitingOnReleaseR1 = false;  // Flag that button has been released, so next press will toggle to the opposite state
     }

    pros::delay(20);

}