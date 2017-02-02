#include "ClimbToPlate.h"

ClimbToPlate::ClimbToPlate(float voltage) {
	Requires(Robot::driveTrain.get());
	m_voltage = voltage;
}

void ClimbToPlate::Initialize() {
	Robot::driveTrain.get()->StartMotor(m_voltage);
}

void ClimbToPlate::Execute() {
}

bool ClimbToPlate::IsFinished() {
	return Robot::driveTrain.get()->IsTouchingPlate();
}

void ClimbToPlate::End() {
	Robot::driveTrain.get()->StopMotor();
}

void ClimbToPlate::Interrupted() {
	Robot::driveTrain.get()->StopMotor();
}
