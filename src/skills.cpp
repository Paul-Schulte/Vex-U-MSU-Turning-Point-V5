#include "main.h"

void skills(){
  //Move back to lower flipper.
  driveStraight(-1650, 150);
  while (!motorL1.is_stopped())
    delay(10);

  //Lower flipper.
  flipper.move_absolute(-660, -80);
  while (!flipper.is_stopped())
    delay(10);

  //Move forward to launch.
  driveStraight(3200, 150);
  while (!motorL1.is_stopped())
    delay(10);

  //Turn right to launch.
  driveTurn(150, 100);
  while (!motorL1.is_stopped())
    delay(10);

  //Shoots at flag.
  launcherShoot();
  while (!launcherR.is_stopped())
    delay(10);

  //Turn left.
  driveTurn(-150, -100);
  while (!motorL1.is_stopped())
    delay(10);

  //Move forward to hit flag.
  driveStraight(1700, 150);
  while (!motorL1.is_stopped())
    delay(10);

  //Move back.
  driveStraight(-1600, -150);
  while (!motorL1.is_stopped())
    delay(10);

  //Turn to cap.
  driveTurn(600, 100);
  while (!motorL1.is_stopped())
    delay(10);

  //Move to cap.
  driveStraight(825, 100);
  while (!motorL1.is_stopped())
    delay(10);

  //Flip cap.
  flipper.move_absolute(-450, 80);
  while (!flipper.is_stopped())
    delay(10);
  flipper.move_absolute(-660, -80);
  while (!flipper.is_stopped())
    delay(10);

  //Turn right.
  driveTurn(600, 100);
  while (!motorL1.is_stopped())
    delay(10);

  //Move forward.
  driveStraight(1400, 150);
  while (!motorL1.is_stopped())
    delay(10);

  //Turn left to cap.
  driveTurn(-600, -100);
  while (!motorL1.is_stopped())
    delay(10);

  //Move to cap.
  driveStraight(1500, 150);
  while (!motorL1.is_stopped())
    delay(10);

  //Flip cap.
  flipper.move_absolute(-450, 80);
  while (!flipper.is_stopped())
    delay(10);
  flipper.move_absolute(-660, -80);
  while (!flipper.is_stopped())
    delay(10);
}
