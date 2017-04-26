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
	const double m_accRate = 0.15; //todo:needs to change
	const double m_maxSpeed = 1.0;
	const double m_decRate = .05;
	const double m_decRatio = 0.1/6; //todo:needs to change
public:
	DriveStraight(double distance, double initialSpeed, double finalSpeed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveStraight_H
