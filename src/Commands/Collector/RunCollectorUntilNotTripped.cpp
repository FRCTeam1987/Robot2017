#include "RunCollectorUntilNotTripped.h"
#include "Timer.h"

RunCollectorUntilNotTripped::RunCollectorUntilNotTripped(float power) {
	Requires(Robot::collector.get());
	m_power = power;
	m_lastTripped = 0.0;
	m_timeAfterTrip = .5;
}

void RunCollectorUntilNotTripped::Initialize() {
	Robot::collector.get()->SetRoller(m_power);
}

void RunCollectorUntilNotTripped::Execute() {
	if (Robot::collector->HasBall()) {
		m_lastTripped = Timer::GetFPGATimestamp();
	}
}

bool RunCollectorUntilNotTripped::IsFinished() {
	return (m_lastTripped < (Timer::GetFPGATimestamp() - m_timeAfterTrip));
}

void RunCollectorUntilNotTripped::End() {
	Robot::collector.get()->SetRoller(0);
}

void RunCollectorUntilNotTripped::Interrupted() {
	Robot::collector.get()->SetRoller(0);
}
