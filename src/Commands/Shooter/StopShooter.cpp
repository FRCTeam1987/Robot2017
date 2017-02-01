#include "StopShooter.h"

StopShooter::StopShooter() {
	Requires(Robot::shooter.get());
}

void StopShooter::Initialize() {
}

void StopShooter::Execute() {
}

bool StopShooter::IsFinished() {
	return true;
}

void StopShooter::End() {
	Robot::shooter.get()->StopShooter();
}

void StopShooter::Interrupted() {
	Robot::shooter.get()->StopShooter();
}
