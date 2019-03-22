#ifndef DRIVE_HPP
#define DRIVE_HPP


void setDrive(int left, int right);
void driveStraight(int distance, int velocity);
void driveTurn(int turn, int velocity);
void driveManual(int turnL, int turnR, int velocityL, int velocityR);
void driveLock();
void driveUnlock();


#endif
