#include "Turret.h"
#include "../RobotMap.h"
#include "../Commands/Turret/ZeroTurret.h"
#include "../Commands/Turret/SetPosition.h"

Turret::Turret() : Subsystem("Turret") {
	m_angle = 0;
	m_tolerance = .10;
	motor = RobotMap::turretMotor;



	m_driveGearDiameter = 1.375;
	m_turretGearDiameter = 13;

	int absolutePosition = motor->GetPulseWidthPosition() & 0xFFF;

	motor->SetEncPosition(absolutePosition);
	motor->SetSensorDirection(true);

	motor->SetControlMode(CANTalon::kPosition);


	motor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	motor->ConfigLimitMode(frc::CANSpeedController::kLimitMode_SwitchInputsOnly);
	motor->ConfigForwardSoftLimitEnable(true);
	motor->ConfigReverseSoftLimitEnable(true);
	motor->ConfigForwardLimit(3.399169921875);
	motor->ConfigReverseLimit(-3.399169921875);


	motor->ConfigNeutralMode(frc::CANSpeedController::NeutralMode::kNeutralMode_Brake);

	motor->SetAllowableClosedLoopErr(1);
	motor->SetClosedLoopOutputDirection(true);
	motor->ConfigPeakOutputVoltage(8, -8); // change this cuz mechanizm is lame
	motor->ConfigNominalOutputVoltage(0, 0);

	motor->SetPID(.7, 0, 30.0, 0);
}

void Turret::InitDefaultCommand() {
	SetDefaultCommand(new ::SetPosition(90));
}

void Turret::SetPosition(double angle) {
	motor->SetControlMode(CANTalon::kPosition);

	frc::SmartDashboard::PutNumber("Pre Calc Turret Angle", angle);
	angle = angle - (GetYaw());

	if (fabs(GetAngle() - angle) <= 10) {
		motor->SetPID(.3, 0, 2.0, 0);
	} else {
		motor->SetPID(.7, 0, 30.0, 0);
	}

	if (angle > 180) {
		angle = (angle - 180) * -1;
	} else if (angle < -180) {
		angle = (angle + 180) * -1;
	}

	if (angle >= 126) {
		angle = 120;
	} else if (angle <= -126) {
		angle = -120;
	}



	m_angle = angle;
	frc::SmartDashboard::PutNumber("Target Turret Angle", angle);
	double targetPosition = (angle * m_rotationsToDegrees);//accounts for 10:1 gear ration on turret

	motor->Set(targetPosition);
}

double Turret::GetPosition() {
	return motor->GetPosition();
}

double Turret::GetAngle() {
	return  GetPosition() / m_rotationsToDegrees;
}

double Turret::GetPositionError() {
	return (motor->GetClosedLoopError() / 1024.0) * m_rotationsToDegrees;
}

bool Turret::isOnTarget() {
	return (fabs(GetPositionError()) <= m_tolerance);
}

void Turret::SetVoltage(double voltage) {
	motor->SetControlMode(CANTalon::kPercentVbus);
	motor->Set(voltage);
}

void Turret::ZeroPosition() {
	motor->SetPosition(0);
}

int Turret::GetForwardLimit() {
	return motor->IsFwdLimitSwitchClosed();
}

int Turret::GetReverseLimit() {
	return motor->IsRevLimitSwitchClosed();
}

double Turret::GetYaw() {
	return Robot::driveTrain.get()->GetAngle();
}


