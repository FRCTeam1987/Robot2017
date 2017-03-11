#include "WaitForOnTarget.h"

WaitForOnTarget::WaitForOnTarget() {
}

void WaitForOnTarget::Initialize() {

}

void WaitForOnTarget::Execute() {

}

bool WaitForOnTarget::IsFinished() {
	return Robot::turret->isStill();
}

void WaitForOnTarget::End() {
	printf("ON TARGET");
}

void WaitForOnTarget::Interrupted() {

}
