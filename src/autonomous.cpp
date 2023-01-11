#include "autonomous.h"
#include "math.h"
#include "pid.h"
#include "vex.h"


// Tile variable is the amount of inches in one tile
const double Tile = 12.0;
// Roller positions
double roller_y;
double roller_x;
// Variables used for autonomous selection
bool redLon;
bool redSon;
bool blueLon;
bool blueSon;
const double inches = 25.4;
// autonomous function,when run it runs the selected autonomous that was
// selected when GUI(); is ran

// These 4 methods are called from GUI.cpp used for setting variables to select
// autonomous.
void redLSelect() { redLon = true; }
void redSSelect() { redSon = true; }
void blueLSelect() { blueLon = true; }
void blueSSelect() { blueSon = true; }




void flyp(){
  flyPneum.open();
  flyPneum.close();
}

void autonomous()
{
  if (redLon)
    redLong();
  if (blueLon)
    blueLong();
  if (redSon)
    redShort();
  if (blueSon)
    blueShort();
}
// intake method, simply runs intake during autonomous
int intake()
{
  IntakeMotor.setVelocity(100, percent);
  IntakeMotor.spin(forward);
  return 0;
}
/*
void turnMethod(double turnDegrees, turnType test)
{
  int currentAngle = 0;
  CDrivetrain.turnFor(90);
}
*/
void driveMethod(double driveAmount, double driveVelocity)
{
  double currentSpeed = Drivetrain.velocity(percentUnits::pct);
  double mvOut = driveVelocityController.step(95.0, currentSpeed);
  CDrivetrain.velocity(12000);
}

// Flywheel method, flyPID from final_pid.cpp is run, flyPID is called here, and
// returns the value for RPM;
void Flywheel()
{
  for (int i = 0; i < 334; i++)
  {
    double currentSpeed = FlywheelMotorGroup.velocity(percentUnits::pct);
    double mvOut = flywheelController.step(95.0, currentSpeed);
    FlywheelMotorGroup.spin(directionType::fwd, mvOut, voltageUnits::mV);
  }
}

// Roller Method, takes
void Roller()
{
  RollerMotor.setVelocity(10, percent);

  roller_y =
      (Vision10.largestObject.originY - Vision10.largestObject.centerY) * 2;
  roller_x = Vision10.largestObject.originY - Vision10.largestObject.originX;
  roller_x = double(roller_x);
  IntakeMotor.spin(forward, roller_x, volt);
  RollerMotor.spinFor(forward, 1, sec);
  roller_x = 0;
  roller_y = 0;
}

// Autonomous Code, runs drive commands and is selected by autonomous();
void blueLong()
{
  // Creates a new task, so that the intake can run at the same time as the main
  // task which runs rest of the methods.
  task t1(intake);

  CDrivetrain.spinFor(2 * Tile,forward);
  // Drivetrain.turnFor(left,135,degrees);
  CDrivetrain.turnFor(left,135);
  CDrivetrain.spinFor(2 * Tile,forward);
  // Drivetrain.turnFor(left,45,degrees);
  CDrivetrain.turnFor(left,45);
  CDrivetrain.spinFor(50.8,forward);
  CDrivetrain.spinFor(25.4,reverse);
  Roller();
  Flywheel();
  // stops task
  t1.stop();
}
// Blue Short side of field,with drive commands being changed
void blueShort()
{
  task t1(intake);
  CDrivetrain.spinFor(2 * Tile, forward);
  // Drivetrain.turnFor(right,135,degrees);
  CDrivetrain.turnFor(right,135);
  CDrivetrain.spinFor(2 * Tile, forward);
  // Drivetrain.turnFor(right,45,degrees);
  CDrivetrain.turnFor(right,45);
  CDrivetrain.spinFor(50.8,forward);
  CDrivetrain.spinFor(25.4,reverse);
  Roller();
  Flywheel();
  t1.stop();
}
// Red Long side of field,with drive commands being changed
void redLong()
{
  task t1(intake);
  CDrivetrain.spinFor(2*Tile,forward);
  CDrivetrain.turnFor(left,135);
  CDrivetrain.spinFor(2*Tile,forward);
  CDrivetrain.turnFor(left,45);
  CDrivetrain.spinFor(2,forward);
  CDrivetrain.spinFor(1,reverse);
  Roller();
  Flywheel();
  t1.stop();
}
// Red Short side of field,with drive commands being changed
void redShort()
{
  task t1(intake);
  CDrivetrain.spinFor(2 * Tile, forward);
  // Drivetrain.turnFor(right,135,degrees);
  CDrivetrain.turnFor(right,135);
  CDrivetrain.spinFor(2 * Tile,forward);
  // Drivetrain.turnFor(right,45,degrees);
  CDrivetrain.turnFor(right,45);
  CDrivetrain.spinFor(2,forward);
  CDrivetrain.spinFor(1,reverse);
  Roller();
  Flywheel();
  t1.stop();
}

void redLongN(){
  task intake(intake);
  CDrivetrain.spinFor(10,reverse);
  Roller();
  CDrivetrain.spinFor(10,forward);  
  CDrivetrain.turnFor(right,225);
  CDrivetrain.spinFor(2*Tile,forward);
  CDrivetrain.spinFor(0.45*Tile,reverse);
  CDrivetrain.turnFor(left,90);
  flyp();
  CDrivetrain.turnFor(right,135);
  CDrivetrain.spinFor(0.25*Tile,forward);
  CDrivetrain.turnFor(left,135);  
  CDrivetrain.spinFor(1*Tile,forward);
  


}
void redShortN(){
  task t1(intake);
  CDrivetrain.spinFor(2*Tile,forward);
  CDrivetrain.turnFor(left,125);
  flyp();
  CDrivetrain.turnFor(right,180);
  CDrivetrain.spinFor(2.5*Tile,forward);
  CDrivetrain.spinFor(10,forward);
  Roller();
  CDrivetrain.spinFor(10,reverse);
}
void blueLongN(){
  task intake(intake);
  CDrivetrain.spinFor(10,reverse);
  Roller();
  CDrivetrain.spinFor(10,forward);  
  CDrivetrain.turnFor(right,225);
  CDrivetrain.spinFor(2*Tile,forward);
  CDrivetrain.spinFor(0.45*Tile,reverse);
  CDrivetrain.turnFor(left,90);
  flyp();
  CDrivetrain.turnFor(right,135);
  CDrivetrain.spinFor(0.25*Tile,forward);
  CDrivetrain.turnFor(left,135);  
  CDrivetrain.spinFor(1*Tile,forward);
}
void blueShortN(){
  task t1(intake);
  CDrivetrain.spinFor(2*Tile,forward);
  CDrivetrain.turnFor(left,125);
  flyp();
  CDrivetrain.turnFor(right,180);
  CDrivetrain.spinFor(2.5*Tile,forward);
  CDrivetrain.spinFor(10,forward);
  Roller();
  CDrivetrain.spinFor(10,reverse);

}