/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       0220182218                                                */
/*    Created:      Tue Mar 23 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftMotor            motor         1               
// RightMotor           motor         2               
// HDrive_motor         motor         11              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;


void Drive_xy(float delta_x,float delta_y,float power_setting, float timeout){
  // delta_x in cm
  // delta_y in cm
  // power_setting in percent
  // timeout in seconds (can be in integer if needed)

  //using the h drive, drive forward delta_x cm, right delta_y, at power setting power_setting %
  //cartitian coordinates format 
  //use functions motorname.spinfor and motor.setpower

  //the motors are red cartarage, just to let you know, but it shouldn't matter
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
}
