#include "main.h"

bool isFlipped = false;

// Chassis constructor
ez::Drive chassis ({-1,-2,-3}, {8,9,10}, 21 ,2.75,600,0.75);



void updateDrive(){
        if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)==1){
                isFlipped = !isFlipped;
        }

        if(!isFlipped){
                chassis.opcontrol_arcade_standard(ez::SPLIT); // Standard split arcade
        }else{
                chassis.opcontrol_arcade_flipped(ez::SPLIT);
        }

        pros::delay(20);

}

