#include "GearManipulator.h"
#include "../RobotMap.h"

GearManipulator::GearManipulator() : Subsystem("GearManipulator") {
	roller = RobotMap::gearRoller;
	gearSensor = RobotMap::gearSensor;
	lift = RobotMap::gearLift;
	gearRaisedSensor = RobotMap::gearPositionRaised;
	gearLoweredSensor = RobotMap::gearPositionLowered;
}

void GearManipulator::InitDefaultCommand() {
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

void GearManipulator::SetGearPosition(bool isRaised) {
	lift->Set(isRaised);
}

void GearManipulator::StartRoller(float speed) {
	roller->Set(speed);
}

void GearManipulator::StopRoller() {
	roller->Set(0);
}
