#include "SetCollector.h"

SetCollector::SetCollector(float power) {
	Requires(Robot::collector.get());
	m_power = power;
}

void SetCollector::Initialize() {
	Robot::collector.get()->SetRoller(m_power);
}

void SetCollector::Execute() {
}

bool SetCollector::IsFinished() {
	return true;
}

void SetCollector::End() {
}

void SetCollector::Interrupted() {
	Robot::collector.get()->SetRoller(0);
}
