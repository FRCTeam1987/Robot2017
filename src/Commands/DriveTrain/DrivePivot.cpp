#include "DrivePivot.h"

DrivePivot::DrivePivot(float angleSetpoint, bool reset, bool useAzimuth, float minAngleChange, float angleTolerance) {
	Requires(Robot::driveTrain.get());

	printf("DrivePivot::DrivePivot() - angleSetpoint = %f\n", angleSetpoint);
	m_minAngleChange = minAngleChange;
	m_angleTolerance = angleTolerance;
	m_originalAngleSetpoint = m_angleSetpoint = angleSetpoint;
	m_reset = reset;
	m_azimuth = useAzimuth;
	m_turnSpeed = MIN_TURN_SPEED;
	m_currentAngle = 0;
	m_lastAngle = 0;
	m_clockWise = true;
	m_degreesPerSecond = 0;
	m_isSlow = false;
}

void DrivePivot::Initialize() {
//	printf("DrivePivot::Initialize(), m_angleSetpoint = %f, azimuth = %f\n", m_angleSetpoint, Robot::driveTrain->GetAzimuth());

	m_turnSpeed = MIN_TURN_SPEED;
	m_currentAngle = 0;
	m_lastAngle = 0;
	m_degreesPerSecond = 0;
	m_isSlow = false;

	if(m_reset || m_azimuth) {
		Robot::driveTrain->ResetHeadingOffset();
//		Robot::driveTrain->SetAzimuth(Robot::driveTrain->GetAngle());
	}
	m_angleSetpoint = m_originalAngleSetpoint + Robot::driveTrain->GetHeadingChange();

//	if(m_azimuth == true)
//	{
//		m_angleSetpoint = Robot::driveTrain->GetAzimuth();
//		printf("Azimuth in AutoTurnSmallAngle = %f\n", Robot::driveTrain->GetAzimuth());
//
//		if(m_angleSetpoint < 0)
//		{
//			m_angleSetpoint += 360;
//		}
//		else if(m_angleSetpoint > 360)
//		{
//			m_angleSetpoint -=360;
//		}
//	}

	printf("m_angleSetpoint = %f\n", m_angleSetpoint);
	if(m_angleSetpoint > 0)
	{
		m_clockWise = true;
//		if(m_azimuth == true)
//		{
//			m_angleSetpoint -= 1.5; // +2.0 for close
//			printf("Adding in clockwise offset\n");
//		}
		m_turnSpeed = -m_turnSpeed;
	}
	else
	{
		m_angleSetpoint += 360;
		m_clockWise = false;
//		if(m_azimuth == true)
//		{
//			m_angleSetpoint -= 0.5; // -.5 for close
//			printf("Adding in counterclockwise offset\n");
//		}
	}

	Robot::driveTrain->SetBrake();

	printf("Clockwise = %s\t Setpoint is = %f\n", (m_clockWise ? "True" : "False") , m_angleSetpoint);
}

void DrivePivot::Execute() {
	m_currentAngle = Robot::driveTrain->GetHeadingChange();

	bool m_isMoving = isMoving(fabs(m_currentAngle - m_lastAngle));

	if(m_isMoving == false) //&& m_isSlow == false)
	{
		if(m_clockWise == false)
		{
			m_turnSpeed += TURN_SPEED_INCREMENT;
		}
		else
		{
			m_turnSpeed -= TURN_SPEED_INCREMENT;
		}
	}
	else if(m_isMoving == true && m_angleSetpoint > 2)
	{
		if(m_clockWise == true)
		{
			if(m_angleSetpoint - (m_angleTolerance + 2) < m_currentAngle && m_currentAngle < 358)
			{
//				m_isSlow = true;
				if(m_turnSpeed < 0)
					m_turnSpeed += 0.1;
				printf("Reducing speed\n");
			}
		}
		else
		{
			if(m_currentAngle < (m_angleSetpoint + m_angleTolerance + 2) && m_currentAngle > 2)
			{
//				m_isSlow = true;
				if(m_turnSpeed > 0)
					m_turnSpeed -= 0.1;
				printf("Reducing speed\n");
			}
		}
	}

	Robot::driveTrain->AutoDrive(0, m_turnSpeed);

	m_degreesPerSecond = (m_currentAngle - m_lastAngle)/(0.02);

//	printf("Setpoint = %f\t Angle = %f\t Last Angle = %f\t Clockwise = %s\t Turn Speed %f\t Degrees/Second %f\n", m_angleSetpoint, m_currentAngle, m_lastAngle, (m_clockWise ? "True" : "False"), m_turnSpeed, m_degreesPerSecond);

	m_lastAngle = m_currentAngle;
}

bool DrivePivot::IsFinished() {
	if(m_clockWise == true)
	{
		return (m_angleSetpoint - m_angleTolerance) < m_currentAngle && m_currentAngle < 358;
	}
	else
	{
		return m_currentAngle < (m_angleSetpoint + m_angleTolerance) && m_currentAngle > 2;
	}
}

void DrivePivot::End() {
	Robot::driveTrain.get()->DriveTank(0, 0);
}

void DrivePivot::Interrupted() {
	Robot::driveTrain.get()->DriveTank(0, 0);
}

bool DrivePivot::isMoving(float angleChange)
{
	return angleChange > m_minAngleChange;
}
