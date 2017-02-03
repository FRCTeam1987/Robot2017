#include "SetRoller.h"

SetRoller::SetRoller(float power) {
	Requires(Robot::shooter.get());
	m_power = power;
}

void SetRoller::Initialize() {
	Robot::shooter.get()->SetRoller(m_power);
}

void SetRoller::Execute() {
}

bool SetRoller::IsFinished() {
	return true;
}

void SetRoller::End() {
}

void SetRoller::Interrupted() {
	Robot::shooter.get()->SetRoller(0);
}
