#pragma once
#include "main.h"


extern Controller master;

extern Motor motorL1;
extern Motor motorL2;
extern Motor motorL3;
extern Motor motorL4;
extern Motor motorR1;
extern Motor motorR2;
extern Motor motorR3;
extern Motor motorR4;

extern okapi::MotorGroup driveL;
extern okapi::MotorGroup driveR;

extern okapi::ChassisControllerPID chassis;

extern Motor launcherL;
extern Motor launcherR;
extern okapi::Motor launcherAngle;
extern Motor flipper;
extern Motor intake;

extern bool isAuton;
