#include "main.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

//int screen = 0;
//int maxScreens = 3;
//int selection = 0;

void onLeftButton(){
  static bool leftPressed = false;
  leftPressed = !leftPressed;
  if (leftPressed)
    screen == 0 ? screen = maxScreens : screen --;
  else
    lcd::clear_line(1);

  displayScreen();
}

void onCenterButton(){
  static bool centerPressed = false;
  centerPressed = !centerPressed;
  if (centerPressed){
    if (screen == maxScreens){
      for (int i = 5; i >= 0; i--)
      {
        lcd::print(1, "Starting Autonomous in : %d", i);
        delay(1000);
      }
      autonomous();
    }
    else
    selection = screen;
  }
  else
    lcd::clear_line(1);

  displayScreen();
}

void onRightButton(){
  static bool rightPressed = false;
  rightPressed = !rightPressed;
  if (rightPressed)
    screen == maxScreens ? screen = 0 : screen ++;
  else
    lcd::clear_line(1);

  displayScreen();
}

void initialize() {
  lcd::initialize();
  lcd::register_btn0_cb(onLeftButton);
  lcd::register_btn1_cb(onCenterButton);
  lcd::register_btn2_cb(onRightButton);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
