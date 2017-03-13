#ifndef TogglePTO_H
#define TogglePTO_H

#include "../../Robot.h"

class TogglePTO : public frc::Command {
public:
	TogglePTO();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TogglePTO_H
