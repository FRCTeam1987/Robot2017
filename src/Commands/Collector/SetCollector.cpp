#include "SetCollector.h"

SetCollector::SetCollector(float power) {
	Requires(Robot::collector.get());
	m_power = power;
	m_time = 0;
	m_isClockwise = true;
}

void SetCollector::Initialize() {

	RobotMap::Log.AddEntry("SetCollector::Initialize()");

	Robot::collector.get()->SetRoller(m_power);
//	printf("collectorRunning\n");

	m_time = frc::Timer::GetFPGATimestamp();
	m_isClockwise = true;

}

void SetCollector::Execute() {

		if (m_isClockwise && frc::Timer::GetFPGATimestamp() - m_time > 1.5) {
			Robot::collector.get()->SetRoller(1);
			m_time = frc::Timer::GetFPGATimestamp();
			m_isClockwise = false;
		} else if (m_isClockwise == false && (frc::Timer::GetFPGATimestamp() - m_time > .1)) {
			Robot::collector.get()->SetRoller(m_power);

			printf("false\n");
			m_time = frc::Timer::GetFPGATimestamp();
			m_isClockwise = true;
		}

}

bool SetCollector::IsFinished() {
	if (m_power == 0) {
		return true;
	} else {
		return false;
	}
}

void SetCollector::End() {
	RobotMap::Log.AddEntry("SetCollector::End()");

}

void SetCollector::Interrupted() {
	Robot::collector.get()->SetRoller(0);
}
