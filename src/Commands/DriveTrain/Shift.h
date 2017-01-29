#ifndef Shift_H
#define Shift_H

#include "WPILib.h"
#include "../../Robot.h"

class Shift : public frc::Command {
private:
	bool m_gear;
public:
	Shift(bool isHighGear);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Shift_H
