#ifndef SetRoller_H
#define SetRoller_H

#include "WPILib.h"
#include <CANTalon.h>
#include "../../Robot.h"

class SetRoller : public frc::Command {
private:
	float m_power;
public:
	SetRoller(float power);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SetRoller_H
