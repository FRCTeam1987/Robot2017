#ifndef ZeroDriveTrain_H
#define ZeroDriveTrain_H

#include "WPILib.h"
#include <CANTalon.h>
#include "../../Robot.h"

class ZeroDriveTrain : public frc::Command {
public:
	ZeroDriveTrain();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ZeroDriveTrain_H
