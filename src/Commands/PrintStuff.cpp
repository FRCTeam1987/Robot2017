#include "PrintStuff.h"

PrintStuff::PrintStuff() {

}

void PrintStuff::Initialize() {
}

void PrintStuff::Execute() {
//	frc::SmartDashboard::PutNumber("Roller RPM", Robot::shooter.get()->GetRollerRPM());
//	frc::SmartDashboard::PutNumber("Shooter RPM", Robot::shooter.get()->GetWheelRPM());
//	frc::SmartDashboard::PutNumber("Gyro Angle", Robot::driveTrain.get()->GetAngle());
//	frc::SmartDashboard::PutNumber("Encoder Distance", Robot::driveTrain.get()->GetLeftEncoderDistance());
//	frc::SmartDashboard::PutNumber("Encoder Distance", Robot::driveTrain.get()->GetRightEncoderDistance());
	frc::SmartDashboard::PutNumber("Gear Sensor", Robot::gearManipulator.get()->HasGear());
	frc::SmartDashboard::PutNumber("Fuel Sensor", Robot::collector.get()->HasBall());
	frc::SmartDashboard::PutNumber("turret position", Robot::turret.get()->GetPosition());


}

bool PrintStuff::IsFinished() {
	return true;
}

void PrintStuff::End() {
}

void PrintStuff::Interrupted() {
}
