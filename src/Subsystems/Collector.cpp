#include "Collector.h"
#include "../RobotMap.h"

Collector::Collector() : Subsystem("Collector") {
	collectorMotor = RobotMap::collectorRoller;
}

void Collector::InitDefaultCommand() {

}

void Collector::StartRoller() {
	collectorMotor->Set(.5);
}

void Collector::StopRoller() {
	collectorMotor->Set(0);
}
