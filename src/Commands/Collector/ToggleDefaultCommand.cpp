#include "ToggleDefaultCommand.h"

ToggleDefaultCommand::ToggleDefaultCommand() {
	Requires(Robot::collector.get());

}

void ToggleDefaultCommand::Initialize() {
	//if used while elevator is running must run a stop all command to stop the elevator
	Robot::collector.get()->ToggleDefault();
}

void ToggleDefaultCommand::Execute() {

}

bool ToggleDefaultCommand::IsFinished() {
	return true;
}

void ToggleDefaultCommand::End() {

}

void ToggleDefaultCommand::Interrupted() {

}
