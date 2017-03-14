#include "SetVisionDefaultCommand.h"
#include "VisionUpdateTurret.h"

SetVisionDefaultCommand::SetVisionDefaultCommand(bool setOnOff) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	m_onOff = setOnOff;
}

// Called just before this Command runs the first time
void SetVisionDefaultCommand::Initialize() {

	if (m_onOff) {
		Robot::vision.get()->SetDefaultCommand(new VisionUpdateTurret());
	} else {
		Robot::vision.get()->DisableDefaultCommand();
	}
}

// Called repeatedly when this Command is scheduled to run
void SetVisionDefaultCommand::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool SetVisionDefaultCommand::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void SetVisionDefaultCommand::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetVisionDefaultCommand::Interrupted() {

}
