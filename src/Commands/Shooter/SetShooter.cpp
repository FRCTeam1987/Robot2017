#include "SetShooter.h"

SetShooter::SetShooter(float rpm) {
	printf("SetShooter::SetShooter - begin\n");
	Requires(Robot::shooter.get());
	m_rpm = rpm;
	m_tolerance = 10;
	printf("SetShooter::SetShooter - end\n");
}

void SetShooter::Initialize() {
	printf("SetShooter::Initialize - begin\n");
	m_rpm = frc::SmartDashboard::GetNumber("Testing RPM", 0);
	Robot::shooter.get()->SetShooterRpm(m_rpm);
	printf("SetShooter::Initialize - rpm: %f\n", m_rpm);
	printf("SetShooter::Initialize - end\n");
}

void SetShooter::Execute() {
//	printf("SetShooter::Execute - begin\n");
	frc::SmartDashboard::PutNumber("Shooter RPM", Robot::shooter.get()->GetWheelRPM());
//	printf("SetShooter::Execute rpm: %f\n", Robot::shooter.get()->GetWheelRPM());
//	printf("SetShooter::Execute - end\n");

}

bool SetShooter::IsFinished() {
	printf("SetShooter::IsFinished\n");
	return fabs(fabs(Robot::shooter.get()->GetWheelRPM()) - fabs(m_rpm)) <= m_tolerance;
}

void SetShooter::End() {
	printf("SetShooter::End\n");
}

void SetShooter::Interrupted() {
	printf("SetShooter::Interrupted\n");
	Robot::shooter.get()->SetShooter(0);
}
