#include "blueAuton.hpp"

using namespace okapi;
#define moveDelay delay(100)

void blueAuton(){
  autonIntake = true;//Starts intake.
  chassis.setMaxVelocity(200);
  chassis.moveDistance(4.1_ft);//Moves up to cap on ball and collects it.
  moveDelay;
  chassis.setMaxVelocity(120);
  chassis.moveDistance(-4.25_ft);//Moves back and aligns with wall
  autonIntake = false;//Stops intake.
  moveDelay;
  chassis.setMaxVelocity(100);
  chassis.moveDistance(.9_ft);//Moves up to edge of tile.
  moveDelay;
  chassis.setMaxVelocity(60);
  chassis.turnAngle(93_deg);//Turns left to align with flags.
  moveDelay;
  chassis.moveDistance(1_ft);//Moves up to position.
  flipper.move_absolute(150, 100);//Moves flipper out of the way.
  moveDelay;
  launcherMove(880);//Sets launcher to first near position.
  delay(500);
  launcherShoot();//Shoots first ball.
  autonIntake = true;
  delay(800);
  launcherMove(220);//Sets launcher to second near position.
  delay(700);
  launcherShoot();//Shoots second ball.
  autonIntake = false;
  delay(700);

  chassis.turnAngle(93_deg);
  moveDelay;
  chassis.moveDistance(.7_ft);
  moveDelay;
  chassis.turnAngle(-93_deg);
  moveDelay;
  chassis.moveDistance(3.6_ft);
  moveDelay;
  chassis.setMaxVelocity(120);
  chassis.moveDistance(-6.3_ft);
  moveDelay;
  chassis.setMaxVelocity(60);
  chassis.turnAngle(93_deg);
  moveDelay;
  chassis.setMaxVelocity(150);
  chassis.moveDistance(4_ft);
/*
  chassis.turnAngle(-145_deg);//Turns to corner of platform.
  moveDelay;
  autonIntake = true;//Starts intake.
  intakeToggle(true);//Moves intake up.
  chassis.setMaxVelocity(150);
  chassis.moveDistance(2.7_ft);//Moves up to corner and collects ball.
  moveDelay;
  intakeToggle(false);
  chassis.setMaxVelocity(120);
  chassis.moveDistance(-2.7_ft);//Backs up.
  moveDelay;
  chassis.setMaxVelocity(60);
  chassis.turnAngle(-35_deg);//Turns parallel to wall.
  autonIntake = false;
  moveDelay;
  chassis.setMaxVelocity(150);
  chassis.moveDistance(5.5_ft);//Moves forward to position for second ball on platform.
  moveDelay;
  chassis.setMaxVelocity(60);
  chassis.turnAngle(140_deg);//Turns to corner of platform.
  autonIntake = true;//Starts intake.
  intakeToggle(true);//Moves intake up.
  moveDelay;
  chassis.setMaxVelocity(125);
  chassis.moveDistance(2.2_ft);//Moves up to corner and collects second ball.
  moveDelay;
  intakeToggle(false);
  chassis.moveDistance(-1_ft);//Backs up.
  moveDelay;
  chassis.setMaxVelocity(60);
  chassis.turnAngle(-60_deg);//Turns perpendicular to side wall.
  moveDelay;
  chassis.setMaxVelocity(120);
  chassis.moveDistance(-2_ft);//Backs up and aligns against wall.
  moveDelay;
  chassis.moveDistance(2_ft);//Goes forward from wall.
  moveDelay;
  chassis.setMaxVelocity(60);
  chassis.turnAngle(93_deg);//Turns left.
  moveDelay;
  chassis.setMaxVelocity(120);
  chassis.moveDistance(2_ft);
  moveDelay;
  chassis.setMaxVelocity(60);
  chassis.turnAngle(-93_deg);
  moveDelay;
  chassis.setMaxVelocity(200);
  chassis.moveDistance(6_ft);
  moveDelay;




  /*
  chassis.turnAngle(-130_deg);//Turns to corner of platform.
  moveDelay;
  autonIntake = true;//Starts intake.
  intakeToggle(true);//Moves intake up.
  chassis.setMaxVelocity(150);
  chassis.moveDistance(1.6_ft);//Moves up to corner and collects ball.
  moveDelay;
  chassis.setMaxVelocity(120);
  chassis.moveDistance(-1.6_ft);//Backs up.
  moveDelay;
  chassis.setMaxVelocity(60);
  chassis.turnAngle(-60_deg);//Turns parallel to wall.
  autonIntake = false;
  moveDelay;
  chassis.setMaxVelocity(150);
  chassis.moveDistance(3.8_ft);//Moves forward to position for second ball on platform.
  moveDelay;
  chassis.setMaxVelocity(60);
  chassis.turnAngle(125_deg);//Turns to corner of platform.
  autonIntake = true;//Starts intake.
  intakeToggle(true);//Moves intake up.
  moveDelay;
  chassis.setMaxVelocity(125);
  chassis.moveDistance(1.4_ft);//Moves up to corner and collects second ball.
  moveDelay;
  chassis.moveDistance(-1_ft);//Backs up.
  moveDelay;
  chassis.setMaxVelocity(60);
  chassis.turnAngle(-35_deg);//Turns perpendicular to side wall.
  moveDelay;
  chassis.setMaxVelocity(120);
  chassis.moveDistance(-2_ft);//Backs up and aligns against wall.
  moveDelay;
  */


  /*
  chassis.setMaxVelocity(100);
  intake.move(90);//Starts intake.
  chassis.moveDistance(2.9_ft);//Moves up to cap on ball and collects it.
  moveDelay;
  intake.move(0);//Stops intake.
  chassis.moveDistance(-3.9_ft);//Moves back to start and aligns with wall.
  moveDelay;
  chassis.moveDistance(1.1_ft);//Moves to center of tile.
  moveDelay;
  chassis.turnAngle(90_deg);//Turns right to flag.
  moveDelay;
  chassis.moveDistance(1_ft);//Moves to high flag firing position.
  moveDelay;
  // chassis.turnAngle(-10_deg);//Turns to flag.***
  // moveDelay;
  launcherShoot();//Shoots first ball.
  delay(700);
  // chassis.turnAngle(10_deg);//Aligns straight.***
  // moveDelay;
  intake.move(90);//Pulls second ball into launcher.
  chassis.moveDistance(1.5_ft);//Moves to middle flag position.
  moveDelay;
  delay(200);
  // chassis.turnAngle(-10_deg);//Turns to flag.***
  // moveDelay;
  intake.move(0);//Stops intake.
  launcherShoot();//Shoots second ball.
  delay(700);
  // chassis.turnAngle(10_deg);//Aligns straight.***
  // moveDelay;
  chassis.turnAngle(90_deg);//Turns right.**
  moveDelay;
  chassis.moveDistance(.6_ft);
  moveDelay;
  chassis.turnAngle(-90_deg);
  moveDelay;//**
  chassis.moveDistance(2_ft);//Scores low flag and aligns on wall.
  moveDelay;
  chassis.moveDistance(-1.5_ft);//Moves back.
  moveDelay;
  chassis.turnAngle(-90_deg);//Turns left toward center flags.
  moveDelay;
  chassis.moveDistance(3.8_ft);//Moves in front of middle flags.
  moveDelay;
  chassis.turnAngle(90_deg);//Turns right to lower flag.
  moveDelay;
  chassis.moveDistance(1.5_ft);//Scores low flag and aligns on wall.
  moveDelay;
  chassis.moveDistance(-2.25_ft);//Backs up.
  moveDelay;
  flipper.move_absolute(-590, 100);//Lowers flipper.
  delay(1000);
  chassis.turnAngle(90_deg);//Turns right to cap.
  moveDelay;
  chassis.moveDistance(1.2_ft);//Moves up to cap.
  moveDelay;
  flipper.move_absolute(-20, 100);//Flips cap.
  delay(1000);
  chassis.turnAngle(90_deg);//Turns right to platform.
  moveDelay;
  chassis.setMaxVelocity(150);
  chassis.moveDistance(5_ft);//Yeeeeeeeets onto platform.

*/


  /*
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
  delay(1400);
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
