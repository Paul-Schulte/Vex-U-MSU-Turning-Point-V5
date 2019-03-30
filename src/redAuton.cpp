#include "redAuton.hpp"

using namespace okapi;
#define moveDelay delay(100)

void redAuton(){
  chassis.setMaxVelocity(100);
  intake.move(90);//Starts intake.
  chassis.moveDistance(2.9_ft);//Moves up to cap on ball and collects it.
  moveDelay;
  intake.move(0);//Stops intake.
  chassis.moveDistance(-3.9_ft);//Moves back to start and aligns with wall.
  moveDelay;
  chassis.moveDistance(0.4_ft);//Moves to center of tile.
  moveDelay;
  chassis.turnAngle(-90_deg);//Turns left to flag.
  moveDelay;
  chassis.moveDistance(1_ft);//Moves to high flag firing position.
  moveDelay;
  launcherShoot();//Shoots first ball.
  delay(700);
  intake.move(90);//Pulls second ball into launcher.
  chassis.moveDistance(1.5_ft);//Moves to middle flag position.
  moveDelay;
  delay(200);
  intake.move(0);//Stops intake.
  launcherShoot();//Shoots second ball.
  delay(700);
  chassis.moveDistance(2_ft);//Scores low flag and aligns on wall.
  moveDelay;
  chassis.moveDistance(-1.5_ft);//Moves back.
  moveDelay;
  chassis.turnAngle(90_deg);//Turns right toward center flags.
  moveDelay;
  chassis.moveDistance(3.8_ft);//Moves in front of middle flags.
  moveDelay;
  chassis.turnAngle(-90_deg);//Turns left to lower flag.
  moveDelay;
  chassis.moveDistance(1.5_ft);//Scores low flag and aligns on wall.
  moveDelay;
  chassis.moveDistance(-2.25_ft);//Backs up.
  moveDelay;
  flipper.move_absolute(-590, 100);//Lowers flipper.
  delay(1000);
  chassis.turnAngle(-90_deg);//Turns left to cap.
  moveDelay;
  chassis.moveDistance(1.2_ft);//Moves up to cap.
  moveDelay;
  flipper.move_absolute(-20, 100);//Flips cap.
  delay(1000);
  chassis.turnAngle(-90_deg);//Turns left to platform.
  moveDelay;
  chassis.setMaxVelocity(150);
  chassis.moveDistance(5_ft);//Yeeeeeeeets onto platform.





  /*
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
  */
}
