#ifndef TestMotors_H
#define TestMotors_H

#include "WPILib.h"
#include <CANTalon.h>
#include "../../Robot.h"

class TestMotors : public frc::Command {
private:
	float m_voltage;
public:
	TestMotors(float voltage);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TestMotors_H
