#include "SetPosition.h"

SetPosition::SetPosition(double angle) {
	Requires(Robot::turret.get());
	m_angle = angle;
}

void SetPosition::Initialize() {
	frc::SmartDashboard::PutNumber("Target Angle", m_angle);
	Robot::turret.get()->SetMyPosition(m_angle);
}

void SetPosition::Execute() {
	frc::SmartDashboard::PutNumber("Turret Angle", Robot::turret.get()->GetAngle());
}

bool SetPosition::IsFinished() {
	return (Robot::turret.get()->isOnTarget());
}

void SetPosition::End() {

}

void SetPosition::Interrupted() {

}
