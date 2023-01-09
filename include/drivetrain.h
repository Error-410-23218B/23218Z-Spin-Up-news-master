#pragma once
#ifndef drivetrain_h
#define drivetrain_h
#include "vex.h"
namespace eftl{
class customDrivetrain{
    public:
       static double Velocity;
       static double VelocL;
       static double VelocR;
       const double deg_mm = 1.0;
       
    
    customDrivetrain::customDrivetrain(vex::motor_group &l, vex::motor_group &r, double wheelTravel=320,double trackWidth=320, double wheelBase=130,vex::distanceUnits unit=vex::distanceUnits::mm,double externalGearRatio=1.0);
    static double slew(double input);
    void spin();
    void  velocity(double veloc);
    static int velocTR();
    void stop();
    void turnFor(turnType turnvar,double turnAmount);
    void spinFor(double spinPos,directionType direction);
     
};



}
#endif