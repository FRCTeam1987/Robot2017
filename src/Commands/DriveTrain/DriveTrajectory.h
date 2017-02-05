#ifndef DriveTrajectory_H
#define DriveTrajectory_H

#include "WPILib.h"
#include <CANTalon.h>
#include <TrajectoryRunner.h>
#include "../../Robot.h"

class DriveTrajectory : public frc::Command {
private:
	TrajectoryRunner m_runner;
	double m_initialAngle;
public:
	DriveTrajectory(vector<Trajectory> path);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveTrajectory_H
