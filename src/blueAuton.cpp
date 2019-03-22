#include "main.h"

void blueAuton(){
  driveStraight(3300, 100);//Hits flag.
  delay(3000);
  driveStraight(-1300, -100);//Backs up
  delay(1000);
  //Blue
  driveManual(-820, 820, -80, 80);//Turn left.
  delay(1000);
  driveStraight(3200, 100);//Drive straight.
  delay(3000);
  //Blue
  driveManual(800, -800, 80, -80);//Turn right.
  delay(1000);
  driveStraight(1700, 100);//Hitting flag 2.
  delay(1400);/*
  driveStraight(-1800, -100); //Back up
  delay(1500);
  //Blue
  driveManual(-800, 800, -80, 80);//Turn left.
  delay(1000);
  driveStraight(-900, -100);//Back up to middle.
  delay(1200);
  //Blue
  driveManual(-600, 600, -80, 80);//Turn left to platform
  delay(1000);

  //delay(10000);//Wait for bot 1.

  driveStraight(4500, 200);//Yeeeeet.
  delay(3500);*/
}
