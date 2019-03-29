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

	Task flipperTask (toggleFlipper, (void*)"", TASK_PRIORITY_MIN, TASK_STACK_DEPTH_DEFAULT, "");

	bool toggleLauncher = false;
	bool toggleLock = false;
	bool toggleDrive = false;

	while (true) {
		//Sets the drive to tank drive.
		if (master.get_digital_new_press(DIGITAL_B))
			toggleDrive = !toggleDrive;

		//Toggles slow driving.
		if (toggleDrive)
			setDrive(master.get_analog(ANALOG_LY)/2, master.get_analog(ANALOG_RY)/2);
		else
			setDrive(master.get_analog(ANALOG_LY), master.get_analog(ANALOG_RY));

		//Toggles the drive lock.
		if (master.get_digital_new_press(DIGITAL_DOWN)) {
			toggleLock = !toggleLock;
			master.rumble("-");
			toggleLock ? driveLock() : driveUnlock();
		}

		//if (master.get_digital_new_press(DIGITAL_B)) redAuton();


		//Basic flipper controls with toggle.
		if (master.get_digital(DIGIT_L1))
			flipper.move_velocity(200);
		else if (master.get_digital(DIGIT_L2))
			flipper.move_velocity(-200);
		else if (!isFlipping)
			flipper.move_velocity(0);


		//Basic intake controls.
		if (master.get_digital(DIGIT_R1))
			intake.move(90);
		else if (master.get_digital(DIGIT_R2))
			intake.move(-90);
		else
			intake.move(0);


		//Basic launcher controls.
		/*
		if (master.get_digital_new_press(DIGITAL_B))
			toggleLauncher = !toggleLauncher;
*/
		if (toggleLauncher)
			launcherControl();
		else if (master.get_digital(DIGIT_A)) {
			launcherL.move(100);
			launcherR.move(100);
		}
		else {
			launcherL.move(0);
			launcherR.move(0);
		}

		//Auton test while not connected to field.
		if (master.get_digital_new_press(DIGITAL_LEFT) && !competition::is_connected())
			autonomous();

		//Updates display values.
		updateLineVariable(1, motorL1.get_position());
		updateLineVariable(2, motorR1.get_position());
		updateLineVariable(3, flipper.get_position());
		updateLineVariable(4, toggleLock);

		//Resets motor encoders.
		if (master.get_digital_new_press(DIGITAL_RIGHT)) {
			motorL1.tare_position();
			motorR1.tare_position();
			flipper.tare_position();
		}

		//Checks if manual auton is starting.
		startAuton();


		do {
			delay(20);
		} while(isAuton);
	}
}
