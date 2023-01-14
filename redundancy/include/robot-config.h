using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern drivetrain Drivetrain;
extern motor_group IntakeMotorGroup;
extern motor_group FlywheelMotorGroup;
extern digital_out FlyPneum;
extern digital_out ExtensionPneum;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );