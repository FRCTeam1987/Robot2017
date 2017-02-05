#ifndef DriveStraight_H
#define DriveStraight_H

#include "WPILib.h"
#include <CANTalon.h>
#include <TrajectoryRunner.h>
#include "../../Robot.h"

class DriveStraight : public frc::Command {
private:
	double m_speed;
	float m_angleSetpoint;
	double m_distance;
public:
	DriveStraight(double speed, float angleSetpoint, double distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveStraight_H
