#include "DrivePivot.h"

DrivePivot::DrivePivot(double angle) {
	Requires(Robot::driveTrain.get());
	m_angle = angle;
	m_currentAngle = 0;
	m_isDec = false;
}

void DrivePivot::Initialize() {
	Robot::driveTrain.get()->Enable();
}

void DrivePivot::Execute() {
	m_currentAngle++;

	if (m_isDec) {
		Robot::driveTrain.get()->SetSetpoint(m_currentAngle - 1);
	} else if (m_currentAngle <= (m_angle - 20)) {
		Robot::driveTrain.get()->SetSetpoint(m_currentAngle + 1);
	} else if (m_currentAngle >= m_angle) {
		m_isDec = true;
	}
}

bool DrivePivot::IsFinished() {
	return Robot::driveTrain.get()->GetAngle() <= m_angle;
}

void DrivePivot::End() {
	Robot::driveTrain.get()->Disable();
	Robot::driveTrain.get()->AutoDrive(0, 0);
}

void DrivePivot::Interrupted() {
	Robot::driveTrain.get()->Disable();
	Robot::driveTrain.get()->AutoDrive(0, 0);
}
