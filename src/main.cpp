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

  //the motors are red cartarage, and the degrees thing needs to take that into account

  //diameter of wheels are around 10cm
  float forward_turns = delta_y/((2*3.1415*5)); //devide target distance by diameter of wheel, then * cartage ratio
  Brain.Screen.print(forward_turns);
  LeftMotor.spinFor(forward,forward_turns,turns,false); //false = do not hold the programme here, so the other wheel will spin at the same time too
  RightMotor.spinFor(forward,forward_turns,turns,true); 

  //@Kee Ming can you please help implement the sideways motion too? It can happen at the same time. So the sideways motor spin should be true, and the right motor and left motor should be false. Thanks
  //Also the timeout and Power % if you have time. Thanks! 

}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Drive_xy(50,50,100,0);
  vex::task::sleep( 10000 );
  
}
