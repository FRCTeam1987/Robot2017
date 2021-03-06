#ifndef SetCollector_H
#define SetCollector_H

#include "WPILib.h"
#include <CANTalon.h>
#include "../../Robot.h"

class SetCollector : public frc::Command {
private:
	float m_power;
	double m_time;
	bool m_isClockwise;
public:
	SetCollector(float power);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SetCollector_H
