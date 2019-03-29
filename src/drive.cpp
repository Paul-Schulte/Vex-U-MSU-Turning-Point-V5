#include "drive.hpp"

/**
Sets the left and right sides of the drive to the given velocities.

\param left
The velocity set to the left side of the drive.

\param right
The velocity set to the right side of the drive.
 */
void setDrive(int left, int right){
  // chassis.tank(left, right);

  motorL1.move(left);
  motorL2.move(left);
  motorL3.move(left);
  motorR1.move(right);
  motorR2.move(right);
  motorR3.move(right);
}

/**
Drives straight for a given distance.

\param distance
The distance to travel in units.

\param velocity
The maximum velocity the motors will go.
 */
void driveStraight(int distance, int velocity){

  motorL1.move_relative(distance, velocity);
  motorL2.move_relative(distance, velocity);
  motorL3.move_relative(distance, velocity);
  motorR1.move_relative(distance, velocity);
  motorR2.move_relative(distance, velocity);
  motorR3.move_relative(distance, velocity);
}

/**
Turns the robot for a given distance. Left is positive.

\param turn
The amount of units the robot will turn.

\param velocity
The maximum velocity the motors will go.
*/
void driveTurn(int turn, int velocity){
  motorL1.move_relative(turn, velocity);
  motorL2.move_relative(turn, velocity);
  motorL3.move_relative(turn, velocity);
  motorR1.move_relative(-turn, -velocity);
  motorR2.move_relative(-turn, -velocity);
  motorR3.move_relative(-turn, -velocity);
}

//Manually moves each side of the robot.
void driveManual(int turnL, int turnR, int velocityL, int velocityR){
  motorL1.move_relative(turnL, velocityL);
  motorL2.move_relative(turnL, velocityL);
  motorL3.move_relative(turnL, velocityL);
  motorR1.move_relative(turnR, velocityR);
  motorR2.move_relative(turnR, velocityR);
  motorR3.move_relative(turnR, velocityR);
}

/**
Locks the drive.
*/
void driveLock(){
  motorL1.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  motorL2.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  motorL3.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  motorR1.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  motorR2.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  motorR3.set_brake_mode(E_MOTOR_BRAKE_HOLD);
}

/**
Unlocks the drive.
*/
void driveUnlock(){
  motorL1.set_brake_mode(E_MOTOR_BRAKE_COAST);
  motorL2.set_brake_mode(E_MOTOR_BRAKE_COAST);
  motorL3.set_brake_mode(E_MOTOR_BRAKE_COAST);
  motorR1.set_brake_mode(E_MOTOR_BRAKE_COAST);
  motorR2.set_brake_mode(E_MOTOR_BRAKE_COAST);
  motorR3.set_brake_mode(E_MOTOR_BRAKE_COAST);
}
