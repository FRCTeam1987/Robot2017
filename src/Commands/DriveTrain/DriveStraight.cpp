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
	Robot::driveTrain.get()->SetAutoTurn(0);
	Robot::driveTrain.get()->SetSetpoint(0);
	Robot::driveTrain.get()->Enable();
}

void DriveStraight::Execute() {
	double deltaSpeed = fabs(fabs(m_currentSpeed) - fabs(m_finalSpeed));
	double currentAverageDistance = (Robot::driveTrain.get()->GetLeftEncoderDistance() + Robot::driveTrain.get()->GetRightEncoderDistance()) / 2;
	double deltaDistance = fabs(fabs(currentAverageDistance) - fabs(m_distance));
	double currentRatio = deltaSpeed / deltaDistance;

	frc::SmartDashboard::PutNumber("autodrive-currentDistance", currentAverageDistance);
	frc::SmartDashboard::PutNumber("autodrive-deltaDistance", deltaDistance);
	frc::SmartDashboard::PutNumber("autodrive-deltaSpeed", deltaSpeed);
	frc::SmartDashboard::PutNumber("autodrive-currentRatio", currentRatio);

	// make an awesome function for this
	// also this doesn't work for ending at certain speeds
	if (m_distance > 0) {
		if (deltaDistance > 12 && fabs(m_currentSpeed) < fabs(m_maxSpeed)) {
			m_currentSpeed += m_accRate*2;
		} else if (deltaDistance <= 12 && m_currentSpeed > 0.2 && fabs(m_currentSpeed) >  fabs(m_finalSpeed)) {
			m_currentSpeed -= m_accRate*2;
		}
	} else {
		if (deltaDistance > 12 && fabs(m_currentSpeed) < fabs(m_maxSpeed)) {
			m_currentSpeed -= m_accRate*2;
		} else if (deltaDistance <= 12 && m_currentSpeed > 0.2 && fabs(m_currentSpeed) >  fabs(m_finalSpeed)) {
			m_currentSpeed += m_accRate*2;
		}
	}

	Robot::driveTrain.get()->SetAutoSpeed(m_currentSpeed);
}

bool DriveStraight::IsFinished() {
	return fabs(Robot::driveTrain.get()->GetLeftEncoderDistance()) >= fabs(m_distance) && fabs(Robot::driveTrain.get()->GetRightEncoderDistance()) >= fabs(m_distance);
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
