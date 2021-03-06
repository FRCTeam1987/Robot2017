#ifndef ClimbToPlate_H
#define ClimbToPlate_H

#include "WPILib.h"
#include <CANTalon.h>
#include "../../Robot.h"

class ClimbToPlate : public frc::Command {
private:
	float m_power;
public:
	ClimbToPlate(float power);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ClimbToPlate_H
