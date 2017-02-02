#include "Collector.h"
#include "../RobotMap.h"
#include "../Commands/Collector/StartCollector.h"

Collector::Collector() : Subsystem("Collector") {
	roller = RobotMap::collectorRoller;
	ballSensor = RobotMap::collectorBallSensor;
}

void Collector::InitDefaultCommand() {
	SetDefaultCommand(new StartCollector());
}

bool Collector::HasBall() {
	return ballSensor->Get();
}

void Collector::StartRoller() {
	roller->Set(.5);
}

void Collector::StopRoller() {
	roller->Set(0);
}
