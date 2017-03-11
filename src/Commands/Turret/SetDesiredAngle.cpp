#include "SetDesiredAngle.h"

SetDesiredAngle::SetDesiredAngle(double desiredAngle) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	m_desiredAngle = desiredAngle;
}

// Called just before this Command runs the first time
void SetDesiredAngle::Initialize() {
	RobotMap::Log.AddEntry("SetDesiredAngle::Initialize()");

	printf("Command_SetDesiredAngle(%f)\n", m_desiredAngle);
	Robot::turret->SetDesiredAngle(m_desiredAngle);
}

// Called repeatedly when this Command is scheduled to run
void SetDesiredAngle::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool SetDesiredAngle::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void SetDesiredAngle::End() {
	RobotMap::Log.AddEntry("SetDesiredAngle::End()");

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetDesiredAngle::Interrupted() {

}
