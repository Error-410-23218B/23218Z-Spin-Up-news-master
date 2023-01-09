#include "vex.h"
#include "pid.h"
#include "drivetrain.h"
#include "pid.h"
using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern controller Controller1;
extern signature Vision10__SIG_1;
extern signature Vision10__SIG_2;
extern signature Vision10__SIG_3;
extern signature Vision10__SIG_4;
extern signature Vision10__SIG_5;
extern signature Vision10__SIG_6;
extern signature Vision10__SIG_7;
extern vision Vision10;
extern drivetrain Drivetrain;
extern motor_group FlywheelMotorGroup;
extern motor IntakeMotor;
extern motor RollerMotor;
extern motor_group DrivetrainLeft;
extern motor_group DrivetrainRight;
extern eftl::customDrivetrain CDrivetrain;
extern pneumatics Pneumatic; 


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );