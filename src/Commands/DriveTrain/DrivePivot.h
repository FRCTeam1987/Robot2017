#ifndef DrivePivot_H
#define DrivePivot_H

#include "WPILib.h"
#include <CANTalon.h>
#include "../../Robot.h"

class DrivePivot : public frc::Command {
private:
	bool m_isDec;
	double m_angle;
	double m_currentAngle;
public:
	DrivePivot(double angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DrivePivot_H
