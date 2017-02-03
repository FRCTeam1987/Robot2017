#include "Collector.h"
#include "../RobotMap.h"
#include "../Commands/Collector/SetCollector.h"

Collector::Collector() : Subsystem("Collector") {
	roller = RobotMap::collectorRoller;
	ballSensor = RobotMap::collectorBallSensor;
}

void Collector::InitDefaultCommand() {
	SetDefaultCommand(new SetCollector(0.25));
}

bool Collector::HasBall() {
	return ballSensor->Get();
}

void Collector::SetRoller(float power) {
	roller->Set(power);
}
