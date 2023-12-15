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
  FlyPneum.set(true);
  FlyPneum.set(false);
}


// intake method, simply runs intake during autonomous
int intake()
{
  IntakeMotorGroup.setVelocity(100, percent);
  IntakeMotorGroup.spin(forward);
  return 0;
}
/*
void turnMethod(double turnDegrees, turnType test)
{
  int currentAngle = 0;
  Drivetrain.turnFor(90);
}
*/
void driveMethod(double driveAmount, double driveVelocity)
{
  double currentSpeed = Drivetrain.velocity(percentUnits::pct);
  double mvOut = driveVelocityController.step(95.0, currentSpeed);
  CDrivetrain.velocity(12000);
}
*/

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
void redRoller()
{
    /*
    RollerMotor.setVelocity(10, percent);

    roller_y =
        (Vision10.largestObject.originY - Vision10.largestObject.centerY) * 2;
    roller_x = Vision10.largestObject.originY - Vision10.largestObject.originX;
    roller_x = double(roller_x);
    IntakeMotor.spin(forward, roller_x, volt);
    RollerMotor.spinFor(forward, 1, sec);
    roller_x = 0;
    roller_y = 0;
    */

    IntakeMotorGroup.spinFor(forward,0.5,rev);
  
}

void blueRoller(){IntakeMotorGroup.spinFor(reverse,0.5,rev);}
/*
// Autonomous Code, runs drive commands and is selected by autonomous();
void blueLong()
{
  // Creates a new task, so that the intake can run at the same time as the main
  // task which runs rest of the methods.
  task t1(intake);

  Drivetrain.driveFor(2 * Tile,forward);
  // Drivetrain.turnFor(left,135,degrees);
  Drivetrain.turnFor(left,135);
  Drivetrain.driveFor(2 * Tile,forward);
  // Drivetrain.turnFor(left,45,degrees);
  Drivetrain.turnFor(left,45);
  Drivetrain.driveFor(50.8,forward);
  Drivetrain.driveFor(25.4,reverse);
  Roller();
  Flywheel();
  // stops task
  t1.stop();
}
// Blue Short side of field,with drive commands being changed
void blueShort()
{
  task t1(intake);
  Drivetrain.driveFor(2 * Tile, forward);
  // Drivetrain.turnFor(right,135,degrees);
  Drivetrain.turnFor(right,135);
  Drivetrain.driveFor(2 * Tile, forward);
  // Drivetrain.turnFor(right,45,degrees);
  Drivetrain.turnFor(right,45);
  Drivetrain.driveFor(50.8,forward);
  Drivetrain.driveFor(25.4,reverse);
  Roller();
  Flywheel();
  t1.stop();
}
// Red Long side of field,with drive commands being changed
void redLong()
{
  task t1(intake);
  Drivetrain.driveFor(2*Tile,forward);
  Drivetrain.turnFor(left,135);
  Drivetrain.driveFor(2*Tile,forward);
  Drivetrain.turnFor(left,45);
  Drivetrain.driveFor(2,forward);
  Drivetrain.driveFor(1,reverse);
  Roller();
  Flywheel();
  t1.stop();
}
// Red Short side of field,with drive commands being changed
void redShort()
{
  task t1(intake);
  Drivetrain.driveFor(2 * Tile, forward);
  // Drivetrain.turnFor(right,135,degrees);
  Drivetrain.turnFor(right,135);
  Drivetrain.driveFor(2 * Tile,forward);
  // Drivetrain.turnFor(right,45,degrees);
  Drivetrain.turnFor(right,45);
  Drivetrain.driveFor(2,forward);
  Drivetrain.driveFor(1,reverse);
  Roller();
  Flywheel();
  t1.stop();
}
*/

void redLongN(){
  task t1(intake);
  Drivetrain.driveFor(reverse,10,mm);
  redRoller();
  Drivetrain.driveFor(forward,10,mm);  
  Drivetrain.turnFor(right,225,degrees);
  Drivetrain.driveFor(forward,2*Tile,mm);
  Drivetrain.driveFor(reverse,0.45*Tile,mm);
  Drivetrain.turnFor(left,90,degrees);
  flyp();
  Drivetrain.turnFor(right,135,degrees);
  Drivetrain.driveFor(forward,0.25*Tile,mm);
  Drivetrain.turnFor(left,135,degrees);  
  Drivetrain.driveFor(forward,1*Tile,mm);
  t1.stop();


}
void redShortN(){
  task t1(intake);
  Drivetrain.driveFor(forward,2*Tile,mm);
  Drivetrain.turnFor(left,125,degrees);
  for(int i = 0; i++; i<3)flyp();
  Drivetrain.turnFor(right,180,degrees);
  Drivetrain.driveFor(forward,2.5*Tile,mm);
  Drivetrain.driveFor(forward,10,mm);
  redRoller();
  Drivetrain.driveFor(reverse,10,mm);
  t1.stop();
}
void blueLongN(){
  task t1(intake);
  Drivetrain.driveFor(reverse,10,mm);
  blueRoller();
  Drivetrain.driveFor(forward,10,mm);  
  Drivetrain.turnFor(right,225,degrees);
  Drivetrain.driveFor(forward,2*Tile,mm);
  Drivetrain.driveFor(reverse,0.45*Tile,mm);
  Drivetrain.turnFor(left,90,degrees);
  flyp();
  Drivetrain.turnFor(right,135,degrees);
  Drivetrain.driveFor(forward,0.25*Tile,mm);
  Drivetrain.turnFor(left,135,degrees);  
  Drivetrain.driveFor(forward,1*Tile,mm);
  t1.stop();
}
void blueShortN(){
  task t1(intake);
  Drivetrain.driveFor(forward,2*Tile,mm);
  Drivetrain.turnFor(left,125,degrees);
  flyp();
  Drivetrain.turnFor(right,180,degrees);
  Drivetrain.driveFor(forward,2.5*Tile,mm);
  Drivetrain.driveFor(forward,10,mm);
  blueRoller();
  Drivetrain.driveFor(reverse,10,mm);
  t1.stop();
}
void autonomous()
{
  if (redLon)
    redLongN();
  if (blueLon)
    blueLongN();
  if (redSon)
    redShortN();
  if (blueSon)
    blueShortN();
}