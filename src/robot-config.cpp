#include "vex.h"
#include "drivetrain.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
 brain Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
/*vex-vision-config:begin*/
vision Vision10 = vision (PORT10, 50);
/*vex-vision-config:end*/
motor leftMotorA = motor(PORT11, ratio18_1, false);
motor leftMotorB = motor(PORT12, ratio18_1, false);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);
motor rightMotorA = motor(PORT15, ratio18_1, true);
motor rightMotorB = motor(PORT16, ratio18_1, true);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1);
motor FlywheelMotorGroupMotorA = motor(PORT13, ratio6_1, false);
motor FlywheelMotorGroupMotorB = motor(PORT14, ratio6_1, false);
motor_group FlywheelMotorGroup = motor_group(FlywheelMotorGroupMotorA, FlywheelMotorGroupMotorB);
motor IntakeMotor = motor(PORT17, ratio18_1, false);
motor RollerMotor = motor(PORT9, ratio18_1, false);
motor DrivetrainLeftA = motor(PORT11,ratio18_1,false);
motor DrivetrainLeftB = motor(PORT12,ratio18_1,false);
motor DrivetrainRightA = motor(PORT15,ratio18_1,true);
motor DrivetrainRightB = motor(PORT16,ratio18_1,true);
motor_group DrivetrainLeft = motor_group(DrivetrainLeftA,DrivetrainLeftB);
motor_group DrivetrainRight = motor_group(DrivetrainRightA,DrivetrainRightB);
eftl::customDrivetrain CDrivetrain= eftl::customDrivetrain(DrivetrainLeft,DrivetrainRight);
pneumatics Pneumatic = pneumatics(Brain.ThreeWirePort.A);  
// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}