#include "TestMotors.h"

TestMotors::TestMotors() {
	Requires(Robot::driveTrain.get());
}

void TestMotors::Initialize() {
	Robot::driveTrain.get()->StartMotor();
}

void TestMotors::Execute() {
}

bool TestMotors::IsFinished() {
	return true;
}

void TestMotors::End() {
}

void TestMotors::Interrupted() {
}
