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
// BeltMotor            motor         7               
// LeftMotor            motor         8               
// RightMotor           motor         10              
// HMotor               motor         9               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

//global vars
// float current_robot_pos_x = 0;
// float current_robot_pos_y = 0;
// float current_target_pos_x = 0;
// float current_target_pos_y = 0;
// float delta_x = 0;
// float delta_y = 0;
// int default_speed_percentage = 25;

// void delta_location(float current_x,float current_y,float target_x,float target_y) {
//   //call it to update the delta values
//   delta_x = target_x - current_x;
//   delta_y = target_y - current_y;
// }

void Movebelt(float rotate, int power_setting=12) {
  BeltMotor.setVelocity(power_setting,percent);
  BeltMotor.setTimeout(20,seconds);
  BeltMotor.spinFor(forward,rotate,turns,true);
}

// void Drive_xy(float delta_x,float delta_y,float power_setting, float timeout) {
//   // delta_x in cm
//   // delta_y in cm
//   // power_setting in percent
//   // timeout in seconds (can be in integer if needed)

//   //using the h drive, drive forward delta_x cm, right delta_y, at power setting power_setting %
//   //cartitian coordinates format
//   //use functions motorname.spinfor and motor.setpower

//   //the motors are red cartarage, and the degrees thing needs to take that into account

//   //diameter of wheels are around 10cm


//   //set motor speed
//   LeftMotor.setVelocity(power_setting,percent);
//   RightMotor.setVelocity(power_setting,percent);

//   //set timeout
//   LeftMotor.setTimeout(timeout,seconds);
//   RightMotor.setTimeout(timeout,seconds);

//   //calc turns
//   float forward_turns = delta_y/((2*3.14159265358979323846*5)); //divide target distance by diameter of wheel, then * cartage ratio
//   // float sideway_turns = delta_x/((2*3.14159265358979323846*5)); //divide target distance by diameter of wheel, then * cartage ratio

//   //turn motors
//   LeftMotor.spinFor(forward,forward_turns,turns,false); //false = do not hold the programme here, so the other wheel will spin at the same time too
//   RightMotor.spinFor(forward,forward_turns,turns,true); //holds
//   //the reason why it is not ran as async is because it is quite wobbly and unstable to go both sideways and straight at the same time, and it is also not needed in this comp

// }

//Normal drive
void ydrive(float distance,int power_percentage = 25,int timeout=5) {

  //set motor speed
  LeftMotor.setVelocity(power_percentage,percent);
  RightMotor.setVelocity(power_percentage,percent);

  //set timeout
  LeftMotor.setTimeout(timeout,seconds);
  RightMotor.setTimeout(timeout,seconds);

  float forward_turns = distance/((2*3.14159265358979323846*5)); //divide target distance by diameter of wheel, then * cartage ratio
  //turn motors
  LeftMotor.spinFor(forward,forward_turns,turns,false); //false = do not hold the programme here, so the other wheel will spin at the same time too
  RightMotor.spinFor(forward,forward_turns,turns,true); //holds
    
}

// Hdrive/sideways
void xdrive(float distance) {

  //set motor speed and timeout
  HMotor.setVelocity(35,percent);
  HMotor.setTimeout(5,seconds);

  float sideways_turns = distance/((2*3.14159265358979323846*5)); //divide target distance by diameter of wheel, then * cartage ratio

  HMotor.spinFor(forward,sideways_turns,turns,true);
}

void pick_up_the_cube() {
  BeltMotor.setVelocity(20,percent);
  BeltMotor.setTimeout(5,seconds);
  BeltMotor.spinFor(forward,1,turns,true);
  // BeltMotor.spinFor(forward,1,turns,false);
  // ydrive(2.5);
  // wait(4, seconds);
  // ydrive(-2);
}

void push_h_area() {
  Movebelt(-3,20);
  ydrive(10,5,10);
  Movebelt(-2,100);
  ydrive(-10,15);
}

void throw_out(){
  Movebelt(-8,20);
}

void turn_one_side(int degrees, int power_percentage=25){

  //set motor speed
  LeftMotor.setVelocity(power_percentage,percent);
  RightMotor.setVelocity(power_percentage,percent);

  float calc_ed_turn = (26*3.1415*degrees/360)/(10*3.1415);
  RightMotor.spinFor(forward,calc_ed_turn,turns,false);
  LeftMotor.spinFor(forward,-calc_ed_turn,turns,true);
}
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  LeftMotor.setStopping(brake);
  RightMotor.setStopping(brake);
  HMotor.setStopping(brake);

  // Move out from base to h blocks
  xdrive(16.8);
  ydrive(51.9);
  RightMotor.spinFor(reverse,8,degrees);
  pick_up_the_cube();

  // Pick up other h blocks

  ydrive(-11.9);
  wait(5, msec);
  xdrive(38.8);
  wait(5, msec);
  RightMotor.spinFor(reverse,9,degrees);
  ydrive(10.7);
  wait(5, msec);
  pick_up_the_cube();

  ydrive(-13.5);
  wait(5, msec);
  xdrive(38.7);
  wait(5, msec);
  RightMotor.spinFor(reverse,10,degrees);
  ydrive(10.7);
  wait(5, msec);
  pick_up_the_cube();


  ydrive(-3.9);
  turn_one_side(-64);
  ydrive(22.2);
  pick_up_the_cube();
  ydrive(-22.2);
  turn_one_side(64);



  // release h cubes to the end

  ydrive(-30);
  turn_one_side(180);
  throw_out();
  ydrive(-10);
  turn_one_side(177);
  

  // s blocks

  xdrive(27);
  ydrive(22);

  pick_up_the_cube();

  ydrive(-10);

  xdrive(-39.2);
  wait(5, msec);
  RightMotor.spinFor(reverse,6,degrees);
  ydrive(11);
  pick_up_the_cube();
  ydrive(-11);

  xdrive(-39.2);
  wait(5, msec);
  RightMotor.spinFor(reverse,7,degrees);
  ydrive(11);
  pick_up_the_cube();
  ydrive(-11);

  xdrive(-39.2);
  wait(5, msec);
  RightMotor.spinFor(reverse,8,degrees);
  ydrive(11);
  pick_up_the_cube();


  // release cubes

  xdrive(20);
  ydrive(10);
  throw_out();
  xdrive(-30);
  ydrive(-60);





  //push_h_area();
  //throw_out();
  // turn_one_side(90,20);
  // // xdrive(20);
  // ydrive(30);
  // // xdrive(-20);
  // // ydrive(-20);

  // Movebelt(0.6);

  // ydrive(-10);
  // xdrive(27);
  // ydrive(10);

  // Movebelt(5);





  //Drivetrain.setTimeout(5,seconds);
  // Drivetrain.setDriveVelocity(20,percent);
  // Drivetrain.setStopping(hold);
  // Drivetrain.setTurnVelocity(20,percent);


  // // Drivetrain.driveFor(forward,500,mm);
  // Drivetrain.turnFor(left,360,degrees);

  // Drivetrain.driveFor(forward,1000,mm);

  



  //LeftMotor.spinFor(forward,1000,degrees,false);
  //RightMotor.spinFor(forward,1000,degrees,false);

  // Normal_drive(150,5);


  //Drive_xy(0,50,25,0);

  //LeftMotor.spinFor(forward,1,turns,false);
  //RightMotor.spinFor(forward,1,turns,false);
  // while (true){

  //   //Drive_xy(50,0,25,1);
  //   //Drive_xy(-50,0,25,1);
  //   Drive_xy(0,-50,25,10);
  //   vex::task::sleep( 1000 );
  //   Drive_xy(0,50,25,10);
  //   //Drive_xy(50,50,25,0);
  //   /*int counter = 0;
  //   while (counter < 4) {
  //     // Test L shape
  //     // Drive_xy(50,0,25,1);
  //     // Drive_xy(-50,0,25,1);
  //     // Drive_xy(0,-50,25,1);
  //     // Drive_xy(0,50,25,1);
  //     // Movebelt(100,50,1);
  //     // Movebelt(-100,50,1);

  //     Drive_xy(50,50,50,1);
  //     Drive_xy(50,0,50,1);
  //     Movebelt(100,50,1);
  //     Drive_xy(50,0,50,1);
  //     Movebelt(-100,50,1);
  //     Drive_xy(-100,50,50,1);

  //     counter++;*/

  // }

  //vex::task::sleep( 10000 );

}
