#ifndef DrivePivot2_H
#define DrivePivot2_H

#include "WPILib.h"
#include "../../Robot.h"

class DrivePivot2 : public frc::Command {
public:
	DrivePivot2();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DrivePivot2_H
