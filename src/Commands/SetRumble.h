#ifndef SetRumble_H
#define SetRumble_H

#include "../Robot.h"

class SetRumble : public frc::Command {
private:
	double m_power;
public:
	SetRumble(double power);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SetRumble_H
