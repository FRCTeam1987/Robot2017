#include "ToggleShift.h"

ToggleShift::ToggleShift() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::driveTrain.get());
}

// Called just before this Command runs the first time
void ToggleShift::Initialize() {
	Robot::driveTrain->ToggleShift();
}

// Called repeatedly when this Command is scheduled to run
void ToggleShift::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleShift::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleShift::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleShift::Interrupted() {

}
