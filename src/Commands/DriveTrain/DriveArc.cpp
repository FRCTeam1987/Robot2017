#include "DriveArc.h"

DriveArc::DriveArc(double initialSpeed, double finalSpeed, double radius, double angle) {
	Requires(Robot::driveTrain.get());
	m_radius = radius;
	m_angle = angle;
	m_currentSpeed = 0;
	m_currentAngle = 0;
	m_isDec = false;
	m_initialSpeed = initialSpeed;
	m_finalSpeed = finalSpeed;

	m_leftRadius = radius - (m_robotWidth/2);
	m_rightRadius = radius + (m_robotWidth/2);

	m_leftDistance = m_leftRadius * m_angle;
	m_rightDistance = m_rightRadius * m_angle;

	m_distance = (m_leftDistance + m_rightDistance) / 2;
}

void DriveArc::Initialize() {
	m_currentSpeed = m_initialSpeed;
	Robot::driveTrain.get()->ZeroEncoders();
	Robot::driveTrain.get()->SetAutoSpeed(m_currentSpeed);
	Robot::driveTrain.get()->SetSetpoint(m_currentAngle);
	Robot::driveTrain.get()->Enable();
}

void DriveArc::Execute() {
	double deltaSpeed = m_currentSpeed - m_finalSpeed;
	double currentAverageDistance = (Robot::driveTrain.get()->GetLeftEncoderDistance() + Robot::driveTrain.get()->GetRightEncoderDistance()) / 2;
	double deltaDistance = currentAverageDistance - m_distance;
	double currentRatio = deltaSpeed / deltaDistance;

	double percentDriven = deltaDistance / m_distance;

	m_currentAngle = percentDriven * m_angle;

	if (m_isDec) {
		m_currentSpeed -= m_accRate;
	} else if (currentRatio <= m_decRatio && m_currentSpeed < m_maxSpeed) {
		m_currentSpeed += m_accRate;
	} else if (currentRatio <= m_decRatio && m_currentSpeed == m_maxSpeed) {
		return;
	} else if (currentRatio >= m_decRatio) {
		m_isDec = true;
		m_currentSpeed -= m_accRate;
	}

//	Should not need to do this because the PID subsystem is enabled.
//	Robot::driveTrain.get()->AutoDrive(m_currentSpeed, m_currentAngle);
}

bool DriveArc::IsFinished() {
	return fabs(Robot::driveTrain.get()->GetLeftEncoderDistance()) >= fabs(m_leftDistance) && fabs(Robot::driveTrain.get()->GetRightEncoderDistance()) >= fabs(m_rightDistance) && (m_angle >= Robot::driveTrain.get()->GetAngle());
}

void DriveArc::End() {
	frc::SmartDashboard::PutNumber("Left Encoder Post Drive Arc", Robot::driveTrain.get()->GetLeftEncoderDistance());
	frc::SmartDashboard::PutNumber("Right Encoder Post Drive Arc", Robot::driveTrain.get()->GetRightEncoderDistance());
	Robot::driveTrain.get()->Disable();
	Robot::driveTrain.get()->AutoDrive(m_finalSpeed, 0);
}

void DriveArc::Interrupted() {
	Robot::driveTrain.get()->Disable();
	Robot::driveTrain.get()->AutoDrive(0, 0);
}
