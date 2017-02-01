#include "StartElevator.h"

StartElevator::StartElevator(float speed) {
	Requires(Robot::shooter.get());
	m_speed = speed;
}

void StartElevator::Initialize() {
	Robot::shooter.get()->StartElevator(m_speed);
}

void StartElevator::Execute() {
}

bool StartElevator::IsFinished() {
	return true;
}

void StartElevator::End() {
}

void StartElevator::Interrupted() {
	Robot::shooter.get()->StopElevator();
}
