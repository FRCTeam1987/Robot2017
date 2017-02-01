#ifndef StartRoller_H
#define StartRoller_H

#include "WPILib.h"
#include <CANTalon.h>
#include "../../Robot.h"

class StartRoller : public frc::Command{
private:
	float m_RPM;
public:
	StartRoller(float RollerRPM);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // StartRoller_H
