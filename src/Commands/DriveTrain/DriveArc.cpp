#include "DriveArc.h"
#include "Timer.h"

DriveArc::DriveArc(double initialSpeed, double finalSpeed, double radius, double angle) {
	Requires(Robot::driveTrain.get());
	m_radius = radius;
	m_angle = (3.14/180)*(angle);
	m_currentSpeed = 0;
	m_currentAngle = 0;
	m_isDec = false;
	m_initialSpeed = initialSpeed;
	m_finalSpeed = finalSpeed;
	m_initialAngle = 0;
	m_desiredAngle = angle;
	m_isClockwise = false;



	m_initialSpeed = .75;

	m_leftRadius = radius - (m_robotWidth/2);
	m_rightRadius = radius + (m_robotWidth/2);

	m_leftDistance = m_leftRadius * m_angle;
	m_rightDistance = m_rightRadius * m_angle;

	m_distance = (m_leftDistance + m_rightDistance) / 2;
}

void DriveArc::Initialize() {
	printf("DriveArc::Initialize\n");
	m_currentSpeed = m_initialSpeed;
	Robot::driveTrain.get()->ZeroEncoders();
//	Robot::driveTrain.get()->ZeroAngle();
	m_initialAngle = Robot::driveTrain->GetAngle();
	if(m_desiredAngle - m_initialAngle > 0) {
		m_isClockwise = m_desiredAngle - m_initialAngle < 180;
	} else {
		m_isClockwise = m_initialAngle - m_desiredAngle > 180;
	}
	Robot::driveTrain.get()->SetAutoSpeed(m_currentSpeed);
	Robot::driveTrain.get()->SetSetpoint(m_currentAngle);
	Robot::driveTrain.get()->Enable();
}

void DriveArc::Execute() {
	printf("DriveArc::Execute::Thing\n");
	while(1) {
	printf("DriveArc::Execute\n");
	double deltaSpeed = m_currentSpeed - m_finalSpeed;
	double currentAverageDistance = (Robot::driveTrain.get()->GetLeftEncoderDistance() + Robot::driveTrain.get()->GetRightEncoderDistance()) / 2;
	double deltaDistance = m_distance - currentAverageDistance;
//	double currentRatio = deltaSpeed / deltaDistance;

	double percentDriven = currentAverageDistance / m_distance;

	printf("Percent Driven: %f\n", percentDriven);
	m_currentAngle = percentDriven * (m_angle * (180 / 3.14));

//	if (deltaDistance > 12 && m_currentSpeed < m_maxSpeed) {
//		m_currentSpeed += m_accRate;
//	} else if (deltaDistance <= 12 && m_currentSpeed > 0.2) {
//		m_currentSpeed -= m_accRate;
//	}

	printf("Current Target Angle: %f Current Angle: %f Percent Driven: %f\n", m_currentAngle, Robot::driveTrain.get()->GetAngle(), percentDriven);

//	if (m_isClockwise) {
//		printf("Set Auto Turn Clockwise: %f\n", Robot::driveTrain.get()->GetAngle() - m_currentAngle);
//		Robot::driveTrain.get()->SetAutoTurn(Robot::driveTrain.get()->GetAngle() - m_currentAngle);
//	} else {
//		printf("Set Auto Turn Counter Clockwise: %f\n", m_currentAngle - Robot::driveTrain.get()->GetAngle());
//
//		Robot::driveTrain.get()->SetAutoTurn(m_currentAngle - Robot::driveTrain.get()->GetAngle());
//	}

	Robot::driveTrain.get()->SetAutoSpeed(m_currentSpeed);
	Robot::driveTrain.get()->SetSetpoint(m_currentAngle);


//	if (m_isDec) {
//		m_currentSpeed -= m_accRate;
//	} else if (currentRatio <= m_decRatio && m_currentSpeed < m_maxSpeed) {
//		m_currentSpeed += m_accRate;
//	} else if (currentRatio <= m_decRatio && m_currentSpeed == m_maxSpeed) {
//		return;
//	} else if (currentRatio >= m_decRatio) {
//		m_isDec = true;
//		m_currentSpeed -= m_accRate;
//	}

//	printf("Left Encoder Distance: %f   Right Encoder Distance: %f   Current Angle: %f   Angle Set Point: %f\n", fabs(Robot::driveTrain.get()->GetLeftEncoderDistance()), fabs(Robot::driveTrain.get()->GetRightEncoderDistance()), Robot::driveTrain.get()->GetHeadingChange(), m_currentAngle);
	bool leftDone = fabs(Robot::driveTrain.get()->GetLeftEncoderDistance()) >= fabs(m_leftDistance);
	bool rightDone = fabs(Robot::driveTrain.get()->GetRightEncoderDistance()) >= fabs(m_rightDistance);
	bool angleDone = m_isClockwise ? (m_angle <= Robot::driveTrain.get()->GetAngle())
			: (m_angle >= Robot::driveTrain.get()->GetAngle());

	printf("LeftEncoderEnd: %s,  RightEncoderEnd: %s, AngleEnd: %s\n",
		leftDone ? "true" : "false",
		rightDone ? "true" : "false",
		angleDone ? "true" : "false");
	printf("OverAllEnd: %s\n",
		(leftDone && rightDone && angleDone) ? "true" : "false");
	printf("Timestamp: %f\n", Timer::GetFPGATimestamp());
	if(leftDone && rightDone && angleDone) {
		return;
	}
	Wait(0.005);
	}
}

bool DriveArc::IsFinished() {
//	bool leftDone = fabs(Robot::driveTrain.get()->GetLeftEncoderDistance()) >= fabs(m_leftDistance);
//	bool rightDone = fabs(Robot::driveTrain.get()->GetRightEncoderDistance()) >= fabs(m_rightDistance);
//	bool angleDone = m_isClockwise ? (m_angle <= Robot::driveTrain.get()->GetAngle())
//			: (m_angle >= Robot::driveTrain.get()->GetAngle());
//
//	printf("LeftEncoderEnd: %s,  RightEncoderEnd: %s, AngleEnd: %s\n",
//		leftDone ? "true" : "false",
//		rightDone ? "true" : "false",
//		angleDone ? "true" : "false");
//	printf("OverAllEnd: %s\n",
//		(leftDone && rightDone && angleDone) ? "true" : "false");
//
//	return leftDone && rightDone && angleDone;
	return true;
}

void DriveArc::End() {
	printf("End\n");
	frc::SmartDashboard::PutNumber("Left Encoder Post Drive Arc", Robot::driveTrain.get()->GetLeftEncoderDistance());
	frc::SmartDashboard::PutNumber("Right Encoder Post Drive Arc", Robot::driveTrain.get()->GetRightEncoderDistance());
	Robot::driveTrain.get()->Disable();
	Robot::driveTrain.get()->AutoDrive(m_finalSpeed, 0);
}

void DriveArc::Interrupted() {
	printf("Interrupted\n");
	Robot::driveTrain.get()->Disable();
	Robot::driveTrain.get()->AutoDrive(0, 0);
}
