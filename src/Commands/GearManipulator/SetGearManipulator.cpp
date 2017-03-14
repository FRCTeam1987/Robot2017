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

bool SetGearManipulator::IsFinished() {
	return Robot::gearManipulator.get()->HasGear();
}

void SetGearManipulator::End() {

	Robot::gearManipulator.get()->SetRoller(0);
}

void SetGearManipulator::Interrupted() {
	Robot::gearManipulator.get()->SetRoller(0);
}
