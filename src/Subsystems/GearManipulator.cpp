#include "GearManipulator.h"
#include "../RobotMap.h"

GearManipulator::GearManipulator() : Subsystem("GearManipulator") {
	roller = RobotMap::gearRoller;
	gearSensor = RobotMap::gearSensor;
	gearRaisedSensor = RobotMap::gearPositionRaised;
	gearLoweredSensor = RobotMap::gearPositionLowered;
	lift = RobotMap::gearLift;
}

void GearManipulator::InitDefaultCommand() {
}

void GearManipulator::SetRoller(float power) {
	roller->Set(power);
}

void GearManipulator::SetGearPosition(bool isRaised) {
	lift->Set(isRaised);
}

bool GearManipulator::HasGear() {
	return gearSensor->Get();
}

bool GearManipulator::IsGearLowered() {
	return gearLoweredSensor->Get();
}

bool GearManipulator::IsGearRaised() {
	return gearRaisedSensor->Get();
}
