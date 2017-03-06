#ifndef DriveArcPower_H
#define DriveArcPower_H

#include "../../Robot.h"

class DriveArcPower : public frc::Command {
private:
	bool m_isCw;
	double m_distance;
public:
	DriveArcPower(bool isCw, double distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveArcPower_H
