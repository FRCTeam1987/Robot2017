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
public:
	Vision();
	void InitDefaultCommand();
	void UpdateInfo();
	TimeStampedValue GetInfo();
};

#endif  // Vision_H