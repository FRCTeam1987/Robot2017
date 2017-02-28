#ifndef AutoTarget_H
#define AutoTarget_H

#include "../../Robot.h"
#include "../../Lib/TimeStampedHistory.h"


class AutoTarget : public frc::Command {
public:
	AutoTarget();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoTarget_H
