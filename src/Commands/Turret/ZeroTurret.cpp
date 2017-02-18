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
	frc::SmartDashboard::PutNumber("Turret Position", Robot::turret.get()->GetPosition());
	frc::SmartDashboard::PutNumber("Turret Limits Reverse", Robot::turret.get()->GetReverseLimit());
	frc::SmartDashboard::PutNumber("Turret Limits Forward", Robot::turret.get()->GetForwardLimit());

}

bool ZeroTurret::IsFinished() {
	if (Robot::turret.get()->GetForwardLimit() == 1) {
		return true;
	}else{
		return false;
	}

}

void ZeroTurret::End() {
	Robot::turret.get()->ZeroPosition();

	Robot::turret.get()->SetVoltage(0);
}

void ZeroTurret::Interrupted() {
	Robot::turret.get()->SetVoltage(0);
}
