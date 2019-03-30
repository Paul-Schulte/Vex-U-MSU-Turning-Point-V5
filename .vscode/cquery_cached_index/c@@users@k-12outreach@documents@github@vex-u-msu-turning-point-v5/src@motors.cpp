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
okapi::MotorGroup driveR({17, -18, 19, -20});

okapi::ChassisControllerPID chassis = okapi::ChassisControllerFactory::create(driveL, driveR,
  //Distance control
  IterativePosPIDController::Gains{0.006, 0, 0.06},
  //Straightening control
  IterativePosPIDController::Gains{0.005, 0, 0.7},
  //Turning control
  IterativePosPIDController::Gains{0.006, 0, 0},
  okapi::AbstractMotor::gearset::green, {4_in, 12.0625_in});

//Other motors
Motor launcherL  (10, GEAR_RED, true);
Motor launcherR (11, GEAR_RED, false);
Motor flipper   (8, GEAR_RED, true);
Motor intake    (7, GEAR_BLUE, false);

bool isAuton;
