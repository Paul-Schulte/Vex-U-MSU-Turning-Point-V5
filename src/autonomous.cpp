#include "main.h"

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
using namespace okapi;

const int DRIVE_L1 = 1;
const int DRIVE_L2 = 2;
const int DRIVE_L3 = 3;
const int DRIVE_R1 = 18;
const int DRIVE_R2 = 19;
const int DRIVE_R3 = 20;
const auto WHEEL_DIAMETER = 4_in;
const auto CHASSIS_WIDTH = 12.5_in;

auto chassis = ChassisControllerFactory::create({DRIVE_L1, DRIVE_L2, DRIVE_L3}, {DRIVE_R1, DRIVE_R2, DRIVE_R3},
  IterativePosPIDController::Gains{0.006, 0, 0.06}, IterativePosPIDController::Gains{0.015, 0.01, 0.8}, IterativePosPIDController::Gains{0.006, 0.0005, 0.06},
  AbstractMotor::gearset::green, {WHEEL_DIAMETER, CHASSIS_WIDTH});


void autonomous() {
  isAuton = true;
  chassis.setMaxVelocity(100);
  //blueAuton();
  //redAuton();
  /*
  Values are not completely accurate due to wheel slop, so turn and distance values need to be slightly adjusted.
  Probably will need trial and error to figure out exact values.

  Turning 90 degreese: 87
  Moving forward 2 ft: about 2' 1"
  */

  //Currently drives in a pretty close square.
  /*
  chassis.moveDistance(2_ft);
  chassis.turnAngle(87_deg);
  chassis.moveDistance(2_ft);
  chassis.turnAngle(87_deg);
  chassis.moveDistance(2_ft);
  chassis.turnAngle(87_deg);
  chassis.moveDistance(2_ft);
  chassis.turnAngle(87_deg);*/

  //chassis.turnAngle(90_deg);
  chassis.moveDistance(2_ft);
  delay(300);
  chassis.moveDistance(-2_ft);

  isAuton = false;
}
