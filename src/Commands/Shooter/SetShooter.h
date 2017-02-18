#ifndef SetShooter_H
#define SetShooter_H

#include "WPILib.h"
#include <CANTalon.h>
#include "../../Robot.h"

class SetShooter : public frc::Command {
private:
	float m_rpm;
	float m_tolerance;
public:
	SetShooter(float rpm);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SetShooter_H
