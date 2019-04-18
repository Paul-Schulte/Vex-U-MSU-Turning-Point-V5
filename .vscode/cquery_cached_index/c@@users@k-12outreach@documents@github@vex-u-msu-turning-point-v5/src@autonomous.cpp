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


void autonomous() {
  isAuton = true;

  // switch (selectedAuton) {
  //   case 1: redAuton();
  //     break;
  //   case 2: blueAuton();
  //     break;
  //   case 3: skills();
  //     break;
  // }

  chassis.setMaxVelocity(100);
  chassis.turnAngle(95_deg);
  delay(2000);

  // driveL.moveRelative(1000, 100);
  // delay(4000);

  chassis.setMaxVelocity(200);
  isAuton = false;
}
