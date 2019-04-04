#include "intake.hpp"


bool toggle_piston = false;
void intakeToggle(int setUp) {
  toggle_piston = !toggle_piston;
  if (setUp != -1) toggle_piston = setUp;
  pistonL.set_value(toggle_piston);
  pistonR.set_value(toggle_piston);
}

void intakeControl() {
  if (master.get_digital(INTAKE_UP) && (intakeSensor.get_value() > 40 || intakeSensor.get_value() != 0))
    intake.move(90);
  else if (master.get_digital(INTAKE_DOWN))
    intake.move(-90);
  else
    intake.move(0);

  if(intakeSensor.get_value() < 40) {
    intakeToggle(true);
    hasBall = true;
  }
}
