#include "main.h"

using namespace okapi;

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

/*
Auton notes:
-driving forward should be done at 200 velocity.
-driving back should be done at 100-120 velocity.
-turning should be done at 75 velocity.
*/
void autonomous() {
  intake.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
  launcherAngle.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
  isAuton = true;

  switch (selectedAuton) {
    case 1: redAuton();
      break;
    case 2: blueAuton();
      break;
    case 3: skills();
      break;
  }

  // chassis.setMaxVelocity(200);
  // chassis.moveDistance(5.5_ft);
  // delay(100);
  // chassis.setMaxVelocity(100);
  // chassis.moveDistance(-.5_ft);
  // delay(100);

  // chassis.setMaxVelocity(60);
  // chassis.turnAngle(90_deg);
  // delay(100);

  // chassis.setMaxVelocity(120);
  // chassis.moveDistance(-3_ft);

  // chassis.setMaxVelocity(100);
  // chassis.turnAngle(102_deg);

  chassis.setMaxVelocity(200);
  isAuton = false;
}
