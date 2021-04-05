#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor BeltMotor = motor(PORT7, ratio36_1, true);
motor LeftMotor = motor(PORT8, ratio36_1, false);
motor RightMotor = motor(PORT10, ratio36_1, true);
motor HMotor = motor(PORT9, ratio36_1, true);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}