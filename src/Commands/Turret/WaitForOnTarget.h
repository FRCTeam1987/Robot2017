#ifndef WaitForOnTarget_H
#define WaitForOnTarget_H

#include "../../Robot.h"

class WaitForOnTarget : public frc::Command {
public:
	WaitForOnTarget();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // WaitForOnTarget_H
