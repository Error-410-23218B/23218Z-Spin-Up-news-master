#include <iostream>
#include "vex.h"
#include "pid.h"

// Structure used to declare variables, at bottom multiple instances of the
// structure are declared, use same variable in "different" ways.

eftl::PIDController::PIDController(double ikP, double ikI, double ikD, double ikF)
{
  kP = pkP;
  kI = pkI;
  kD = pkD;
  kF = pkF;
};

double eftl::PIDController::step(double isetpoint, double process_variable)
{
while(Power != isetpoint){
  double error = isetpoint - process_variable;
  integral += error; 
  if (error == 0 || error > isetpoint)
    integral = 0;
  if (0 < error && error < 10000)
    integral = 0;
  derivative = error - prevError;
  prevError = error;
  Power = isetpoint * kF + error * kP + integral * kI + derivative * kD;
  return Power;
}
}

double eftl::PIDController::tune(){
  while(!Controller1.ButtonA.pressing()){
    this->pkP += 0.05;
    this->pkI += 0.05;
    this->pkD += 0.05;
    Brain.Screen.print(pkP);
    Brain.Screen.print(pkI);
    Brain.Screen.print(pkD);
  
  }

  

}

void eftl::PIDController::tune_test(){
  
}
