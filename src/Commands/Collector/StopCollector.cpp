#include "StopCollector.h"

StopCollector::StopCollector() {
	Requires(Robot::collector.get());
}

void StopCollector::Initialize() {
	Robot::collector.get()->StopRoller();
}

void StopCollector::Execute() {

}

bool StopCollector::IsFinished() {
	return true;
}

void StopCollector::End() {

}

void StopCollector::Interrupted() {

}
