#include "DriveStraight.h"

DriveStraight::DriveStraight(double distance, double initialSpeed, double finalSpeed) {
	Requires(Robot::driveTrain.get());
	m_distance = distance;
	m_initialSpeed = initialSpeed;
	m_finalSpeed = finalSpeed;
	m_isDec = false;
	m_currentSpeed = 0;
}

void DriveStraight::Initialize() {
	m_currentSpeed = m_initialSpeed;
	Robot::driveTrain.get()->ZeroEncoders();
	Robot::driveTrain.get()->ZeroAngle();
	Robot::driveTrain.get()->SetAutoSpeed(m_currentSpeed);
	Robot::driveTrain.get()->SetSetpoint(0);
	Robot::driveTrain.get()->Enable();
}

void DriveStraight::Execute() {
	double deltaSpeed = m_currentSpeed - m_finalSpeed;
	double currentAverageDistance = (Robot::driveTrain.get()->GetLeftEncoderDistance() + Robot::driveTrain.get()->GetRightEncoderDistance()) / 2;
	double deltaDistance = currentAverageDistance - m_distance;
	double currentRatio = deltaSpeed / deltaDistance;

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

	Robot::driveTrain.get()->SetAutoSpeed(m_currentSpeed);

//	Should not need to do this because the PID subsystem is enabled.
//	Robot::driveTrain.get()->AutoDrive(m_currentSpeed, 0);

}

bool DriveStraight::IsFinished() {
	return abs(Robot::driveTrain.get()->GetLeftEncoderDistance()) >= abs(m_distance) && abs(Robot::driveTrain.get()->GetRightEncoderDistance()) >= abs(m_distance);
}

void DriveStraight::End() {
	frc::SmartDashboard::PutNumber("Left Encoder Post Drive", Robot::driveTrain.get()->GetLeftEncoderDistance());
	frc::SmartDashboard::PutNumber("Right Encoder Post Drive", Robot::driveTrain.get()->GetRightEncoderDistance());
	Robot::driveTrain.get()->Disable();
	Robot::driveTrain.get()->AutoDrive(m_finalSpeed, 0);
	Robot::driveTrain.get()->SetAutoSpeed(m_currentSpeed);
}

void DriveStraight::Interrupted() {
	Robot::driveTrain.get()->Disable();
	Robot::driveTrain.get()->AutoDrive(0, 0);
}
