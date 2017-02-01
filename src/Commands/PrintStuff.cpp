#include "PrintStuff.h"

PrintStuff::PrintStuff() {

}

void PrintStuff::Initialize() {
}

void PrintStuff::Execute() {
	frc::SmartDashboard::PutNumber("Roller RPM", Robot::shooter.get()->GetRollerRPM());
	frc::SmartDashboard::PutNumber("Shooter RPM", Robot::shooter.get()->GetWheelRPM());

}

bool PrintStuff::IsFinished() {
	return true;
}

void PrintStuff::End() {
}

void PrintStuff::Interrupted() {
}
