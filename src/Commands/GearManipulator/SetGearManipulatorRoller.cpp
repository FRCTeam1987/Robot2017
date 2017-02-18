#include "SetGearManipulatorRoller.h"

SetGearManipulatorRoller::SetGearManipulatorRoller(float power) {
	Requires(Robot::gearManipulator.get());
	m_power = power;
}

// Called just before this Command runs the first time
void SetGearManipulatorRoller::Initialize() {
	Robot::gearManipulator.get()->SetRoller(m_power);
}

// Called repeatedly when this Command is scheduled to run
void SetGearManipulatorRoller::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool SetGearManipulatorRoller::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void SetGearManipulatorRoller::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetGearManipulatorRoller::Interrupted() {
	Robot::gearManipulator.get()->SetRoller(0);
}
