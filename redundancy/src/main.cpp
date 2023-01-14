/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Rohan                                            */
/*    Created:      Fri Jan 13 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    19, 20, 17, 18  
// IntakeMotorGroup     motor_group   7, 9            
// FlywheelMotorGroup   motor_group   15, 16          
// FlyPneum             digital_out   A               
// ExtensionPneum       digital_out   B               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "pid.h"
#include "autonomous.h"
using namespace vex;
double flyt;
bool intakebutton = false;
bool rintakebutton = false;
 
int flywheelStep(){
  while(true){
   flyt = flywheelController.step(600,FlywheelMotorGroup.velocity(rpm));
   Brain.Screen.print(flyt);
  FlywheelMotorGroup.setVelocity(flyt,rpm);
             }
             return 0;
  
}

void flyPneum(){
FlyPneum.set(true);
wait(100,msec);
FlyPneum.set(false);
}

void extend(){
  ExtensionPneum.set(true);
  wait(100,msec);
  ExtensionPneum.set(false);

}

void intake(){
  IntakeMotorGroup.spin(forward);
}

void Reverseintake(){
  IntakeMotorGroup.spin(reverse);

}
void  flywheel(){
  FlywheelMotorGroup.spin(forward);

}



void flywheelStop(){
  FlywheelMotorGroup.stop();
}void drivercontrol(){
  Controller1.ButtonA.pressed(intake);
  Controller1.ButtonY.pressed(Reverseintake);
  Controller1.ButtonB.pressed(flyPneum);
  Controller1.ButtonX.pressed(extend);

  Controller1.ButtonL1.pressed(flywheel);
  Controller1.ButtonL2.pressed(flywheelStop);

}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Drivetrain.setDriveVelocity(100,percent);
  Drivetrain.setTurnVelocity(100,percent);
  IntakeMotorGroup.setMaxTorque(100,percent);
  IntakeMotorGroup.setVelocity(100,percent);


  task f2(flywheelStep);
  f2.resume();

  Controller1.ButtonR1.pressed(drivercontrol);
  Controller1.ButtonR2.pressed(autonomous);


}


