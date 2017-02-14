#ifndef AutoRunCollector_H
#define AutoRunCollector_H

#include "WPILib.h"
#include "../../Robot.h"

class AutoRunCollector : public frc::Command {
public:
	AutoRunCollector();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoRunCollector_H
