#ifndef StopRoller_H
#define StopRoller_H

#include "WPILib.h"
#include <CANTalon.h>
#include "../../Robot.h"

class StopRoller : public frc::Command {
public:
	StopRoller();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // StopRoller_H
