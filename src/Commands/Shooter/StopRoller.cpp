#include "StopRoller.h"

StopRoller::StopRoller() {
	Requires(Robot::shooter.get());
}

void StopRoller::Initialize() {

}

void StopRoller::Execute() {

}

bool StopRoller::IsFinished() {
	return true;
}

void StopRoller::End() {
	Robot::shooter.get()->StopRoller();
}

void StopRoller::Interrupted() {
	Robot::shooter.get()->StopRoller();
}
