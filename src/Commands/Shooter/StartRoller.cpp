#include "StartRoller.h"

StartRoller::StartRoller(float rollerRPM) {
	Requires(Robot::shooter.get());
	m_RPM = rollerRPM;
}

void StartRoller::Initialize() {
	Robot::shooter.get()->StartRoller(m_RPM);
}

void StartRoller::Execute() {

}

bool StartRoller::IsFinished() {
	return true;
}

void StartRoller::End() {

}

void StartRoller::Interrupted() {
	Robot::shooter.get()->StopRoller();
}
