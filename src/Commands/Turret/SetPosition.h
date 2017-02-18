#ifndef SetPosition_H
#define SetPosition_H

#include "WPILib.h"
#include "../../Robot.h"

class SetPosition : public frc::Command {
private:
	double m_angle;
public:
	SetPosition(double angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SetPosition_H
