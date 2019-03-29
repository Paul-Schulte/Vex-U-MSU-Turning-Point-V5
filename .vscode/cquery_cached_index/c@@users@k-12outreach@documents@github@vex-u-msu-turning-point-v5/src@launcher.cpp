#include "launcher.hpp"

/**
Holds the launcher close to firing to allow quicker shooting.
*/
void launcherControl(){
  //while (true) {
    if (limitSwitch.get_value()) {
      if (master.get_digital(DIGIT_A)){
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
