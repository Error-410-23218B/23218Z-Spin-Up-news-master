#pragma once
#ifndef pid_h
#define pid_h

#include "robot-config.h"
#include "vex.h"
// Declared Methods in global scope and allows them to be used in other .cpp files, related to PID code;
namespace eftl{
typedef unsigned char TYPE;

class PIDController
{
public:
    double prevError;
    double integral;
    double derivative;
    double Power;
    double Setpoint;

    double kP;
    double kI;
    double kD;
    double kF;

    double pkP;
    double pkI;
    double pkD;
    double pkF;
    PIDController::PIDController(double ikP, double ikI, double ikD, double ikF);

    double step(double setpoint, double process_variable);
    double tune();
    void tune_test();
//  double slewRate(double slewSetpoint,TYPE type);
};
}


extern eftl::PIDController flywheelController(200.0, 0.0, 0.0, 120.0);
extern eftl::PIDController driveVelocityController(0.0, 0.0, 0.0, 0.0);
extern eftl::PIDController drivePosController(0.0, 0.0, 0.0, 0.0);
extern eftl::PIDController turnController(0.0, 0.0, 0.0, 0.0);

extern eftl::PIDController flywheelt(200.0, 0.0, 0.0, 120.0);
extern  eftl::PIDController drivet(0.0, 0.0, 0.0, 0.0);
extern eftl::PIDController drivePost(0.0, 0.0, 0.0, 0.0);
extern  eftl::PIDController turnt  (0.0, 0.0, 0.0, 0.0);

#endif pid_h