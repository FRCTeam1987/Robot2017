#ifndef RunCollectorUntilNotTripped_H
#define RunCollectorUntilNotTripped_H

#include "WPILib.h"
#include "../../Robot.h"

class RunCollectorUntilNotTripped : public frc::Command {
private:
	float m_power;
	double m_lastTripped;
	double m_timeAfterTrip;
public:
	RunCollectorUntilNotTripped(float power);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // RunCollectorUntilNotTripped_H
