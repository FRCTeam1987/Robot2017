#ifndef StartElevator_H
#define StartElevator_H

#include "WPILib.h"
#include <CANTalon.h>
#include "../../Robot.h"

class StartElevator : public frc::Command{
private:
	float m_speed;
public:
	StartElevator(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // StartElevator_H
