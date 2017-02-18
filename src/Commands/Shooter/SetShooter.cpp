#include "SetShooter.h"

SetShooter::SetShooter(float rpm) {
	Requires(Robot::shooter.get());
	m_rpm = rpm;
	m_tolerance = 50;
}

void SetShooter::Initialize() {
	Robot::shooter.get()->SetShooterRpm(m_rpm);
}

void SetShooter::Execute() {
	frc::SmartDashboard::PutNumber("Shooter RPM", Robot::shooter.get()->GetWheelRPM());
}

bool SetShooter::IsFinished() {
	return fabs(fabs(Robot::shooter.get()->GetWheelRPM()) - fabs(m_rpm)) <= m_tolerance;
}

void SetShooter::End() {
}

void SetShooter::Interrupted() {
	Robot::shooter.get()->SetShooter(0);
}
