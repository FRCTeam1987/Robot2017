#ifndef AutoTarget_H
#define AutoTarget_H

#include "../../Robot.h"
#include "../../Lib/TimeStampedHistory.h"


class AutoTarget : public frc::Command {
private:
	double m_anchorPoint;
	double m_angleToGoal;
	double m_lastTimeStamp;
	double m_lastGoalAngle;
public:
	AutoTarget();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void AnchorTurret();
};

#endif  // AutoTarget_H
