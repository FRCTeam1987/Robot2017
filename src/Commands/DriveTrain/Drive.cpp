#include "Drive.h"

Drive::Drive() {
	Requires(Robot::driveTrain.get());
}

void Drive::Initialize() {
}

void Drive::Execute() {
	Robot::driveTrain.get()->DriveArcade(RobotMap::xbox.get());
	Robot::driveTrain->UpdateHistory();
}

bool Drive::IsFinished() {
	return false;
}

void Drive::End() {
}

void Drive::Interrupted() {
}
