#include "StartShooter.h"

StartShooter::StartShooter(float WheelRPM) {
	Requires(Robot::shooter.get());
	m_RPM = WheelRPM;
}

void StartShooter::Initialize() {
	Robot::shooter.get()->StartShooter(m_RPM);
}

void StartShooter::Execute() {
}

bool StartShooter::IsFinished() {
	return true;
}

void StartShooter::End() {
}

void StartShooter::Interrupted() {
	Robot::shooter.get()->StopShooter();
}
