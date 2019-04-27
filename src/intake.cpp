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
bool autonIntake = false;

int sensorRange = 32;
void intakeControl(void*) {
  while (true) {
    if (isAuton) {
      if ((master.get_digital(INTAKE_UP) || autonIntake) && !(sensorL.get_value() || sensorR.get_value()))
        intake.move(70);
        else if (master.get_digital(INTAKE_DOWN))
        intake.move(-90);
        else if (!hasBall && (sensorL.get_value() || sensorR.get_value())) {
          delay(200);
          intakeToggle(true);
          intake.move(70);
          delay(700);
          intakeToggle(false);
          intake.move(0);
        }
        else
        intake.move(0);

        if ((sensorL.get_value() || sensorR.get_value()) && !hasBall) {
          intakeToggle(true);
        }
      }
      else {
        if (master.get_digital(INTAKE_UP)) {
          if (!(sensorL.get_value() || sensorR.get_value())) {
            intake.move(70);
          }
          else if ((sensorL.get_value() || sensorR.get_value()) && !hasBall) {
            intakeToggle(true);
            intake.move(70);
            delay(400);
            intakeToggle(false);
          }
          else {
            intake.move(0);
          }
        }
        else if (master.get_digital(INTAKE_DOWN)) {
          intake.move(-90);
        }
        else {
          intake.move(0);
        }
      }

    if (ballSensorL.get_value() < 2800 || ballSensorR.get_value() < 2800) {
      hasBall = true;
    }
    else if (!launching && hasBall) {
      delay(300);
      hasBall = false;
    }

    delay(4);
  }
}
