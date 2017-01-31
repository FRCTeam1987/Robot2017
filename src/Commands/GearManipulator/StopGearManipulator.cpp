#include "StopGearManipulator.h"

StopGearManipulator::StopGearManipulator() {
	Requires(Robot::gearManipulator.get());
}

void StopGearManipulator::Initialize() {
}

void StopGearManipulator::Execute() {
}

bool StopGearManipulator::IsFinished() {
	return true;
}

void StopGearManipulator::End() {
	Robot::gearManipulator.get()->StopRoller();
}

void StopGearManipulator::Interrupted() {
	Robot::gearManipulator.get()->StopRoller();
}
