#include "ZeroDriveTrain.h"

ZeroDriveTrain::ZeroDriveTrain() {
	Requires(Robot::driveTrain.get());
}

void ZeroDriveTrain::Initialize() {
	Robot::driveTrain.get()->ZeroAngle();
	Robot::driveTrain.get()->ZeroEncoders();
	RobotMap::Log.AddEntry("ZeroDriveTrain::Initialize()");

}

void ZeroDriveTrain::Execute() {

}

bool ZeroDriveTrain::IsFinished() {
	return true;
}

void ZeroDriveTrain::End() {
	RobotMap::Log.AddEntry("ZeroDriveTrain::End()");

}

void ZeroDriveTrain::Interrupted() {

}
