#include "main.h"

bool running = false;

void redAuton(){
  driveStraight(3300, 80);//Hits flag.
  delay(3500);
  driveStraight(-1700, -80);//Backs up
  delay(1500);
  //Red
  driveManual(800, -800, 80, -80);//Turn right.
  delay(1000);
  driveStraight(3000, 100);//Drive straight.
  delay(3000);
  //Red
  driveManual(-800, 800, -80, 80);//Turn right.
  delay(1000);
  driveStraight(1700, 100);//Hitting flag 2.
  delay(1400);
  driveStraight(-1800, -100); //Back up
  delay(1500);
  //Red
  driveManual(800, -800, 80, -80);//Turn left.
  delay(1000);
  driveStraight(-900, -100);//Back up to middle.
  delay(1200);
  //Red
  driveManual(600, -600, 80, -80);//Turn left to platform
  delay(1000);

  //delay(10000);//Wait for bot 1.

  driveStraight(4500, 200);//Yeeeeet.
  delay(3500);
}
