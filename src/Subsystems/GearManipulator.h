#ifndef GearManipulator_H
#define GearManipulator_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>
#include "WPILib.h"

class GearManipulator : public frc::Subsystem {
private:
	std::shared_ptr<frc::DigitalInput> gearSensor;
	std::shared_ptr<frc::Solenoid> lift;
	std::shared_ptr<frc::DigitalInput> gearRaisedSensor;
	std::shared_ptr<frc::DigitalInput> gearLoweredSensor;
	std::shared_ptr<CANTalon> roller;

public:
	GearManipulator();
	void InitDefaultCommand();
	bool HasGear();
	bool IsGearLowered();
	bool IsGearRaised();
	void SetGearPosition(bool isRaised);
	void StartRoller(float speed);
	void StopRoller();
};

#endif  // GearManipulator_H
