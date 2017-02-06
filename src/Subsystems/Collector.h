#ifndef Collector_H
#define Collector_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>
#include "WPILib.h"


class Collector : public frc::Subsystem {
private:
	std::shared_ptr<CANTalon> roller;
	std::shared_ptr<frc::DigitalInput> ballSensor;

public:
	Collector();
	void InitDefaultCommand();
	void SetRoller(float power);
	bool HasBall();
};

#endif  // Collector_H
