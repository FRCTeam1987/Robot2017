#ifndef Turret_H
#define Turret_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>
#include "WPILIB.h"
#include "math.h"

class Turret : public frc::Subsystem {
private:
	std::shared_ptr<CANTalon> motor;
	double m_angle;
	double m_tolerance;
	double m_driveGearDiameter;
	double m_turretGearDiameter;
	const double m_rotationsToDegrees = (10.0 / 360.0);
public:
	Turret();
	void InitDefaultCommand();
	void SetPosition(double angle);
	double GetPosition();
	double GetAngle();
	double GetPositionError();
	bool isOnTarget();
	void SetVoltage(double voltage);
	void ZeroPosition();
	int GetForwardLimit();
	int GetReverseLimit();
	double GetYaw();
};

#endif  // Turret_H
