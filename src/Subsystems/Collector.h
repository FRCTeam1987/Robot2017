#ifndef Collector_H
#define Collector_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>
#include "WPILib.h"


class Collector : public frc::Subsystem {
private:
	std::shared_ptr<CANTalon> collectorMotor;

public:
	Collector();
	void InitDefaultCommand();
	void StartRoller();
	void StopRoller();
};

#endif  // Collector_H
