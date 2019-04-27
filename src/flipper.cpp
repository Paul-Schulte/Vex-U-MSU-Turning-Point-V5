#include "flipper.hpp"


bool flipperUp = true;
int flipperMax = 550;
int flipperMin = 150;

void toggleFlipper() {
  if(flipperUp)
    flipper.move_absolute(flipperMax, 200);
  else
    flipper.move_absolute(flipperMin, 100);

  flipperUp = !flipperUp;
}

void flipperCheck() {
  if ((flipper.get_position() <= flipperMin && flipperUp) || (flipper.get_position() >= flipperMax && !flipperUp))
    flipper.move_velocity(0);
}
