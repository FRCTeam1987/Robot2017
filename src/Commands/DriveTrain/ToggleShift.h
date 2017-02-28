#ifndef ToggleShift_H
#define ToggleShift_H

#include "../../Robot.h"

class ToggleShift : public frc::Command {
public:
	ToggleShift();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ToggleShift_H
