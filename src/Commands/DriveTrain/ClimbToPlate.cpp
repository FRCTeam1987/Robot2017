#include "ClimbToPlate.h"

ClimbToPlate::ClimbToPlate(float power) {
	Requires(Robot::driveTrain.get());
	m_power = power;
}

void ClimbToPlate::Initialize() {
	Robot::driveTrain.get()->DriveTank(m_power, m_power);
}

void ClimbToPlate::Execute() {
}

bool ClimbToPlate::IsFinished() {
	return Robot::driveTrain.get()->IsTouchingPlate();
}

void ClimbToPlate::End() {
	Robot::driveTrain.get()->DriveTank(0, 0);
}

void ClimbToPlate::Interrupted() {
	Robot::driveTrain.get()->DriveTank(0, 0);
}
