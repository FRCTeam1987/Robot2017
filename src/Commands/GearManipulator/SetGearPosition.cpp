#include "SetGearPosition.h"

SetGearPosition::SetGearPosition(bool isRaised) {
	Requires(Robot::gearManipulator.get());
	m_isRaised = isRaised;
}

void SetGearPosition::Initialize() {
	Robot::gearManipulator.get()->SetGearPosition(m_isRaised);
}

void SetGearPosition::Execute() {
}

bool SetGearPosition::IsFinished() {
	return m_isRaised == true ?
			Robot::gearManipulator.get()->IsGearRaised() :
			Robot::gearManipulator.get()->IsGearLowered();
}

void SetGearPosition::End() {
}

void SetGearPosition::Interrupted() {
}
