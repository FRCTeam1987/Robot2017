#ifndef DriveArc_H
#define DriveArc_H

#include "WPILib.h"
#include <CANTalon.h>
#include "../../Robot.h"

class DriveArc : public frc::Command {
private:
	double m_initialSpeed;
	double m_finalSpeed;
	double m_radius;
	double m_angle;
	double m_currentSpeed;
	double m_leftRadius;
	double m_rightRadius;
	double m_leftDistance;
	double m_rightDistance;
	double m_distance;
	double m_currentAngle;
	bool m_isDec;
	const double m_accRate = 0.1; //todo:needs to change
	const double m_maxSpeed = 0.95;
	const double m_decRatio = .2; //todo:needs to change
	const double m_robotWidth = 25.25;
public:
	DriveArc(double initialSpeed, double finalSpeed, double radius, double angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveArc_H
