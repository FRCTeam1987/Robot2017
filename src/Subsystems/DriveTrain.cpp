#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/DriveTrain/TestMotors.h"
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
}

void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new Drive());
}

void DriveTrain::DriveArcade(frc::XboxController *xbox) {
	robotDrive->ArcadeDrive((-xbox->GetTriggerAxis(XboxController::kLeftHand) + xbox->GetTriggerAxis(XboxController::kRightHand)), -xbox->GetX(XboxController::kLeftHand));
}

void DriveTrain::Shift(bool isHighGear)
{
	if (isHighGear){
		shifter->Set(DoubleSolenoid::kForward);
	}else {
		shifter->Set(DoubleSolenoid::kReverse);
	}
}
void DriveTrain::StartMotor() {
	leftMaster->Set(.5);
	rightMaster->Set(-.5);
}

void DriveTrain::StopMotor() {
	leftMaster->Set(0);
}
