#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter() : Subsystem("Shooter") {
	wheelMaster = RobotMap::shooterWheelMaster;
	wheelSlave = RobotMap::shooterWheelSlave;
	elevator = RobotMap::shooterElevator;
	roller = RobotMap::shooterRoller;

	wheelMaster->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	wheelMaster->SetSensorDirection(false);
	wheelMaster->ConfigNominalOutputVoltage(0,0);
	wheelMaster->ConfigPeakOutputVoltage(12,-12);
	wheelMaster->ConfigNeutralMode(frc::CANSpeedController::kNeutralMode_Coast);
	wheelMaster->SetPID((double) 0.05, (double) 0.0, (double) 0.0, (double) 0.0425);

	m_isRun = false;

}

void Shooter::InitDefaultCommand() {
}

void Shooter::SetShooter(float power){
	wheelMaster->SetControlMode(CANTalon::kPercentVbus);
	wheelMaster->Set(-power);
}

void Shooter::SetShooterRpm(float rpm) {

	if (rpm < 0 ) {
		wheelMaster->Disable();
	}else {
		wheelMaster->Enable();
	}
	wheelMaster->SetControlMode(CANTalon::kSpeed);
	wheelMaster->Set(-rpm);
}

void Shooter::SetElevator(float power){
	if(fabs(power) > 0){
		m_isRun = true;
	}else{
		m_isRun = false;
	}
	elevator->Set(power);
}

void Shooter::SetRoller(float power){
	roller->SetControlMode(frc::CANSpeedController::kPercentVbus);
	roller->Set(power);
}

float Shooter::GetWheelRPM(){
	return wheelMaster->GetSpeed();
}

float Shooter::GetRollerRPM(){
	return roller->GetSpeed();
}
