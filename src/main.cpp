#include "vex.h"
#include "robot-config.h"
#include <iostream>
#include "pid.h"
#include "autonomous.h"
#include"drivetrain.h"
double velocD;
// Namespaces
using namespace vex;

bool rollerDC;
bool flywheelDC;

void rollerIntake()
{
  RollerMotor.setVelocity(100, percent);
  RollerMotor.spin(forward);
}

void rollerStop()
{
  RollerMotor.stop();
}


void flywheel()
{
  while (true){
  velocD =  flywheelController.step(12000,FlywheelMotorGroup.voltage(voltageUnits::mV));
  FlywheelMotorGroup.setVelocity(velocD,voltageUnits::mV);    
  }
}

void pneumaticsOn(){
  Pneumatic.open();
}
void pneumaticsOff(){
  Pneumatic.close();

}

void flywheelStop()
{
  FlywheelMotorGroup.stop();
}
// Driver Controls
void drivercontrol()
{
  Controller1.ButtonA.pressed(rollerIntake);
  Controller1.ButtonB.pressed(rollerStop);
  Controller1.ButtonX.pressed(flywheel);
  Controller1.ButtonY.pressed(flywheelStop);
  Controller1.ButtonUp.pressed(pneumaticsOn);
  Controller1.ButtonDown.pressed(pneumaticsOff);
}
// Calls autonomous when buttonL1 is pressed ButtonL2 switches to driver control
int main()
{
  CDrivetrain.spin();
  Controller1.ButtonL1.pressed(autonomous);
  Controller1.ButtonL2.pressed(drivercontrol);

}
