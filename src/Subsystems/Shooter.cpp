#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter() : Subsystem("Shooter") {
	wheel = RobotMap::shooterWheel;
	elevator = RobotMap::shooterElevator;
	roller = RobotMap::shooterRoller;
}

void Shooter::InitDefaultCommand() {
}

void Shooter::StartShooter(float RPM){
	wheel->Set(RPM);
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

void Shooter::StartRoller(float RPM){
	roller->Set(RPM);
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

