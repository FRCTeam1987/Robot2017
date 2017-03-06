#ifndef VisionUpdateTurret_H
#define VisionUpdateTurret_H

#include "WPILib.h"
#include "../../Robot.h"

class VisionUpdateTurret : public frc::Command {
private:
	double m_lastTimeStamp;
public:
	VisionUpdateTurret();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // VisionUpdateTurret_H
