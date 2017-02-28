#ifndef DriveArcPower_H
#define DriveArcPower_H

#include "../../Robot.h"

class DriveArcPower : public frc::Command {
private:
	bool m_isCw;
public:
	DriveArcPower(bool isCw);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveArcPower_H
