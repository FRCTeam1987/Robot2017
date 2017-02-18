#include "Collector.h"
#include "../RobotMap.h"
#include "../Commands/Collector/CollectFuel.h"

Collector::Collector() : Subsystem("Collector") {
	roller = RobotMap::collectorRoller;
	ballSensor = RobotMap::collectorBallSensor;
}

void Collector::InitDefaultCommand() {
	SetDefaultCommand(new CollectFuel());
}

void Collector::DisableDefaultCommand() {
	SetDefaultCommand(NULL);
}

bool Collector::HasBall() {
	return (!(ballSensor->Get()));
}

void Collector::SetRoller(float power) {

	roller->Set(power);
}

