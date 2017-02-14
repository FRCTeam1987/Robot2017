#include "ShowHasBall.h"

ShowHasBall::ShowHasBall() {
	Requires(Robot::collector.get());
}

void ShowHasBall::Initialize() {

}

void ShowHasBall::Execute() {
	frc::SmartDashboard::PutNumber("Has Ball Sensor", Robot::collector.get()->HasBall());
}

bool ShowHasBall::IsFinished() {
	return false;
}

void ShowHasBall::End() {

}

void ShowHasBall::Interrupted() {

}
