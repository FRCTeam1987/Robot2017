#ifndef StopGearManipulator_H
#define StopGearManipulator_H

#include "WPILib.h"
#include <CANTalon.h>
#include "../../Robot.h"

class StopGearManipulator : public frc::Command {
public:
	StopGearManipulator();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // StopGearManipulator_H
