#include "StopElevator.h"

StopElevator::StopElevator() {
	Requires(Robot::shooter.get());
}

void StopElevator::Initialize() {
}


void StopElevator::Execute() {
}

bool StopElevator::IsFinished() {
	return true;
}

void StopElevator::End() {
	Robot::shooter.get()->StopElevator();
}

void StopElevator::Interrupted() {
	Robot::shooter.get()->StopElevator();
}
