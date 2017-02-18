#ifndef AddToCurrentAngle_H
#define AddToCurrentAngle_H

#include "../../Robot.h"

class AddToCurrentAngle : public frc::Command {
private:
	double m_angleToAdd;
public:
	AddToCurrentAngle(double angleToAdd);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AddToCurrentAngle_H
