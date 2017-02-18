#include "AddToCurrentAngle.h"

AddToCurrentAngle::AddToCurrentAngle(double angleToAdd) {
	Requires(Robot::turret.get());
	m_angleToAdd = angleToAdd;
}

void AddToCurrentAngle::Initialize() {
	double currentAngle = Robot::turret.get()->GetAngle();
	double targetAngle = currentAngle + m_angleToAdd;
	Robot::turret.get()->SetPosition(targetAngle);

}

void AddToCurrentAngle::Execute() {

}

bool AddToCurrentAngle::IsFinished() {
	return (Robot::turret.get()->isOnTarget());
}

void AddToCurrentAngle::End() {

}

void AddToCurrentAngle::Interrupted() {

}
