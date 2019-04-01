#include "launcher.hpp"

/**
Holds the launcher close to firing to allow quicker shooting.
*/
void launcherControl(){
  //while (true) {
    if (limitSwitch.get_value()) {
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
    }
  //}
}

/**
Activates the launcher.
*/
void launcherShoot(){
  launcherL.move_relative(1800, 300);
  launcherR.move_relative(1800, 300);
}

int l_angle_cl = 0;
int l_angle_ch = 300;
int l_angle_fl = 600;
int l_angle_fh = 880;
int l_power = 400;
int last_pos = 1;
void launcherMove(bool close) {
  launcherAngle.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);

  if(close) {
    if(last_pos != 1) {
      launcherAngle.moveAbsolute(l_angle_cl, l_power);
      last_pos = 1;
    } else {
      launcherAngle.moveAbsolute(l_angle_ch, l_power);
      last_pos = 2;
    }
  }
  else {
    if(last_pos != 3) {
      launcherAngle.moveAbsolute(l_angle_fl, l_power);
      last_pos = 3;
    } else {
      launcherAngle.moveAbsolute(l_angle_fh, l_power);
      last_pos = 4;
    }
  }
}
