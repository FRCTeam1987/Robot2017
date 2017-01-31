#include "StartCollector.h"

StartCollector::StartCollector() {
	Requires(Robot::collector.get());
}

void StartCollector::Initialize() {
	if (!Robot::collector.get()->HasBall()){
		Robot::collector.get()->StartRoller();
	}
}

void StartCollector::Execute() {

}

bool StartCollector::IsFinished() {
	return (Robot::collector.get()->HasBall());
}

void StartCollector::End() {
	Robot::collector.get()->StopRoller();
}

void StartCollector::Interrupted() {

}
