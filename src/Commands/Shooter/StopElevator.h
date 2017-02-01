#ifndef StopElevator_H
#define StopElevator_H

#include "WPILib.h"
#include <CANTalon.h>
#include "../../Robot.h"

class StopElevator : public frc::Command {
public:
	StopElevator();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // StopElevator_H
