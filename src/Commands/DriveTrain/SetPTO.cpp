#include "SetPTO.h"

SetPTO::SetPTO(bool isEnabled) {
	Requires(Robot::driveTrain.get());
	m_isEnabled = isEnabled;
}

void SetPTO::Initialize() {
	Robot::driveTrain.get()->SetPTO(m_isEnabled);
}

void SetPTO::Execute() {
}

bool SetPTO::IsFinished() {
	return true;
}

void SetPTO::End() {
}

void SetPTO::Interrupted() {
	Robot::driveTrain.get()->SetPTO(false);
}
