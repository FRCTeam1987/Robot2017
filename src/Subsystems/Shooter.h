#ifndef Shooter_H
#define Shooter_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>
#include "WPILIB.h"

class Shooter : public frc::Subsystem {
private:
	std::shared_ptr<CANTalon> wheel;
	std::shared_ptr<Talon> elevator;
	std::shared_ptr<CANTalon> roller;

public:
	Shooter();
	void InitDefaultCommand();
	void SetShooter(float power);
	void SetElevator(float power);
	void SetRoller(float power);
	float GetWheelRPM();
	float GetRollerRPM();
};

#endif  // Shooter_H
