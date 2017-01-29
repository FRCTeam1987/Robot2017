#ifndef StopCollector_H
#define StopCollector_H

#include "WPILib.h"
#include <CANTalon.h>
#include "../../Robot.h"

class StopCollector : public frc::Command {
public:
	StopCollector();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // StopCollector_H
