#include <iostream>
#include "math.h"
#include "pid.h"
#include "autonomous.h"
#include "drivetrain.h"
#include "vex.h"
#include "robot-config.h"


using namespace vex;


void flyt(){flywheelt.tune();}
void drive(){drivet.tune();}
void drivePos(){drivePost.tune();}
void turn(){turnt.tune();}





void PIDtuner(){
    Controller1.ButtonL1.pressed(flyt);
    Controller1.ButtonL2.pressed(drive);
    Controller1.ButtonR1.pressed(drivePos);
    Controller1.ButtonR2.pressed(turn);
}