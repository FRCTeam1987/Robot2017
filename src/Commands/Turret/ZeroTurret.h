#ifndef ZeroTurret_H
#define ZeroTurret_H

#include "WPILib.h"
#include "../../Robot.h"

class ZeroTurret : public frc::Command {
private:
	bool m_isAtLimit;
	double m_voltage;
public:
	ZeroTurret(double voltage);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ZeroTurret_H
