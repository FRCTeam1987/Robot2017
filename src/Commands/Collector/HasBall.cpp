#include "HasBall.h"

HasBall::HasBall() {
	Requires(Robot::collector.get());
}

void HasBall::Initialize() {

}

void HasBall::Execute() {

}

bool HasBall::IsFinished() {
	return Robot::collector.get()->HasBall();
}

void HasBall::End() {

}

void HasBall::Interrupted() {

}
