#include "Vision.h"
#include "../RobotMap.h"

#include "../Commands/Vision/VisionUpdateTurret.h"

Vision::Vision() : Subsystem("Vision") {
	m_angleToTarget = 0;
	m_distanceToTarget = 0;
	m_isTargetVisible = 0;
	m_timeStamp = 0;
}

void Vision::InitDefaultCommand() {
	RobotMap::Log.AddEntry("Vision::InitDefaultCommand()");
	SetDefaultCommand(new VisionUpdateTurret());
}

void Vision::UpdateInfo() {
	const double defaultAngleToTarget = 0.0;
	const double defaultComputeTime = 0.1;
	const double networkTablesDelay = .08;
	const double defaultDistanceToTarget = 0.0;
	const bool defaultHasTarget = false;

	double isTargetVisible = frc::SmartDashboard::GetBoolean("hasTarget", defaultHasTarget) ? 1.0 : 0.0;
	double angleToTarget = frc::SmartDashboard::GetNumber("angle", defaultAngleToTarget);
	double computeTime = frc::SmartDashboard::GetNumber("timeDelta", defaultComputeTime);
	double distanceToTarget = frc::SmartDashboard::GetNumber("distance", defaultDistanceToTarget);

	if(m_angleToTarget == angleToTarget) {
		//printf("Vision::UpdateInfo same data, don't update vision info!\n");
		return;
	}

	double currentTime = frc::Timer::GetFPGATimestamp();
	double imageCaptureTime = currentTime - computeTime - networkTablesDelay;
	m_angleToTarget = angleToTarget;
	m_distanceToTarget = distanceToTarget;
	m_isTargetVisible = isTargetVisible;
	m_timeStamp = imageCaptureTime;
}

TimeStampedValue Vision::GetInfo() {
	TimeStampedValue info = TimeStampedValue(m_isTargetVisible, m_angleToTarget, m_distanceToTarget);
	info.SetTimeStamp(m_timeStamp);
	return info;
}
