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

bool GearManipulator::HasGear() {
	return !gearSensor->Get(); //TODO inverted for comp bot
}

bool GearManipulator::IsGearLowered() {
	return gearLoweredSensor->Get();
}

bool GearManipulator::IsGearRaised() {
	return gearRaisedSensor->Get();
}

void GearManipulator::SetGearPosition(bool isRaised) {
	if (isRaised)
		lift->Set(frc::DoubleSolenoid::kReverse);
	else
		lift->Set(frc::DoubleSolenoid::kForward);
}

void GearManipulator::SetRoller(float power) {
	roller->Set(-power);
}
