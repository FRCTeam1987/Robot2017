#include "SetElevator.h"

SetElevator::SetElevator(float power) {
	Requires(Robot::shooter.get());
	m_power = power;
}

void SetElevator::Initialize() {
	Robot::shooter.get()->SetElevator(m_power);
}

void SetElevator::Execute() {
}

bool SetElevator::IsFinished() {
	return true;
}

void SetElevator::End() {
}

void SetElevator::Interrupted() {
	Robot::shooter.get()->SetElevator(0);
}
