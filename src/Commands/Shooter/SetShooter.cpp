#include "SetShooter.h"

SetShooter::SetShooter(float power) {
	Requires(Robot::shooter.get());
	m_power = power;
}

void SetShooter::Initialize() {
	Robot::shooter.get()->SetShooter(m_power);
}

void SetShooter::Execute() {
}

bool SetShooter::IsFinished() {
	return true;
}

void SetShooter::End() {
}

void SetShooter::Interrupted() {
	Robot::shooter.get()->SetShooter(0);
}
