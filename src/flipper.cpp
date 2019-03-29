#include "flipper.hpp"


bool isFlipping = false;

bool flipperUp = true;

void toggleFlipper(void* x) {
  while (true) {
    if (master.get_digital_new_press(DIGITAL_UP)) {
      isFlipping = true;

      if(flipperUp) {
        flipper.move_absolute(-590, 100);
        while (flipper.get_position() > -580) {}
        // while(flipper.get_position() > -590)
        //   flipper.move_velocity(-200);
      }
      else {
        flipper.move_absolute(-50, 100);
        while (flipper.get_position() < -50) {}
        // while(flipper.get_position() < -50)
        //   flipper.move_velocity(200);
      }

      isFlipping = false;
      flipperUp = !flipperUp;
    }
  }
}
