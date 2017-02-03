#include "SetGearManipulator.h"

SetGearManipulator::SetGearManipulator(float power) {
	Requires(Robot::gearManipulator.get());
	m_power = power;
}

void SetGearManipulator::Initialize() {
	Robot::gearManipulator.get()->SetRoller(m_power);
}

void SetGearManipulator::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool SetGearManipulator::IsFinished() {
	return true;
}

void SetGearManipulator::End() {
}

void SetGearManipulator::Interrupted() {
	Robot::gearManipulator.get()->SetRoller(m_power);
}
