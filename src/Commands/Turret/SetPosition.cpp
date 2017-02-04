#include "SetPosition.h"

SetPosition::SetPosition(double position) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::turret.get());
	m_position = position;
}

// Called just before this Command runs the first time
void SetPosition::Initialize() {
	Robot::turret.get()->SetPosition(m_position);
}

// Called repeatedly when this Command is scheduled to run
void SetPosition::Execute() {
	frc::SmartDashboard::PutNumber("Turret Position", Robot::turret.get()->GetPosition());
}

// Make this return true when this Command no longer needs to run execute()
bool SetPosition::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void SetPosition::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetPosition::Interrupted() {

}
