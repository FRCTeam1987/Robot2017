#include "DriveTrain.h"
#include "../RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "../Commands/DriveTrain/Drive.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {
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
}

void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new Drive());
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
