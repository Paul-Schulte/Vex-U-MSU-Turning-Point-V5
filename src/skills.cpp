#include "skills.hpp"

using namespace okapi;
#define moveDelay delay(100)

void skills() {
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
  chassis.turnAngle(-93_deg);//Turns left to align with flags.
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

  chassis.turnAngle(-93_deg);
  moveDelay;
  chassis.moveDistance(.7_ft);
  moveDelay;
  chassis.turnAngle(93_deg);
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
  chassis.moveDistance(6_ft);



  /*
  chassis.setMaxVelocity(150);
  intake.move(90);//Starts intake.
  chassis.moveDistance(3.5_ft);//Moves up to cap on ball and collects it.
  moveDelay;
  intake.move(0);//Stops intake.
  chassis.moveDistance(-4.4_ft);//Moves back to start and aligns with wall.
  moveDelay;
  chassis.setMaxVelocity(100);
  chassis.moveDistance(0.5_ft);//Moves to center of tile.
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
  intake.move(0);//Stops intake.
  chassis.turnAngle(-90_deg);//Turns left to lower flag.
  moveDelay;
  chassis.moveDistance(1.5_ft);//Scores low flag and aligns on wall.
  moveDelay;
  chassis.moveDistance(-1.85_ft);
  moveDelay;
  launcherShoot();
  delay(700);
  chassis.moveDistance(-.4_ft);
  // chassis.moveDistance(-2.25_ft);//Backs up.
  moveDelay;
  flipper.move_absolute(-590, 100);//Lowers flipper.
  delay(1000);
  chassis.turnAngle(-90_deg);//Turns left to cap.
  moveDelay;
  chassis.moveDistance(1.1_ft);//Moves up to cap.
  moveDelay;
  flipper.move_absolute(-20, 100);//Flips cap.
  delay(1000);
  chassis.turnAngle(-90_deg);//Turns left to platform.
  moveDelay;
  chassis.setMaxVelocity(150);
  chassis.moveDistance(4.9_ft);//Yeeeeeeeets onto platform.
  moveDelay;
  chassis.setMaxVelocity(100);
  chassis.turnAngle(-90_deg);//Turns left to center platform.
  moveDelay;
  chassis.setMaxVelocity(150);
  chassis.moveDistance(2.5_ft);//Yeets onto center platform.
  */
}
