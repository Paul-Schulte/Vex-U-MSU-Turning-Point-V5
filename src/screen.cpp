#include "main.h"

int screen = 0;
int maxScreens = 3;
int selection = 0;

void displayScreen(){
  lcd::clear_line(7);
  lcd::clear_line(8);
  
  switch (screen) {
    case 0: lcd::print(7, "Red Auton"); break;
    case 1: lcd::print(7, "Blue Auton"); break;
    case 2: lcd::print(7, "Skills Auton"); break;
    case 3: lcd::print(7, "Run Auton"); break;
  }
  if (screen == selection) lcd::print(8, "[Selected]");
}
