#include "StartGearManipulator.h"

StartGearManipulator::StartGearManipulator(float speed) {
	Requires(Robot::gearManipulator.get());
	m_speed = speed;
}

void StartGearManipulator::Initialize() {
	if (!Robot::gearManipulator.get()->HasGear()) {
		Robot::gearManipulator.get()->StartRoller(m_speed);
	}
}

void StartGearManipulator::Execute() {
}

bool StartGearManipulator::IsFinished() {
	return (Robot::gearManipulator.get()->HasGear());
}

void StartGearManipulator::End() {
	Robot::gearManipulator.get()->StopRoller();
}

void StartGearManipulator::Interrupted() {
	Robot::gearManipulator.get()->StopRoller();
}
