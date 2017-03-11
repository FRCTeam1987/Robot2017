#ifndef ShootDistance_H
#define ShootDistance_H

#include "../../Robot.h"

class ShootDistance : public frc::Command {
private:
	double m_distance;
	std::map<int, double> m_distanceToRpm;
	double m_shooterRpm;
	double m_tolerance;
public:
	ShootDistance();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ShootDistance_H
