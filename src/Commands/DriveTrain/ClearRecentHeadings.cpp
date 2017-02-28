#include "ClearRecentHeadings.h"

ClearRecentHeadings::ClearRecentHeadings() {
	Requires(Robot::driveTrain.get());
}

// Called just before this Command runs the first time
void ClearRecentHeadings::Initialize() {
	Robot::driveTrain.get()->ClearRecentHeadings();
}

// Called repeatedly when this Command is scheduled to run
void ClearRecentHeadings::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ClearRecentHeadings::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ClearRecentHeadings::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClearRecentHeadings::Interrupted() {

}
