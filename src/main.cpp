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

//global vars
float current_robot_pos_x = 0;
float current_robot_pos_y = 0;
float current_target_pos_x = 0;
float current_target_pos_y = 0;
float delta_x = 0;
float delta_y = 0;
int default_speed_percentage = 25;

void delta_location(float current_x,float current_y,float target_x,float target_y){
  //call it to update the delta values
  delta_x = target_x - current_x;
  delta_y = target_y - current_y;
}


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


  //set motor speed
  LeftMotor.setVelocity(power_setting,percent);
  LeftMotor.setTimeout(timeout,seconds);
  RightMotor.setVelocity(power_setting,percent);
  RightMotor.setTimeout(timeout,seconds);
  HDrive_motor.setVelocity(power_setting,percent);
  HDrive_motor.setTimeout(timeout,seconds);

  //calc turns
  float forward_turns = delta_y/((2*3.1415*5)); //devide target distance by diameter of wheel, then * cartage ratio
  float sideway_turns = delta_x/((2*3.1415*5)); //devide target distance by diameter of wheel, then * cartage ratio

  //turn motors
  LeftMotor.spinFor(forward,forward_turns,turns,false); //false = do not hold the programme here, so the other wheel will spin at the same time too
  RightMotor.spinFor(forward,forward_turns,turns,true); //holds
  //the reason why it is not ran as async is because it is quite wobbly and unstable to go both sideways and straight at the same time, and it is also not needed in this comp
  HDrive_motor.spinFor(forward,sideway_turns,turns,true); //holds programme here

}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  //Drive_xy(50,50,25,0);
  while (true){
    
    Drive_xy(50,0,25,1);
    Drive_xy(-50,0,25,1);
    Drive_xy(0,-50,25,1);
    Drive_xy(0,50,25,1);
    
  }

  //vex::task::sleep( 10000 );
  
}
