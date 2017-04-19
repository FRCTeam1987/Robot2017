#ifndef Collector_H
#define Collector_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>
#include "WPILib.h"


class Collector : public frc::Subsystem {
private:
	std::shared_ptr<Talon> roller;
	std::shared_ptr<frc::DigitalInput> ballSensor;
	bool m_isEnabled;

public:
	Collector();
	void InitDefaultCommand();
	void DisableDefaultCommand();
	bool HasBall();
	void SetRoller(float power);
	void ToggleDefault();
};

#endif  // Collector_H
