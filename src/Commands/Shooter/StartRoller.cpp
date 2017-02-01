#include "StartRoller.h"

StartRoller::StartRoller(float RollerRPM) {
	Requires(Robot::shooter.get());
	m_RPM = RollerRPM;
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
