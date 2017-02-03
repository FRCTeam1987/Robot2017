#ifndef SetElevator_H
#define SetElevator_H

#include "WPILib.h"
#include <CANTalon.h>
#include "../../Robot.h"

class SetElevator : public frc::Command {
private:
	float m_power;
public:
	SetElevator(float power);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SetElevator_H
