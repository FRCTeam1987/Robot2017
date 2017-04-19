#ifndef ToggleDefaultCommand_H
#define ToggleDefaultCommand_H

#include "../../Robot.h"
#include "CollectFuel.h"

class ToggleDefaultCommand : public frc::Command {
public:
	ToggleDefaultCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ToggleDefaultCommand_H
