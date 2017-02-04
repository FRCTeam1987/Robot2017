#include "Turret.h"
#include "../RobotMap.h"
#include "../Commands/Turret/ZeroTurret.h"

Turret::Turret() : Subsystem("Turret") {
	m_angle = 0;
	m_tolerance = 2.0;
	motor = RobotMap::turretMotor;

	motor.get()->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	motor.get()->ConfigLimitMode(frc::CANSpeedController::kLimitMode_SwitchInputsOnly);
	motor.get()->ConfigNeutralMode(frc::CANSpeedController::NeutralMode::kNeutralMode_Brake);

	motor.get()->ConfigPeakOutputVoltage(12, -12);
	motor.get()->ConfigNominalOutputVoltage(0, 0);

	motor.get()->SetPID(.05, 0, 0, 0);
}

void Turret::InitDefaultCommand() {
//	SetDefaultCommand(new ZeroTurret(0.25));
}

void Turret::SetPosition(double angle) {
	m_angle = angle;
	double targetAngle = (angle * (10 / 360));//accounts for 10:1 gear ration on turret

	motor.get()->SetControlMode(CANTalon::kPosition);
	motor.get()->Set(targetAngle);
}

double Turret::GetPosition() {
	return motor.get()->GetPosition();
}

double Turret::GetPositionError() {
	return fabs(m_angle - GetPosition());
}

bool Turret::isOnTarget() {
	return (GetPositionError() <= m_tolerance);
}

void Turret::SetVoltage(double voltage) {
	motor.get()->SetControlMode(CANTalon::kPercentVbus);
	motor.get()->Set(voltage);
}

void Turret::ZeroPosition() {
	motor.get()->SetPosition(0);
}

int Turret::GetForwardLimit() {
	return motor.get()->IsFwdLimitSwitchClosed();
}

int Turret::GetReverseLimit() {
	return motor.get()->IsRevLimitSwitchClosed();
}
