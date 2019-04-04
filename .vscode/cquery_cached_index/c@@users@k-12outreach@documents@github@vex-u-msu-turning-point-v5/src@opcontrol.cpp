#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	isAuton = false;

	// Task flipperTask (toggleFlipper, (void*)"", TASK_PRIORITY_MIN, TASK_STACK_DEPTH_DEFAULT, "");
	Task screenAuton (startAuton, (void*)"", TASK_PRIORITY_MIN, TASK_STACK_DEPTH_DEFAULT);

	bool toggleLauncher = false;
	bool toggleLock = false;
	bool toggleDrive = false;

	launcherAngle.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);

	while (true) {
		//Sets the drive to tank drive.
		if (master.get_digital_new_press(INVERT_DRIVE) && master.get_digital(ALT_BTNS))
			toggleDrive = !toggleDrive;

		//Toggles slow driving.
		if (toggleDrive)
			setDrive(master.get_analog(ANALOG_LY)/2, master.get_analog(ANALOG_RY)/2);
		else
			setDrive(master.get_analog(ANALOG_LY), master.get_analog(ANALOG_RY));

		//Toggles the drive lock.
		if (master.get_digital_new_press(LOCK_DRIVE) && master.get_digital(ALT_BTNS)) {
			toggleLock = !toggleLock;
			master.rumble("-");
			toggleLock ? driveLock() : driveUnlock();
		}


		//Basic flipper controls with toggle.
		if (master.get_digital_new_press(FLIPPER_TOGG))
			toggleFlipper();

		flipperCheck();


		//Basic intake controls.
		intakeControl();

		//Toggles intake pneumatics.
		if (master.get_digital_new_press(INTAKE_TOGG) && !master.get_digital(ALT_BTNS))
			intakeToggle();


		//Basic launcher controls.
		if (toggleLauncher)
			launcherControl();
		else if (master.get_digital(LAUNCH_BTN) && !master.get_digital(ALT_BTNS)) {
			launcherL.move(100);
			launcherR.move(100);
		}
		else {
			launcherL.move(0);
			launcherR.move(0);
		}

		//Toggles launcher angle
		if(master.get_digital_new_press(LAUNCHER_C) && !master.get_digital(ALT_BTNS))
			launcherMove(true);
		else if(master.get_digital_new_press(LAUNCHER_F) && !master.get_digital(ALT_BTNS))
			launcherMove(false);

		launcherCheck();


		//Auton test while not connected to field.
		if (master.get_digital_new_press(RUN_AUTON) && !competition::is_connected() && master.get_digital(ALT_BTNS))
			autonomous();

		//Updates display values.
		updateLineVariable(1, driveL.getPosition());
		updateLineVariable(2, driveR.getPosition());
		updateLineVariable(3, flipper.get_position());
		updateLineVariable(4, launcherAngle.getPosition());
		updateLineVariable(5, intakeSensor.get_value());

		//Resets motor encoders.
		if (master.get_digital_new_press(CLEAR_ENCODE) && master.get_digital(ALT_BTNS)) {
			motorL1.tare_position();
			motorR1.tare_position();
			flipper.tare_position();
			launcherAngle.tarePosition();
		}

		//Checks if manual auton is starting.
		// startAuton();

		do {
			delay(10);
		} while(isAuton);
	}
}
