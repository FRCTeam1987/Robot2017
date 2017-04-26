#include "ToggleFlashlight.h"

ToggleFlashlight::ToggleFlashlight() {
	Requires(Robot::driveTrain.get());
}

void ToggleFlashlight::Initialize() {
	Robot::driveTrain.get()->ToggleFlashlight();
}

void ToggleFlashlight::Execute() {

}

bool ToggleFlashlight::IsFinished() {
	return true;
}

void ToggleFlashlight::End() {
}

void ToggleFlashlight::Interrupted() {
}
