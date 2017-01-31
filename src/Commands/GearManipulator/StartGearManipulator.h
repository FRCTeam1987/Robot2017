#ifndef StartGearManipulator_H
#define StartGearManipulator_H

#include "WPILib.h"
#include <CANTalon.h>
#include "../../Robot.h"

class StartGearManipulator : public frc::Command {
private:
	float m_speed;

public:
	StartGearManipulator(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // StartGearManipulator_H
