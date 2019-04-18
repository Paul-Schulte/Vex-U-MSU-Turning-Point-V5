#include "intake.hpp"


bool toggle_piston = false;
void intakeToggle(int setUp) {
  toggle_piston = !toggle_piston;
  if (setUp != -1) toggle_piston = setUp;
  pistonL.set_value(toggle_piston);
  pistonR.set_value(toggle_piston);
}

bool launching = false;
bool hasBall = false;

int sensorRange = 32;
void intakeControl(void*) {
  while (true) {
    if (master.get_digital(INTAKE_UP) && !(sensorL.get_value() || sensorR.get_value()))
      intake.move(90);
    else if (master.get_digital(INTAKE_DOWN))
      intake.move(-90);
    else if (!hasBall && (sensorL.get_value() || sensorR.get_value())) {
      intakeToggle(true);
      intake.move(90);
      delay(400);
      intakeToggle(false);
      intake.move(0);
    }
    else
      intake.move(0);

    if (ballSensorL.get_value() < 2650 || ballSensorR.get_value() < 2750) {
      hasBall = true;
    }
    else if (!launching && hasBall) {
      delay(100);
      hasBall = false;
    }

    if ((sensorL.get_value() || sensorR.get_value()) && !hasBall) {
      intakeToggle(true);
    }
    delay(4);
  }
}
