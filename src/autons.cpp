#include "main.h"

/////
// For installation, upgrading, documentations and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 110;  
const int TURN_SPEED = 90;
const int SWING_SPEED = 90;

///
// Constants
///
void default_constants() {
  chassis.pid_heading_constants_set(6, 0, 9.5);
  chassis.pid_drive_constants_forward_set(7.3,0,18.25);
  chassis.pid_drive_constants_backward_set(7.4,0,22.75);
  chassis.pid_turn_constants_set(3, 0, 12.75);
  chassis.pid_swing_constants_set(3, 0, 17);

  chassis.pid_turn_exit_condition_set(300_ms, 3_deg, 500_ms, 7_deg, 750_ms, 750_ms);
  chassis.pid_swing_exit_condition_set(300_ms, 3_deg, 500_ms, 7_deg, 750_ms, 750_ms);
  chassis.pid_drive_exit_condition_set(300_ms, 1_in, 500_ms, 3_in, 750_ms, 750_ms);

  chassis.slew_drive_constants_set(7_in, 80);
}



// . . .
// Make your own autonomous functions here!
// . . .
void match(){

  chassis.drive_imu_reset();
  pros::delay(2000);

  chassis.pid_turn_set(45_deg,TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(36_in,DRIVE_SPEED,true);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg,TURN_SPEED);
  chassis.pid_wait();

  intakeSpinIn();

  chassis.pid_drive_set(36_in,DRIVE_SPEED,true);
  chassis.pid_wait();

  chassis.pid_drive_set(-18_in,DRIVE_SPEED,true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg,TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(30,DRIVE_SPEED,true);
  chassis.pid_wait();

  chassis.pid_turn_set(10_deg,TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-5_in,DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg,TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-70_in,DRIVE_SPEED,true);
  chassis.pid_wait();



}
void skills(){
  chassis.drive_imu_reset();

  chassis.pid_drive_set(-12_in,127);
  chassis.pid_wait();
  
  chassis.pid_drive_set(8_in,DRIVE_SPEED);
  chassis.pid_wait();
  
  chassis.pid_turn_set(45_deg,TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(18_in,DRIVE_SPEED,true);
  chassis.pid_wait();

  chassis.pid_turn_set(315,TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(8_in,DRIVE_SPEED);
  chassis.pid_wait();

  skillsCycle();


}

void skillsCycle(){

  intakeMoveDown();
  pros::delay(250);
  intakeMovementStop();

  intakeSpinIn();

  chassis.pid_drive_set(-10_in,DRIVE_SPEED);
  chassis.pid_wait();

  intakeSpinStop();

  chassis.pid_turn_set(45_deg,TURN_SPEED);
  chassis.pid_wait();

  intakeSpinOut();
  intakeMoveUp();
  pros::delay(500);
  intakeSpinStop();

  chassis.pid_turn_set(315,TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(10_in,DRIVE_SPEED);
  chassis.pid_wait();
  

}


// . . .
// Subsystem Methods
// . . .
void intakeMoveUp(){
  intakeLeft=-127;
  intakeRight=-127;
}

void intakeMoveDown(){
  intakeLeft=127;
  intakeRight=127;
}

void intakeMovementStop(){
  intakeLeft.brake();
  intakeRight.brake();
}

void intakeSpinIn(){
  intakeMotor = -127;
}

void intakeSpinOut(){
  intakeMotor = 127;
}

void intakeSpinStop(){
  intakeMotor.brake();
}

void hangUp(){
  hangMotor = 90;
}

void hangDown(){
  
}

void hangStop(){

}

void ratchetEngage(){
  ratchetMotor = -127;
}

void ratchetDisengage(){
  ratchetMotor = 127;
}

void ratchetStop(){
  ratchetMotor.brake();
}

// . . .
// Functions created to tune PID
// . . .
float valLeft = 0.0;
float valRight = 0.0;
float gyroVal = 0.0;

void tuneSwing(){

  chassis.pid_swing_set(ez::LEFT_SWING,90,SWING_SPEED);
  chassis.pid_wait();
  gyroVal = chassis.drive_imu_get();  

  

  printf("Degrees of turn: %lf\n",gyroVal);


  chassis.pid_swing_set(ez::LEFT_SWING,0,SWING_SPEED);
  chassis.pid_wait();
  gyroVal = chassis.drive_imu_get();  

  

  printf("Degrees of turn: %lf\n",gyroVal);

  

}

void tuneTurn(){

  chassis.pid_turn_set(90,TURN_SPEED);
  chassis.pid_wait();
  gyroVal = chassis.drive_imu_get();  

  

  printf("Degrees of turn: %lf\n",gyroVal);



  chassis.pid_turn_set(0,TURN_SPEED);
  chassis.pid_wait();

  gyroVal = chassis.drive_imu_get();  

  

  printf("Degrees of turn: %lf\n",gyroVal);

}

void tuneHeading(){


  chassis.pid_drive_set(24_in, DRIVE_SPEED,true);
  chassis.pid_wait();

  gyroVal = chassis.drive_imu_get();  

  

  printf("Degrees of turn: %lf\n",gyroVal);

  chassis.pid_drive_set(-24_in, DRIVE_SPEED);
  chassis.pid_wait();

  gyroVal = chassis.drive_imu_get();
  
  printf("Degrees of turn: %lf\n",gyroVal);



}


void tuneForwardBackward() { 
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches

  chassis.pid_drive_set(24_in, DRIVE_SPEED);
  chassis.pid_wait();
  // valLeft = chassis.drive_sensor_left()/  chassis.drive_tick_per_inch();
  // valRight = chassis.drive_sensor_right()/  chassis.drive_tick_per_inch();
    valLeft = chassis.drive_sensor_left();
  valRight = chassis.drive_sensor_right();

  

  printf("Distance Traveled: %lf\t%lf\n",valLeft,valRight);

  chassis.pid_drive_set(-24_in, DRIVE_SPEED);
  chassis.pid_wait();

  valLeft = chassis.drive_sensor_left();
  valRight = chassis.drive_sensor_right();
  
  printf("Distance Traveled: %lf\t%lf\n",valLeft,valRight);
  // chassis.pid_drive_set(-12_in, DRIVE_SPEED);
  // chassis.pid_wait();
}