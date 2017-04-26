#ifndef ToggleFlashlight_H
#define ToggleFlashlight_H

#include "../../Robot.h"
#include "WPILib.h"

class ToggleFlashlight : public frc::Command {
public:
	ToggleFlashlight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ToggleFlashlight_H
