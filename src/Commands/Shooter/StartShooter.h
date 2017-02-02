#ifndef StartShooter_H
#define StartShooter_H

#include "WPILib.h"
#include <CANTalon.h>
#include "../../Robot.h"

class StartShooter : public frc::Command {
private:
	float m_RPM;
public:
	StartShooter(float wheelRPM);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // StartShooter_H
