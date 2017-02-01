#ifndef Shooter_H
#define Shooter_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>
#include "WPILIB.h"

class Shooter : public frc::Subsystem {
private:
	std::shared_ptr<CANTalon> wheel;
	std::shared_ptr<CANTalon> elevator;
	std::shared_ptr<CANTalon> roller;

public:
	Shooter();
	void InitDefaultCommand();
	void StartShooter(float RPM);
	void StopShooter();
	void StartElevator(float speed);
	void StopElevator();
	void StartRoller(float RPM);
	void StopRoller();
	float GetWheelRPM();
	float GetRollerRPM();
};

#endif  // Shooter_H
