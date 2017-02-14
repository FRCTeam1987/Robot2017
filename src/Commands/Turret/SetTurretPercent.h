#ifndef SetTurretPercent_H
#define SetTurretPercent_H

#include "WPILib.h"
#include "../../Robot.h"

class SetTurretPercent : public frc::Command {
private:
	float m_percent;
public:
	SetTurretPercent(float percent);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SetTurretPercent_H
