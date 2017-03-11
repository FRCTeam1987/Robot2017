#include "SetCollectorDefaultCommand.h"
#include "CollectFuel.h"


SetCollectorDefaultCommand::SetCollectorDefaultCommand(bool setOnOff) {
	Requires(Robot::collector.get());
	m_setOnOff = setOnOff;
}

void SetCollectorDefaultCommand::Initialize() {
	RobotMap::Log.AddEntry("SetCollectorDefaultCommand::Initialize()");

	if (m_setOnOff) {
		Robot::collector.get()->SetDefaultCommand(new CollectFuel());
	} else {
		Robot::collector.get()->DisableDefaultCommand();
	}
}

void SetCollectorDefaultCommand::Execute() {

}

bool SetCollectorDefaultCommand::IsFinished() {
	return true;
}

void SetCollectorDefaultCommand::End() {
	RobotMap::Log.AddEntry("SetCollectorDefaultCommand::End()");


}

void SetCollectorDefaultCommand::Interrupted() {

}
