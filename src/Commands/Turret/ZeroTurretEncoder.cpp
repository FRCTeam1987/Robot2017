#include "ZeroTurretEncoder.h"

ZeroTurretEncoder::ZeroTurretEncoder() {
	Requires(Robot::turret.get());
}

void ZeroTurretEncoder::Initialize() {
	Robot::turret.get()->ZeroPosition();
}

void ZeroTurretEncoder::Execute() {

}

bool ZeroTurretEncoder::IsFinished() {
	return true;
}

void ZeroTurretEncoder::End() {

}

void ZeroTurretEncoder::Interrupted() {

}
