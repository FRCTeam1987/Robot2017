#ifndef DriveStraight_H
#define DriveStraight_H

#include "WPILib.h"
#include <CANTalon.h>
#include "../../Robot.h"

class DriveStraight : public frc::Command {
private:
	double m_distance;
	double m_currentSpeed;
	double m_initialSpeed;
	double m_finalSpeed;
	bool m_isDec;
	const double m_accRate = 0.1; //todo:needs to change
	const double m_maxSpeed = 0.95;
	const double m_decRatio = .2; //todo:needs to change
public:
	DriveStraight(double distance, double initialSpeed, double finalSpeed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveStraight_H
