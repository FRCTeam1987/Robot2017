#ifndef UpdateSmartDashboard_H
#define UpdateSmartDashboard_H

#include "WPILib.h"
#include <CANTalon.h>
#include "../../Robot.h"

class UpdateSmartDashboard : public frc::Command {
public:
	UpdateSmartDashboard();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // UpdateSmartDashboard_H
