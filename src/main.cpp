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
// HDriveMotor          motor         11
// ArmMotor             motor         3
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

void delta_location(float current_x,float current_y,float target_x,float target_y) {
  //call it to update the delta values
  delta_x = target_x - current_x;
  delta_y = target_y - current_y;
}

void Movebelt(float rotate, float power_setting, float timeout) {
  ArmMotor.setVelocity(power_setting,percent);
  ArmMotor.setTimeout(timeout,seconds);
  ArmMotor.spinFor(forward,rotate,turns,true);

}

void Drive_xy(float delta_x,float delta_y,float power_setting, float timeout) {
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
  RightMotor.setVelocity(power_setting,percent);
  HDriveMotor.setVelocity(power_setting,percent);

  //set timeout
  LeftMotor.setTimeout(timeout,seconds);
  RightMotor.setTimeout(timeout,seconds);
  HDriveMotor.setTimeout(timeout,seconds);

  //calc turns
  float forward_turns = delta_y/((2*3.14159265358979323846*5)); //divide target distance by diameter of wheel, then * cartage ratio
  float sideway_turns = delta_x/((2*3.14159265358979323846*5)); //divide target distance by diameter of wheel, then * cartage ratio

  //turn motors
  LeftMotor.spinFor(forward,forward_turns,turns,false); //false = do not hold the programme here, so the other wheel will spin at the same time too
  RightMotor.spinFor(forward,forward_turns,turns,true); //holds
  //the reason why it is not ran as async is because it is quite wobbly and unstable to go both sideways and straight at the same time, and it is also not needed in this comp
  HDriveMotor.spinFor(forward,sideway_turns,turns,true); //holds programme here

}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  //Drive_xy(0,50,25,0);

  //LeftMotor.spinFor(forward,1,turns,false);
  //RightMotor.spinFor(forward,1,turns,false);
  while (true){

    //Drive_xy(50,0,25,1);
    //Drive_xy(-50,0,25,1);
    Drive_xy(0,-50,25,10);
    vex::task::sleep( 1000 );
    Drive_xy(0,50,25,10);
    //Drive_xy(50,50,25,0);
    /*int counter = 0;
    while (counter < 4) {
      // Test L shape
      // Drive_xy(50,0,25,1);
      // Drive_xy(-50,0,25,1);
      // Drive_xy(0,-50,25,1);
      // Drive_xy(0,50,25,1);
      // Movebelt(100,50,1);
      // Movebelt(-100,50,1);

      Drive_xy(50,50,50,1);
      Drive_xy(50,0,50,1);
      Movebelt(100,50,1);
      Drive_xy(50,0,50,1);
      Movebelt(-100,50,1);
      Drive_xy(-100,50,50,1);

      counter++;*/

  }

  //vex::task::sleep( 10000 );

}
