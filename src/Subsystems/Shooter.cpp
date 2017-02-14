#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter() : Subsystem("Shooter") {
	wheel = RobotMap::shooterWheel;
	elevator = RobotMap::shooterElevator;
	roller = RobotMap::shooterRoller;
}

void Shooter::InitDefaultCommand() {
}

void Shooter::SetShooter(float power){
	wheel->Set(-power);
}

void Shooter::SetElevator(float power){
	elevator->Set(power);
}

void Shooter::SetRoller(float power){
	roller->Set(-power);
}

float Shooter::GetWheelRPM(){
	return wheel->GetSpeed();
}

float Shooter::GetRollerRPM(){
	return roller->GetSpeed();
}
