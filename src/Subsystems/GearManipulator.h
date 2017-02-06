#ifndef GearManipulator_H
#define GearManipulator_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>
#include "WPILib.h"

class GearManipulator : public frc::Subsystem {
private:
	std::shared_ptr<CANTalon> roller;
	std::shared_ptr<frc::DigitalInput> gearSensor;
	std::shared_ptr<frc::DigitalInput> gearRaisedSensor;
	std::shared_ptr<frc::DigitalInput> gearLoweredSensor;
	std::shared_ptr<frc::Solenoid> lift;

public:
	GearManipulator();
	void InitDefaultCommand();
	void SetRoller(float power);
	void SetGearPosition(bool isRaised);
	bool HasGear();
	bool IsGearLowered();
	bool IsGearRaised();
};

#endif  // GearManipulator_H
