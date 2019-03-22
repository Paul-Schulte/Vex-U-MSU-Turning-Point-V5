#include "main.h"

Controller master(E_CONTROLLER_MASTER);

//Drive motors
Motor motorL1 (1, GEAR_GREEN, false);
Motor motorL2 (2, GEAR_GREEN, false);
Motor motorL3 (3, GEAR_GREEN, false);
Motor motorR1 (18, GEAR_GREEN, true);
Motor motorR2 (19, GEAR_GREEN, true);
Motor motorR3 (20, GEAR_GREEN, true);

//Other motors
Motor launcherL  (10, GEAR_RED, true);
Motor launcherR (11, GEAR_RED, false);
Motor flipper   (9, GEAR_GREEN, true);
Motor intake    (8, GEAR_BLUE, false);

bool isAuton;
