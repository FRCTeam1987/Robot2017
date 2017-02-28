#include "DrivePivot2.h"

DrivePivot2::DrivePivot2() {
	Requires(Robot::driveTrain.get());
}

void DrivePivot2::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DrivePivot2::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool DrivePivot2::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DrivePivot2::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DrivePivot2::Interrupted() {

}
