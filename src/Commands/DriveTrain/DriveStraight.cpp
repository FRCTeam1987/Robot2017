#include "DriveStraight.h"

DriveStraight::DriveStraight(double speed, float angleSetpoint, double distance) {
	Requires(Robot::driveTrain.get());
	m_speed = speed;
	m_angleSetpoint = angleSetpoint;
	m_distance = distance;
}

void DriveStraight::Initialize() {
	Robot::driveTrain.get()->ZeroEncoders();
	Robot::driveTrain.get()->SetAutoSpeed(m_speed);
	Robot::driveTrain.get()->SetSetpoint(m_angleSetpoint);
}

void DriveStraight::Execute() {
	Robot::driveTrain.get()->AutoDrive(m_speed, m_angleSetpoint);
}

bool DriveStraight::IsFinished() {
	return abs(Robot::driveTrain.get()->GetLeftEncoderDistance()) >= abs(m_distance) && abs(Robot::driveTrain.get()->GetRightEncoderDistance()) >= abs(m_distance);
}

void DriveStraight::End() {
	frc::SmartDashboard::PutNumber("Left Encoder Post Drive", Robot::driveTrain.get()->GetLeftEncoderDistance());
	frc::SmartDashboard::PutNumber("Right Encoder Post Drive", Robot::driveTrain.get()->GetRightEncoderDistance());
}

void DriveStraight::Interrupted() {

}
