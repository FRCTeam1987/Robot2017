#ifndef Vision_H
#define Vision_H

#include <Commands/Subsystem.h>

#include "../Lib/TimeStampedHistory.h"

class Vision : public Subsystem {
private:
	double m_angleToTarget;
	double m_distanceToTarget;
	double m_isTargetVisible;
	double m_timeStamp;
	double m_computeTime;
public:
	Vision();
	void InitDefaultCommand();
	void UpdateInfo();
	TimeStampedValue GetInfo();
	void DisableDefaultCommand();
};

#endif  // Vision_H
