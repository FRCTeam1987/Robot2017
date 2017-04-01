#include "ChangeRPMBasedOnCurrent.h"

ChangeRPMBasedOnCurrent::ChangeRPMBasedOnCurrent(double RPMToAdd) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::shooter.get());
	m_currentRpm = 0;
	m_rpmToAdd = RPMToAdd;
	m_targetRpm = 0;
	m_tolerance = 10;
}

// Called just before this Command runs the first time
void ChangeRPMBasedOnCurrent::Initialize() {
	m_currentRpm = Robot::shooter->GetCurrentRpm();
	 m_targetRpm= m_currentRpm + m_rpmToAdd;

	Robot::shooter->SetShooterRpm(m_targetRpm);
}

// Called repeatedly when this Command is scheduled to run
void ChangeRPMBasedOnCurrent::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ChangeRPMBasedOnCurrent::IsFinished() {
	return fabs(fabs(Robot::shooter.get()->GetWheelRPM()) - fabs(m_targetRpm)) <= m_tolerance;
}

// Called once after isFinished returns true
void ChangeRPMBasedOnCurrent::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ChangeRPMBasedOnCurrent::Interrupted() {

}
