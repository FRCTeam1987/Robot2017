#include "DriveRotate.h"


DriveRotate::DriveRotate(float desiredAngle) {
	Requires(Robot::driveTrain.get());
	m_desiredAngle = desiredAngle;
	m_turnSpeed = 0;
	m_isClockwise = false;
	m_initialAngle = 0;
	m_minTurnSpeed = 0;
}

void DriveRotate::Initialize() {
	printf("Drive Rotate Initialized\n");
	m_turnSpeed = 0;
	m_minTurnSpeed = 0;
	m_initialAngle = Robot::driveTrain->GetAngle();
	if(m_desiredAngle - m_initialAngle > 0) {
		m_isClockwise = m_desiredAngle - m_initialAngle < 180;
	} else {
		m_isClockwise = m_initialAngle - m_desiredAngle > 180;
	}
}

void DriveRotate::Execute() {
//	if(fabs(m_turnSpeed) >= m_maxTurnSpeed) {
//		return;
//	}
	printf("Drive Rotate Execute\n");

	if(IsRotating() == true && m_minTurnSpeed == 0) {
		m_minTurnSpeed = m_turnSpeed;
	}
	if(IsAlmostThere() == true && fabs(m_minTurnSpeed) > 0) {
		m_turnSpeed = m_minTurnSpeed;
	} else if(m_isClockwise == false && m_turnSpeed < m_maxTurnSpeed) {
		m_turnSpeed += m_turnSpeedInc;
	} else if(m_isClockwise == true && m_turnSpeed > -m_maxTurnSpeed) {
		m_turnSpeed -= m_turnSpeedInc;
	}
	Robot::driveTrain->AutoDrive(0, m_turnSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveRotate::IsFinished() {
	printf("angle: %f, is rotating: %f, is clockwise: %f, min turn speed: %f, turn speed: %f, almost there: %f\n", Robot::driveTrain->GetAngle(), Robot::driveTrain->IsRotating() ? 1.0 : 0.0, m_isClockwise ? 1.0 : 0.0, m_minTurnSpeed, m_turnSpeed, IsAlmostThere() ? 1.0 : 0.0);
	float lowerBound = m_desiredAngle - m_tolerance;
	float upperBound = m_desiredAngle + m_tolerance;
//	if(lowerBound < 0) {
//		lowerBound += 360;
//	}
//	if(upperBound > 360) {
//		upperBound -= 360;
//	}
	// probs won't work for close to 360/0, pls fix
	return (Robot::driveTrain->GetAngle() > lowerBound &&
			Robot::driveTrain->GetAngle() < upperBound);
}

// Called once after isFinished returns true
void DriveRotate::End() {
	printf("Drive Roate End\n");
	Robot::driveTrain->AutoDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveRotate::Interrupted() {
	Robot::driveTrain->AutoDrive(0, 0);
}

bool DriveRotate::IsRotating(){
	return fabs(Robot::driveTrain->GetAngle() - m_initialAngle) > 0.05;
}

bool DriveRotate::IsAlmostThere(){
	return fabs(m_desiredAngle - Robot::driveTrain->GetAngle()) <= m_isAlmostThereAngle;
}
