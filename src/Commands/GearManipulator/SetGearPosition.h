#ifndef SetGearPosition_H
#define SetGearPosition_H

#include "WPILib.h"
#include <CANTalon.h>
#include "../../Robot.h"

class SetGearPosition : public frc::Command {
private:
	bool m_isRaised;

public:
	SetGearPosition(bool isRaised);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SetGearPosition_H
