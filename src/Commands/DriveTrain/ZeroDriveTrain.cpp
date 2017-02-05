#include "ZeroDriveTrain.h"

ZeroDriveTrain::ZeroDriveTrain() {
	Requires(Robot::driveTrain.get());
}

void ZeroDriveTrain::Initialize() {
	Robot::driveTrain.get()->ZeroAngle();
	Robot::driveTrain.get()->ZeroEncoders();
}

void ZeroDriveTrain::Execute() {

}

bool ZeroDriveTrain::IsFinished() {
	return true;
}

void ZeroDriveTrain::End() {

}

void ZeroDriveTrain::Interrupted() {

}
