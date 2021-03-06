#include "SetShooterPercent.h"

SetShooterPercent::SetShooterPercent(double percent) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::shooter.get());
	m_percent = percent;
}

// Called just before this Command runs the first time
void SetShooterPercent::Initialize() {
	Robot::shooter.get()->SetShooter(m_percent);
}

// Called repeatedly when this Command is scheduled to run
void SetShooterPercent::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool SetShooterPercent::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void SetShooterPercent::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetShooterPercent::Interrupted() {

}
