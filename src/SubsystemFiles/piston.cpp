#include "main.h"

bool ratchetDisengaged = false;

pros::ADIDigitalOut HangRatchetLeft('B');
pros::ADIDigitalOut HangRatchetRight('H');

void updatePistons(){
        
    /* Hang Sling Ratchet Controls */
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)){
      ratchetDisengaged = !ratchetDisengaged;
      HangRatchetLeft.set_value(ratchetDisengaged);
      HangRatchetRight.set_value(ratchetDisengaged);  

    }

    pros::delay(20);

}