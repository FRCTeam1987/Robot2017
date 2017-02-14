#include "SetTurretPercent.h"

SetTurretPercent::SetTurretPercent(float percent) {
	Requires(Robot::turret.get());
	m_percent = percent;
}

void SetTurretPercent::Initialize() {
	Robot::turret.get()->SetVoltage(m_percent);
}

void SetTurretPercent::Execute() {

}

bool SetTurretPercent::IsFinished() {
	return true;
}

void SetTurretPercent::End() {

}

void SetTurretPercent::Interrupted() {
	Robot::turret.get()->SetVoltage(0);
}
