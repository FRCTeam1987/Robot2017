#ifndef SetDesiredAngle_H
#define SetDesiredAngle_H

#include "../../Robot.h"

class SetDesiredAngle : public frc::Command {
private:
	double m_desiredAngle;
public:
	SetDesiredAngle(double desiredAngle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SetDesiredAngle_H
