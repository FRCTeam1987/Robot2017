#ifndef StopShooter_H
#define StopShooter_H

#include "WPILib.h"
#include <CANTalon.h>
#include "../../Robot.h"

class StopShooter : public frc::Command {
public:
	StopShooter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // StopShooter_H
