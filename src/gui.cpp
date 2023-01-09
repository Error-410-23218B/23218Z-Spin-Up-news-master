/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\jaymi                                            */
/*    Created:      Fri Nov 04 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "robot-config.h"
#include "autonomous.h"

using namespace vex;

int screenX;
int screenY;
bool tf;

/*Screen Selections, sees where button is pressed && if so, it calls redLSelect && clears screen && prints to affirm selection,
repeated just with different values, runs after one of the coloured halves has been selected */
void SelectAUTON()
{
  if ((Brain.Screen.xPosition() >= 120) && (Brain.Screen.xPosition() <= 160) && (Brain.Screen.yPosition() >= 0) && (Brain.Screen.yPosition() <= 40))
  {
    Brain.Screen.clearScreen();
    Brain.Screen.print("Red long");
    redLSelect();
  }
  if ((Brain.Screen.xPosition() >= 240) && (Brain.Screen.xPosition() <= 280) && (Brain.Screen.yPosition() >= 200) && (Brain.Screen.yPosition() <= 240))
  {
    Brain.Screen.clearScreen();
    Brain.Screen.print("Red short");
    redSSelect();
  }
  if ((Brain.Screen.xPosition() >= 200) && (Brain.Screen.xPosition() <= 240) && (Brain.Screen.yPosition() >= 0) && (Brain.Screen.yPosition() <= 40))
  {
    Brain.Screen.clearScreen();
    Brain.Screen.print("Blue short");
    blueSSelect();
  }
  if ((Brain.Screen.xPosition() >= 320) && (Brain.Screen.xPosition() <= 360) && (Brain.Screen.yPosition() >= 200) && (Brain.Screen.yPosition() <= 240))
  {
    Brain.Screen.print("Blue long");
    blueLSelect();
  }
}

void RedSelect()
{ // When the red half on GUI pressed runs after MainMenuPress(); is loaded.
  Brain.Screen.clearScreen();
  Brain.Screen.setFont(monoS);
  Brain.Screen.setFillColor(yellow);
  Brain.Screen.drawRectangle(120, 160, 80, 80);
  Brain.Screen.drawRectangle(280, 0, 80, 80);
  Brain.Screen.setFillColor(white);
  Brain.Screen.drawLine(120, 0, 120, 240);
  Brain.Screen.drawLine(160, 0, 160, 240);
  Brain.Screen.drawLine(200, 0, 200, 240);
  Brain.Screen.drawLine(240, 0, 240, 240);
  Brain.Screen.drawLine(280, 0, 280, 240);
  Brain.Screen.drawLine(320, 0, 320, 240);
  Brain.Screen.drawLine(360, 0, 360, 240);
  Brain.Screen.drawLine(120, 0, 360, 0);
  Brain.Screen.drawLine(120, 40, 360, 40);
  Brain.Screen.drawLine(120, 80, 360, 80);
  Brain.Screen.drawLine(120, 120, 360, 120);
  Brain.Screen.drawLine(120, 160, 360, 160);
  Brain.Screen.drawLine(120, 200, 360, 200);
  Brain.Screen.drawLine(120, 240, 360, 240);
  Brain.Screen.setFillColor(red);
  Brain.Screen.drawRectangle(120, 40, 40, 40);
  Brain.Screen.drawRectangle(240, 200, 40, 40);
  Brain.Screen.pressed(SelectAUTON);
}

// When the blue half of GUI pressed
void BlueSelect()
{
  Brain.Screen.clearScreen();
  Brain.Screen.setFont(monoS);
  Brain.Screen.setFillColor(yellow);
  Brain.Screen.drawRectangle(120, 160, 80, 80);
  Brain.Screen.drawRectangle(280, 0, 80, 80);
  Brain.Screen.setFillColor(white);
  Brain.Screen.drawLine(120, 0, 120, 240);
  Brain.Screen.drawLine(160, 0, 160, 240);
  Brain.Screen.drawLine(200, 0, 200, 240);
  Brain.Screen.drawLine(240, 0, 240, 240);
  Brain.Screen.drawLine(280, 0, 280, 240);
  Brain.Screen.drawLine(320, 0, 320, 240);
  Brain.Screen.drawLine(360, 0, 360, 240);
  Brain.Screen.drawLine(120, 0, 360, 0);
  Brain.Screen.drawLine(120, 40, 360, 40);
  Brain.Screen.drawLine(120, 80, 360, 80);
  Brain.Screen.drawLine(120, 120, 360, 120);
  Brain.Screen.drawLine(120, 160, 360, 160);
  Brain.Screen.drawLine(120, 200, 360, 200);
  Brain.Screen.drawLine(120, 240, 360, 240);
  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle(200, 0, 40, 40);
  Brain.Screen.drawRectangle(320, 200, 40, 40);
  Brain.Screen.pressed(SelectAUTON);
}

// GUI selection of red && blue made sure to only be pressed once && act as a gate for Red/Blue selection, runs BlueSelect(); or RedSelect();
void MainMenuPress()
{
  screenX = Brain.Screen.xPosition();
  screenY = Brain.Screen.yPosition();
  if (tf == true)
  {
    if (screenX >= 240)
    {
      BlueSelect();
      screenX = 0;
    }
    else if (screenX < 240)
    {
      RedSelect();
      screenX = 0;
    }
    tf = false;
  }
}

// Runs MainMenuPress(); loads the 2 coloured halves.

void MainMenu()
{ //
  Brain.Screen.clearScreen();
  Brain.Screen.print(Brain.Battery.capacity());
  Brain.Screen.print("% Left in Battery.");
  Brain.Screen.setFillColor(red);
  Brain.Screen.drawRectangle(0, 0, 240, 240);
  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle(240, 0, 240, 240);
  Brain.Screen.pressed(MainMenuPress);
}
// Loads MainMenu();, displays Loading
void GUI()
{
  Brain.Screen.setFillColor(black);
  Brain.Screen.setFont(propXL);
  Brain.Screen.print("Loading");
  wait(0.1, seconds);
  Brain.Screen.clearLine();
  Brain.Screen.print("Loading.");
  wait(0.1, seconds);
  Brain.Screen.clearLine();
  Brain.Screen.print("Loading..");
  wait(0.1, seconds);
  Brain.Screen.clearLine();
  Brain.Screen.print("Loading...");
  wait(0.5, seconds);
  Brain.Screen.clearLine();
  Brain.Screen.print("Complete!");
  wait(1, seconds);
  tf = true;
  MainMenu();
}