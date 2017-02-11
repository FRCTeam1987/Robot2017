#include "DriveTrain.h"
#include "../RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "../Commands/DriveTrain/Drive.h"
#include "../Commands/DriveTrain/UpdateSmartDashboard.h"
#include <CANTalon.h>

DriveTrain::DriveTrain() :
	PIDSubsystem("DriveTrain", 1.0, 0.0, 0.0)
{
	leftMaster = RobotMap::driveLeftMaster;
	rightMaster = RobotMap::driveRightMaster;
	leftSlave = RobotMap::driveLeftSlave;
	rightSlave = RobotMap::driveRightSlave;
	robotDrive = RobotMap::robotDrive;
	ahrs = RobotMap::driveAhrs;
	navx = RobotMap::driveNavx;
	shifter = RobotMap::driveShifter;
	PTO = RobotMap::climberPTO;
	plateSensor = RobotMap::climberPlateSensor;
	leftEncoder = RobotMap::driveLeftEncoder;
	rightEncoder = RobotMap::driveRightEncoder;

	GetPIDController()->SetAbsoluteTolerance(2.0);
	GetPIDController()->SetContinuous(true);
	GetPIDController()->SetInputRange(0, 360);
	GetPIDController()->SetOutputRange(-1, 1);

	m_output = 0;
	m_autoSpeed = 0;
}
double DriveTrain::ReturnPIDInput() {
	return GetHeadingChange();
}

void DriveTrain::UsePIDOutput(double output) {
	m_output = output;

	AutoDrive(m_autoSpeed, output);
}
void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new Drive());
//	SetDefaultCommand(new UpdateSmartDashboard());
}

void DriveTrain::DriveArcade(frc::XboxController *xbox) {
	robotDrive->ArcadeDrive((-xbox->GetTriggerAxis(XboxController::kLeftHand) + xbox->GetTriggerAxis(XboxController::kRightHand)), -xbox->GetX(XboxController::kLeftHand));
}

void DriveTrain::Shift(bool isHighGear)
{
	if (isHighGear)
		shifter->Set(DoubleSolenoid::kForward);
	else
		shifter->Set(DoubleSolenoid::kReverse);
}

void DriveTrain::DriveTank(float left, float right)
{
	robotDrive->TankDrive(left, -right);
}

void DriveTrain::SetPTO(bool isEnabled) {
	if (isEnabled == true)
		PTO->Set(DoubleSolenoid::kForward);
	else
		PTO->Set(DoubleSolenoid::kReverse);
}

bool DriveTrain::IsTouchingPlate() {
	return plateSensor->Get();
}

double DriveTrain::GetLeftEncoderDistance() {
	return leftEncoder->GetDistance();
}

double DriveTrain::GetRightEncoderDistance() {
	return -(rightEncoder->GetDistance());
}

double DriveTrain::GetAngle() {
	return ahrs->GetFusedHeading();
}

void DriveTrain::ZeroAngle() {
	ahrs->Reset();
}

void DriveTrain::ZeroEncoders() {
	leftEncoder->Reset();
	rightEncoder->Reset();
}

double DriveTrain::GetHeadingChange() {
	if (GetAngle() < 0)
	{
		return (GetAngle() + 360);
	}else {
		return GetAngle();
	}
}

void DriveTrain::AutoDrive(float move, float rotate) {
	robotDrive->ArcadeDrive(move, rotate);
}

void DriveTrain::SetAutoSpeed(double autoSpeed) {
	m_autoSpeed = autoSpeed;
}

void DriveTrain::SetSetpoint(double setpoint) {
	GetPIDController()->SetSetpoint(setpoint);
}

void DriveTrain::SetBrake() {
	leftMaster->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Brake);
	rightMaster->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Brake);
}

void DriveTrain::SetCoast() {
	leftMaster->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Coast);
	rightMaster->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Coast);
}
