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
public:
	Turret();
	void InitDefaultCommand();
	void SetPosition(double angle);
	double GetPosition();
	double GetPositionError();
	bool isOnTarget();
	void SetVoltage(double voltage);
	void ZeroPosition();
	int GetForwardLimit();
	int GetReverseLimit();
};

#endif  // Turret_H
