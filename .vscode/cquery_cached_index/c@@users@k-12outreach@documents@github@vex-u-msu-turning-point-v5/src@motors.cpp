#include "motors.hpp"

using namespace okapi::literals;
using okapi::IterativePosPIDController;

Controller master(E_CONTROLLER_MASTER);

/*NOTE: Port 9 does not work*/

//Drive motors
Motor motorL1 (1, GEAR_GREEN, true);
Motor motorL2 (2, GEAR_GREEN, false);
Motor motorL3 (3, GEAR_GREEN, true);
Motor motorL4 (4, GEAR_GREEN, false);
Motor motorR1 (17, GEAR_GREEN, false);
Motor motorR2 (18, GEAR_GREEN, true);
Motor motorR3 (19, GEAR_GREEN, false);
Motor motorR4 (20, GEAR_GREEN, true);

okapi::MotorGroup driveL({-1, 2, -3, 4});
okapi::MotorGroup driveR({16, -18, 19, -20});

okapi::ChassisControllerPID chassis = okapi::ChassisControllerFactory::create(driveL, driveR,
  //Distance control
  IterativePosPIDController::Gains{0.003, 0.0004, 0.0002},//0.003, 0.000, 0.0002
  //Straightening control
  IterativePosPIDController::Gains{0.0001, 0.0000, 0.00016},//0.01, 0.0001, 0.0001
  //Turning control
  IterativePosPIDController::Gains{0.017, 0.013, 0.0012},//0.035, 0.01, 0.0015 //0.035, 0.01, 0.0006
  okapi::AbstractMotor::gearset::green, {4.125_in, 12.25_in});

using okapi::AbstractMotor;

//Other motors
Motor launcherL  (10, GEAR_RED, true);
Motor launcherR (11, GEAR_RED, false);
okapi::Motor launcherAngle (12, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor flipper   (8, GEAR_RED, false);
okapi::Motor intake (7, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
// Motor intake    (7, GEAR_BLUE, false);

bool isAuton;
