#include "ZeroTurretEncoder.h"

ZeroTurretEncoder::ZeroTurretEncoder() {
}

void ZeroTurretEncoder::Initialize() {
	Robot::turret.get()->ZeroPosition();
	RobotMap::Log.AddEntry("ZeroTurretEncoder::Initialize()");

}

void ZeroTurretEncoder::Execute() {

}

bool ZeroTurretEncoder::IsFinished() {
	return true;
}

void ZeroTurretEncoder::End() {
	RobotMap::Log.AddEntry("ZeroTurretEncoder::End()");
}

void ZeroTurretEncoder::Interrupted() {

}
