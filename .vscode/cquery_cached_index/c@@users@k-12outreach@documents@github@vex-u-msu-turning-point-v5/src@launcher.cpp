#include "launcher.hpp"

/**
Holds the launcher close to firing to allow quicker shooting.
*/
void launcherControl(){
  //while (true) {
    /*if (limitSwitch.get_value()) {
      if (master.get_digital(DIGITAL_A)){
        launcherL.move_velocity(100);
        launcherR.move_velocity(100);
      }
      else{
        launcherL.set_brake_mode(E_MOTOR_BRAKE_HOLD);
        launcherR.set_brake_mode(E_MOTOR_BRAKE_HOLD);
        launcherL.move_velocity(0);
        launcherR.move_velocity(0);
      }
    }
    else{
      launcherL.set_brake_mode(E_MOTOR_BRAKE_COAST);
      launcherR.set_brake_mode(E_MOTOR_BRAKE_COAST);
      launcherL.move_velocity(100);
      launcherR.move_velocity(100);
    }*/
  //}
}

/**
Activates the launcher.
*/
void launcherShoot(){
  launcherL.move_absolute(1800, 300);
  launcherR.move_relative(1800, 300);
}

int angle_1 = 0;
int angle_2 = 300;
int angle_3 = 600;
int angle_4 = 880;
int l_power = 400;
int last_pos = 1;
void launcherMove(bool close) {
  if(close) {
    if(last_pos != 1) {
      launcherAngle.moveAbsolute(angle_1, l_power);
      last_pos = 1;
    }
    else {
      launcherAngle.moveAbsolute(angle_2, l_power);
      last_pos = 2;
    }
  }
  else {
    if(last_pos != 3) {
      launcherAngle.moveAbsolute(angle_3, l_power);
      last_pos = 3;
    }
    else {
      launcherAngle.moveAbsolute(angle_4, l_power);
      last_pos = 4;
    }
  }
}

void launcherCheck() {
  int curr_pos = launcherAngle.getPosition();
  switch(last_pos) {
    case 1: if(abs(curr_pos - angle_1) < 5) launcherAngle.moveVelocity(0);
      break;
    case 2: if(abs(curr_pos - angle_2) < 5) launcherAngle.moveVelocity(0);
      break;
    case 3: if(abs(curr_pos - angle_3) < 5) launcherAngle.moveVelocity(0);
      break;
    case 4: if(abs(curr_pos - angle_4) < 5) launcherAngle.moveVelocity(0);
      break;
  }
}
