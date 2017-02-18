#ifndef SetGearManipulatorRoller_H
#define SetGearManipulatorRoller_H

#include "WPILib.h"
#include "../../Robot.h"

class SetGearManipulatorRoller : public frc::Command {
private:
	float m_power;
public:
	SetGearManipulatorRoller(float power);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SetGearManipulatorRoller_H
