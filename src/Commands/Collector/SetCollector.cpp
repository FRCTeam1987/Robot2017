#include "SetCollector.h"

SetCollector::SetCollector(float power) {
	Requires(Robot::collector.get());
	m_power = power;
}

void SetCollector::Initialize() {
	RobotMap::Log.AddEntry("SetCollector::Initialize()");

	Robot::collector.get()->SetRoller(m_power);
	printf("collectorRunning\n");

}

void SetCollector::Execute() {
}

bool SetCollector::IsFinished() {
	return true;
}

void SetCollector::End() {
	RobotMap::Log.AddEntry("SetCollector::End()");

}

void SetCollector::Interrupted() {
	Robot::collector.get()->SetRoller(0);
}
