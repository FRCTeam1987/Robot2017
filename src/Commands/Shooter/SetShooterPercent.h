#ifndef SetShooterPercent_H
#define SetShooterPercent_H

#include "WPILib.h"
#include "../../Robot.h"

class SetShooterPercent : public frc::Command {
private:
	double m_percent;
public:
	SetShooterPercent(double percent);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SetShooterPercent_H
