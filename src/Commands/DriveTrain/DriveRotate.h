#ifndef DriveRotate_H
#define DriveRotate_H

#include "../../Robot.h"
#include "WPILib.h"

class DriveRotate : public frc::Command {
private:
	float m_desiredAngle;
	const float m_tolerance = 1;
	float m_turnSpeed;
	bool m_isClockwise;
	const float m_turnSpeedInc = 0.025;
	float m_initialAngle;
	float m_minTurnSpeed;
	const float m_maxTurnSpeed = 0.6;
	const float m_isAlmostThereAngle = 5;
public:
	DriveRotate(float desiredAngle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	bool IsRotating();
	bool IsAlmostThere();
};

#endif  // DriveRotate_H
