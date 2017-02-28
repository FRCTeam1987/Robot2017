#include "RunCollectorUntilNotTripped.h"

RunCollectorUntilNotTripped::RunCollectorUntilNotTripped(float power) {
	m_power = power;
	Requires(Robot::collector.get());
}

void RunCollectorUntilNotTripped::Initialize() {
	Robot::collector.get()->SetRoller(m_power);
}

void RunCollectorUntilNotTripped::Execute() {

}

bool RunCollectorUntilNotTripped::IsFinished() {
	return !(Robot::collector.get()->HasBall());
}

void RunCollectorUntilNotTripped::End() {
	Robot::collector.get()->SetRoller(0);
}

void RunCollectorUntilNotTripped::Interrupted() {
	Robot::collector.get()->SetRoller(0);
}
