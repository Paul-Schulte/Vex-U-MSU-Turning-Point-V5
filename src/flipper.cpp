#include "main.h"

bool flipperUp = true;
bool flipping = false;


void toggleFlipper(){
  flipping = true;
  flipperUp ? flipper.move_absolute(300, 150) : flipper.move_absolute(100, -150);
  flipperUp = !flipperUp;
  flipping = false;
}

void setFlipping(bool in){
  flipping = in;
}

bool isFlipping() {
  return flipping;
}
