#pragma once
#include "main.h"


void setDrive(int left, int right);
void driveStraight(int distance, int velocity);
void driveTurn(int turn, int velocity);
void driveManual(int turnL, int turnR, int velocityL, int velocityR);
void driveLock();
void driveUnlock();
