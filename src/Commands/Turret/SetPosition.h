#ifndef SetPosition_H
#define SetPosition_H

#include "WPILib.h"
#include "../../Robot.h"

class SetPosition : public frc::Command {
private:
	double m_position;
public:
	SetPosition(double position);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SetPosition_H
