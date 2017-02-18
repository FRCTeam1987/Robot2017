#include "DriveTrain.h"
#include "../RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "../Commands/DriveTrain/Drive.h"
#include "../Commands/DriveTrain/UpdateSmartDashboard.h"
#include <CANTalon.h>

DriveTrain::DriveTrain() :
	PIDSubsystem("DriveTrain", 0.01, 0.0, 0.0)
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

//	ZeroAngle(); //move to somewhere else

	GetPIDController()->SetAbsoluteTolerance(2.0);
	GetPIDController()->SetContinuous(true);
	GetPIDController()->SetInputRange(0, 360);
	GetPIDController()->SetOutputRange(-1, 1);

	m_output = 0;
	m_autoSpeed = 0;
	m_autoTurn = 0;
	m_headingOffset = ahrs->GetFusedHeading();
}

double DriveTrain::ReturnPIDInput() {
//	printf("heading change: %d\n", GetHeadingChange()); //Warning
	return GetHeadingChange();
}

void DriveTrain::UsePIDOutput(double output) {
	m_output = output;
	frc::SmartDashboard::PutNumber("drive-power", m_autoSpeed);
	frc::SmartDashboard::PutNumber("drive-rotate", output);
	printf("power: %f, rotate: %f\n", m_autoSpeed, output);
	AutoDrive(m_autoSpeed, output + m_autoTurn);
}

void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new Drive());
//	SetDefaultCommand(new UpdateSmartDashboard());
}

void DriveTrain::DriveArcade(frc::XboxController *xbox) {
	frc::SmartDashboard::PutBoolean("imu-connected", ahrs->IsConnected());
	frc::SmartDashboard::PutNumber("imu-yaw", ahrs->GetYaw());
	frc::SmartDashboard::PutNumber("imu-getFusedHeading", ahrs->GetFusedHeading());
	frc::SmartDashboard::PutNumber("imu-velocity-x", ahrs->GetVelocityX());
	frc::SmartDashboard::PutNumber("imu-velocity-y", ahrs->GetVelocityY());
	frc::SmartDashboard::PutNumber("imu-displacement-x", ahrs->GetDisplacementX());
	frc::SmartDashboard::PutNumber("imu-displacement-y", ahrs->GetDisplacementY());
	frc::SmartDashboard::PutNumber("drive-left-encoder-distance", GetLeftEncoderDistance());
	frc::SmartDashboard::PutNumber("drive-right-encoder-distance", GetRightEncoderDistance());
	robotDrive->ArcadeDrive((-xbox->GetTriggerAxis(XboxController::kLeftHand) + xbox->GetTriggerAxis(XboxController::kRightHand)), -xbox->GetX(XboxController::kLeftHand));
}

void DriveTrain::Shift(bool isHighGear) {
	if (isHighGear)
		shifter->Set(DoubleSolenoid::kForward);
	else
		shifter->Set(DoubleSolenoid::kReverse);
}

void DriveTrain::DriveTank(float left, float right) {
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

float DriveTrain::GetAngle() {
//	frc::SmartDashboard::PutBoolean("imu-connected", ahrs->IsConnected());
//	frc::SmartDashboard::PutNumber("imu-yaw", ahrs->GetYaw());
//	frc::SmartDashboard::PutNumber("imu-getFusedHeading", ahrs->GetFusedHeading());
//	frc::SmartDashboard::PutNumber("imu-velocity-x", ahrs->GetVelocityX());
//	frc::SmartDashboard::PutNumber("imu-velocity-y", ahrs->GetVelocityY());
//	frc::SmartDashboard::PutNumber("imu-displacement-x", ahrs->GetDisplacementX());
//	frc::SmartDashboard::PutNumber("imu-displacement-y", ahrs->GetDisplacementY());
//	frc::SmartDashboard::PutNumber("drive-left-encoder-distance", GetLeftEncoderDistance());
//	frc::SmartDashboard::PutNumber("drive-right-encoder-distance", GetRightEncoderDistance());
	return ahrs->GetFusedHeading();
}

void DriveTrain::ZeroAngle() {
	ahrs->ZeroYaw();
//	ahrs->Reset();
	m_headingOffset = Robot::driveTrain.get()->GetAngle();
}

void DriveTrain::ZeroEncoders() {
	leftEncoder->Reset();
	rightEncoder->Reset();
}

float DriveTrain::GetHeadingChange() {
	if (GetAngle() < 0)
	{
		frc::SmartDashboard::PutNumber("Drive Train Angle", GetAngle() + 360.0);
		return ((GetAngle() - m_headingOffset) + 360.0);
	}else {
		frc::SmartDashboard::PutNumber("Drive Train Angle", GetAngle());
		return (GetAngle() - m_headingOffset);
	}
}

void DriveTrain::AutoDrive(float move, float rotate) {
	robotDrive->ArcadeDrive(move, rotate);
}

void DriveTrain::SetAutoSpeed(double autoSpeed) {
	m_autoSpeed = autoSpeed;
}

void DriveTrain::SetAutoTurn(float turn) {
	m_autoTurn = turn;
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
