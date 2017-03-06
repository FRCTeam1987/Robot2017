#ifndef Turret_H
#define Turret_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>
#include "WPILIB.h"
#include "math.h"
#include "Timer.h"

#include "../Lib/TimeStampedHistory.h"

class Turret : public frc::Subsystem {
private:
	std::shared_ptr<CANTalon> motor;
	double m_angle;
	double m_tolerance;
	double m_driveGearDiameter;
	double m_turretGearDiameter;
	const double m_rotationsToDegrees = (9.98 / 360.0);
	TimeStampedHistory m_history;
	double m_desiredAngle;
public:
	Turret();
	void InitDefaultCommand();
	void SetMyPosition(double deltaAngle);
	void SetPosition(double angle);
	void SetAbsoluteAngle(double angle); // 0 - 359
	double GetPosition();
	double GetAngle();
	double GetPositionError();
	bool isOnTarget();
	void SetVoltage(double voltage);
	void ZeroPosition();
	int GetForwardLimit();
	int GetReverseLimit();
	double GetHeading();
	void UpdateHistory();
	TimeStampedValue GetHistory(double timeStamp);
	TimeStampedValue FetchAngleToGoal();
	void SetDesiredAngle(double desiredAngle);
	void SetDesiredAngle(double desiredAngle, double timeStamp);
	double GetDesiredAngle();
	double GetOutputVoltage();
};

#endif  // Turret_H
