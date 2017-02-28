#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter() : Subsystem("Shooter") {
	wheelMaster = RobotMap::shooterWheelMaster;
	wheelSlave = RobotMap::shooterWheelSlave;
	elevator = RobotMap::shooterElevator;
	roller = RobotMap::shooterRoller;

	wheelMaster->SetFeedbackDevice(feedbackDevice);
	wheelMaster->SetSensorDirection(false);
	wheelMaster->ConfigNominalOutputVoltage(0,0);
	wheelMaster->ConfigPeakOutputVoltage(0,-12);
	wheelMaster->ConfigNeutralMode(frc::CANSpeedController::kNeutralMode_Coast);
//	wheelMaster->SetPID(0.09, (double) 0.0, 0.8525, 0.02555);
//	wheelMaster->SetPID(0.045, (double) 0.0, 0.9, 0.0247); //Practice bot
	wheelMaster->SetPID(0.084, (double) 0.0, 0.0, 0.0275); //comp


	if(wheelMaster->IsSensorPresent(feedbackDevice) != CANTalon::FeedbackStatusPresent) {
		printf("Device Error: Could not detect shooter encoder.\n");
	}

	m_isRun = false;

}

void Shooter::InitDefaultCommand() {
}

void Shooter::SetShooter(float power){
	wheelMaster->SetControlMode(CANTalon::kPercentVbus);
	wheelMaster->Set(-power);
}

void Shooter::SetShooterRpm(float rpm) {

//	if (rpm < 0 ) {
//		wheelMaster->Disable();
//	}else {
//		wheelMaster->Enable();
//	}
	wheelMaster->Enable();
	wheelMaster->SetTalonControlMode(CANTalon::kSpeedMode);
	wheelMaster->Set(-rpm);
}

void Shooter::SetElevator(float power){
	frc::SmartDashboard::PutBoolean("Is set elevator running", true);

	elevator->Set(power);
}

void Shooter::SetRoller(float power){
	frc::SmartDashboard::PutBoolean("Is set roller running", true);
	roller->SetControlMode(frc::CANSpeedController::kPercentVbus);
	roller->Set(power);
}

float Shooter::GetWheelRPM(){
	frc::SmartDashboard::PutNumber("Shooter Error", wheelMaster->GetClosedLoopError());
	return wheelMaster->GetSpeed();
}

float Shooter::GetRollerRPM(){
	return roller->GetSpeed();
}
