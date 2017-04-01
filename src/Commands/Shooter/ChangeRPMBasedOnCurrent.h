#ifndef ChangeRPMBasedOnCurrent_H
#define ChangeRPMBasedOnCurrent_H

#include "../../Robot.h"

class ChangeRPMBasedOnCurrent : public frc::Command {
private:
	double m_rpmToAdd;
	double m_currentRpm;
	double m_targetRpm;
	double m_tolerance;
public:
	ChangeRPMBasedOnCurrent(double RPMToAdd);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ChangeRPMBasedOnCurrent_H
