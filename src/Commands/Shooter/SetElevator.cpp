#include "SetElevator.h"

SetElevator::SetElevator(float power) {
	Requires(Robot::shooter.get());
	m_power = power;
}

void SetElevator::Initialize() {
	RobotMap::Log.AddEntry("SetElevator::Initialize()");

	Robot::shooter.get()->SetElevator(m_power);
	printf("elevatorRunning\n");

}

void SetElevator::Execute() {
}

bool SetElevator::IsFinished() {
	return true;
}

void SetElevator::End() {
	RobotMap::Log.AddEntry("SetElevator::End()");

}

void SetElevator::Interrupted() {
	Robot::shooter.get()->SetElevator(0);
}
