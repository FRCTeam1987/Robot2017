#ifndef SetGearManipulator_H
#define SetGearManipulator_H

#include "WPILib.h"
#include <CANTalon.h>
#include "../../Robot.h"

class SetGearManipulator : public frc::Command {
private:
	float m_power;
public:
	SetGearManipulator(float power);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SetGearManipulator_H
