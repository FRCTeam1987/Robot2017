#include "ZeroTurret.h"

ZeroTurret::ZeroTurret(double voltage) {
	Requires(Robot::turret.get());
	m_isAtLimit = false;
	m_voltage = voltage;
}

void ZeroTurret::Initialize() {
	Robot::turret.get()->SetVoltage(m_voltage);
}

void ZeroTurret::Execute() {
//	frc::SmartDashboard::PutNumber("Turret Position", Robot::turret.get()->GetPosition());
	frc::SmartDashboard::PutNumber("Turret Limits", Robot::turret.get()->GetReverseLimit());
}

bool ZeroTurret::IsFinished() {
	if (Robot::turret.get()->GetReverseLimit() == 1) {
		return true;
	}else{
		return false;
	}

}

void ZeroTurret::End() {
	Robot::turret.get()->ZeroPosition();
	frc::SmartDashboard::PutNumber("Turret Limits", Robot::turret.get()->GetReverseLimit());
	Robot::turret.get()->SetVoltage(0);
}

void ZeroTurret::Interrupted() {
	Robot::turret.get()->SetVoltage(0);
}
