#ifndef StartCollector_H
#define StartCollector_H

#include "WPILib.h"
#include <CANTalon.h>
#include "../../Robot.h"

class StartCollector : public frc::Command {
public:
	StartCollector();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // StartCollector_H
