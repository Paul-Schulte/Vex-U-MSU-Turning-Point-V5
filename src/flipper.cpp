#include "flipper.hpp"


bool flipperUp = true;

void toggleFlipper() {
  if(flipperUp)
    flipper.move_absolute(500, 200);
  else
    flipper.move_absolute(100, 100);

  flipperUp = !flipperUp;
}
