#pragma once
#include "main.h"


extern bool launching;
extern bool hasBall;
extern bool autonIntake;

void intakeToggle(int setUp = -1);
void intakeControl(void*);
