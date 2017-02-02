#include "TestMotors.h"

TestMotors::TestMotors(float voltage) {
	Requires(Robot::driveTrain.get());
	m_voltage = voltage;
}

void TestMotors::Initialize() {
	Robot::driveTrain.get()->StartMotor(m_voltage);
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
