#pragma once

#include "main.h"

/*Main Buttons*/
#define INTAKE_UP     DIGITAL_R1
#define INTAKE_DOWN   DIGITAL_R2
#define FLIPPER_UP    DIGITAL_L1
#define FLIPPER_DOWN  DIGITAL_L2

#define ALT_BTNS      DIGITAL_X
#define LAUNCH_BTN    DIGITAL_A
#define LAUNCHER_C    DIGITAL_Y
#define LAUNCHER_F    DIGITAL_B

#define INTAKE_TOGG   DIGITAL_UP
#define FLIPPER_TOGG  DIGITAL_DOWN
//#define ###### DIGITAL_LEFT
//#define ###### DIGITAL_RIGHT

#define IS_ALT        master.get_digital(ALT_BTNS)

/*Alt buttons*/
#define INVERT_DRIVE  DIGITAL_UP
#define LOCK_DRIVE    DIGITAL_UP
#define RUN_AUTON     DIGITAL_LEFT
#define CLEAR_ENCODE  DIGITAL_RIGHT
