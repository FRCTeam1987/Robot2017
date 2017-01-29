#include "Shift.h"

Shift::Shift(bool isHighGear) {
	Requires(Robot::driveTrain.get());
	m_gear = isHighGear;
}

void Shift::Initialize() {
	Robot::driveTrain.get()->Shift(m_gear);
}

void Shift::Execute() {
}

bool Shift::IsFinished() {
	return true;
}

void Shift::End() {
}

void Shift::Interrupted() {
}
