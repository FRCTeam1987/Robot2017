#include "UpdateSmartDashboard.h"

UpdateSmartDashboard::UpdateSmartDashboard() {
	Requires(Robot::driveTrain.get());
}

void UpdateSmartDashboard::Initialize() {

}

void UpdateSmartDashboard::Execute() {
	frc::SmartDashboard::PutNumber("Left Encoder", Robot::driveTrain.get()->GetLeftEncoderDistance());
	frc::SmartDashboard::PutNumber("Right Encoder", Robot::driveTrain.get()->GetRightEncoderDistance());
	frc::SmartDashboard::PutNumber("Angle", Robot::driveTrain.get()->GetAngle());
}

bool UpdateSmartDashboard::IsFinished() {
	return true;
}

void UpdateSmartDashboard::End() {

}

void UpdateSmartDashboard::Interrupted() {

}
