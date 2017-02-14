#include "AutoRunCollector.h"

AutoRunCollector::AutoRunCollector() {
	Requires(Robot::collector.get());
}

void AutoRunCollector::Initialize() {

}

void AutoRunCollector::Execute() {
	if (Robot::collector.get()->HasBall()) {
		Robot::collector.get()->SetRoller(0.9);
	}
	else {
		Wait(0.25);
		Robot::collector.get()->SetRoller(0.0);
	}
}

bool AutoRunCollector::IsFinished() {

	return false;
}

void AutoRunCollector::End() {

}

void AutoRunCollector::Interrupted() {
	Robot::collector.get()->SetRoller(0.0);
}
