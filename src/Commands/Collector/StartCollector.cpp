#include "StartCollector.h"

StartCollector::StartCollector() {
	Requires(Robot::collector.get());
}

void StartCollector::Initialize() {
	Robot::collector.get()->StartRoller();
}

void StartCollector::Execute() {

}

bool StartCollector::IsFinished() {
	return true;
}

void StartCollector::End() {

}

void StartCollector::Interrupted() {

}
