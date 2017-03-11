#include "AddToCurrentAngle.h"

AddToCurrentAngle::AddToCurrentAngle(double angleToAdd) {
	m_angleToAdd = angleToAdd;
}

void AddToCurrentAngle::Initialize() {
	double currentTargetAngle = Robot::turret->GetDesiredAngle();
	Robot::turret->SetDesiredAngle(m_angleToAdd + currentTargetAngle);
}

void AddToCurrentAngle::Execute() {

}

bool AddToCurrentAngle::IsFinished() {
	return true;
}

void AddToCurrentAngle::End() {

}

void AddToCurrentAngle::Interrupted() {

}
