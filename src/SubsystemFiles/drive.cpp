#include "main.h"

bool isFlipped = false;

// Chassis constructor
Drive chassis (
        
  // Left Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  {7,20} // ports for left motors

  // Right Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  ,{-6,-18} // ports for right motors

  // IMU Port
  ,21

  // Wheel Diameter (Remember, 4" wheels are actually 4.125!)
  //    (or tracking wheel diameter)
  ,2.75

  // Cartridge RPM
  //   (or tick per rotation if using tracking wheels)
  ,600

  // External Gear Ratio (MUST BE DECIMAL)
  //    (or gear ratio of tracking wheel)
  // eg. if your drive is 84:36 where the 36t is powered, your RATIO would be 2.333.
  // eg. if your drive is 36:60 where the 60t is powered, your RATIO would be 0.6.
  ,1

);


void updateDrive(){
        if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)==1){
                isFlipped = !isFlipped;
        }

        if(!isFlipped){
                chassis.arcade_standard(ez::SPLIT); // Standard split arcade
        }else{
                chassis.arcade_flipped(ez::SPLIT); // Flipped split arcade
        }
}