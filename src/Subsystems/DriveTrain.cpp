#include "DriveTrain.h"
#include "../RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "../Commands/DriveTrain/Drive.h"
#include "../Commands/DriveTrain/UpdateSmartDashboard.h"
#include <CANTalon.h>

DriveTrain::DriveTrain() :
	PIDSubsystem("DriveTrain", -0.1, 0.0, 0.0), m_history(100) //Was P -0.1
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
	gyro = new ADXRS450_Gyro();
	m_isHigh = true;
	m_isEngaged = false;

//	ZeroAngle(); //move to somewhere else

	GetPIDController()->SetAbsoluteTolerance(2.0);
	GetPIDController()->SetContinuous(true);
	GetPIDController()->SetInputRange(0, 360);
	GetPIDController()->SetOutputRange(-1, 1);

	m_output = 0;
	m_autoSpeed = 0;
	m_autoTurn = 0;
	m_azimuth = 0;
	m_headingOffset = ahrs->GetFusedHeading();
}

double DriveTrain::ReturnPIDInput() {
//	printf("heading change: %d\n", GetHeadingChange()); //Warning
	float headingChange = GetAngle();
//	if (headingChange > 180) {
//		headingChange -= 360;
//	}
	return headingChange;
}

void DriveTrain::UsePIDOutput(double output) {
	m_output = output;
	frc::SmartDashboard::PutNumber("drive-power", m_autoSpeed);
	frc::SmartDashboard::PutNumber("drive-rotate", output);
//	printf("power: %f, rotate: %f, heading-change: %f\n", m_autoSpeed, output, Robot::driveTrain.get()->ReturnPIDInput());
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
	frc::SmartDashboard::PutNumber("gryo-angle", GetGyroAngle());
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

bool DriveTrain::IsRotating() {
	return ahrs->IsRotating();
}

double DriveTrain::GetLeftEncoderDistance() {
	return leftEncoder->GetDistance();
}

double DriveTrain::GetRightEncoderDistance() {
	return -(rightEncoder->GetDistance());
}

float DriveTrain::GetAngle() {
	frc::SmartDashboard::PutBoolean("imu-connected", ahrs->IsConnected());
	frc::SmartDashboard::PutNumber("imu-yaw", ahrs->GetYaw());
	frc::SmartDashboard::PutNumber("imu-getFusedHeading", ahrs->GetFusedHeading());
	frc::SmartDashboard::PutNumber("imu-velocity-x", ahrs->GetVelocityX());
	frc::SmartDashboard::PutNumber("imu-velocity-y", ahrs->GetVelocityY());
	frc::SmartDashboard::PutNumber("imu-displacement-x", ahrs->GetDisplacementX());
	frc::SmartDashboard::PutNumber("imu-displacement-y", ahrs->GetDisplacementY());
	frc::SmartDashboard::PutNumber("drive-left-encoder-distance", GetLeftEncoderDistance());
	frc::SmartDashboard::PutNumber("drive-right-encoder-distance", GetRightEncoderDistance());
	frc::SmartDashboard::PutNumber("Raw X", ahrs->GetRawGyroX());
	frc::SmartDashboard::PutNumber("Raw Y", ahrs->GetRawGyroY());
	frc::SmartDashboard::PutNumber("Raw Z", ahrs->GetRawGyroZ());

	return ahrs->GetYaw();
}

void DriveTrain::ZeroAngle() {
//	ahrs->ZeroYaw();
	ahrs->Reset();
//	m_headingOffset = Robot::driveTrain.get()->GetAngle();
}

void DriveTrain::ZeroEncoders() {
	leftEncoder->Reset();
	rightEncoder->Reset();
}

float DriveTrain::GetHeadingChange() {

	if (GetAngle() < 0) {
		frc::SmartDashboard::PutNumber("Drive Train Angle", GetAngle() + 360.0);
		return GetAngle() + 360.0;
	}else {
		frc::SmartDashboard::PutNumber("Drive Train Angle", GetAngle());
		return GetAngle();
	}

	m_recentHeadings.push_back(GetAngle());
	if (m_recentHeadings.size() > 5) {
		m_recentHeadings.erase(m_recentHeadings.begin());
	}
	double currentHeading = GetAngle();
//	printf("heading! %f\n", currentHeading);
	double headingChange = GetRecentHeadingChange();
	if(headingChange > 180) {
		headingChange -= 360;
	}
	return headingChange;
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

void DriveTrain::ResetHeadingOffset()
{
	m_headingOffset = ahrs->GetFusedHeading();
}

void DriveTrain::SetAzimuth(double azimuth)
{
	m_azimuth = azimuth;
}
double DriveTrain::GetAzimuth()
{
	return m_azimuth;
}

double DriveTrain::GetRecentHeadingChange()
{
	double first = m_recentHeadings[0];
	if (first > 180)
		first -= 360;

	double last = m_recentHeadings[m_recentHeadings.size()-1];
	if (last > 180)
		last -= 360;

	return last - first;
}

double DriveTrain::GetGyroAngle() {
	return gyro->GetAngle();
}

void DriveTrain::ResetGyro() {
	gyro->Reset();
}

void DriveTrain::UpdateHistory() {
	TimeStampedValue value(GetAngle(), GetLeftEncoderDistance(), GetRightEncoderDistance());
	m_history.Add(value);
}

TimeStampedValue DriveTrain::GetHistory(double timeStamp) {
	return m_history.GetHistory(timeStamp);
}

void DriveTrain::ToggleShift() {
	shifter->Set((m_isHigh ? DoubleSolenoid::kForward : DoubleSolenoid::kReverse));

	m_isHigh = !m_isHigh;
}

void DriveTrain::TogglePto() {
	PTO->Set((m_isEngaged ? DoubleSolenoid::kForward : DoubleSolenoid::kReverse));

	m_isEngaged = !m_isEngaged;
}
