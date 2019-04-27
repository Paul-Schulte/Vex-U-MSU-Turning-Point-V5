#include "drive.hpp"

using brakeMode = okapi::AbstractMotor::brakeMode;

/**
Sets the left and right sides of the drive to the given velocities.

\param left
The velocity set to the left side of the drive.

\param right
The velocity set to the right side of the drive.
 */
void setDrive(int left, int right, bool invert){
  // motorL1.move(left);
  // motorL2.move(left);
  // motorL3.move(left);
  // motorL4.move(left);
  // motorR1.move(right);
  // motorR2.move(right);
  // motorR3.move(right);
  // motorR4.move(right);
  invert ? chassis.tank(right / -127.0, left / -127.0) : chassis.tank(left / 127.0, right / 127.0);
}

/**
Locks the drive.
*/
void driveLock(){
  // motorL1.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  // motorL2.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  // motorL3.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  // motorL4.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  // motorR1.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  // motorR2.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  // motorR3.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  // motorR4.set_brake_mode(E_MOTOR_BRAKE_HOLD);

  chassis.setBrakeMode(brakeMode::brake);
}

/**
Unlocks the drive.
*/
void driveUnlock(){
  // motorL1.set_brake_mode(E_MOTOR_BRAKE_COAST);
  // motorL2.set_brake_mode(E_MOTOR_BRAKE_COAST);
  // motorL3.set_brake_mode(E_MOTOR_BRAKE_COAST);
  // motorL4.set_brake_mode(E_MOTOR_BRAKE_COAST);
  // motorR1.set_brake_mode(E_MOTOR_BRAKE_COAST);
  // motorR2.set_brake_mode(E_MOTOR_BRAKE_COAST);
  // motorR3.set_brake_mode(E_MOTOR_BRAKE_COAST);
  // motorR4.set_brake_mode(E_MOTOR_BRAKE_COAST);

  chassis.setBrakeMode(brakeMode::coast);
}
