#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter() : Subsystem("Shooter") {
	wheel = RobotMap::shooterWheel;
	elevator = RobotMap::shooterElevator;
	roller = RobotMap::shooterRoller;
}

void Shooter::InitDefaultCommand() {
}

void Shooter::StartShooter(float wheelRPM){
	wheel->Set(wheelRPM);
}

void Shooter::StopShooter(){
	wheel->Set(0);
}

void Shooter::StartElevator(float speed){
	elevator->Set(speed);
}

void Shooter::StopElevator(){
	elevator->Set(0);
}

void Shooter::StartRoller(float rollerRPM){
	roller->Set(rollerRPM);
}

void Shooter::StopRoller(){
	roller->Set(0);
}

float Shooter::GetWheelRPM(){
	return wheel->GetSpeed();
}

float Shooter::GetRollerRPM(){
	return roller->GetSpeed();
}

