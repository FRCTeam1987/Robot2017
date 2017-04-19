#include "VisionUpdateTurret.h"

VisionUpdateTurret::VisionUpdateTurret() {
	Requires(Robot::vision.get());
	m_lastTimeStamp = 0;
}

void VisionUpdateTurret::Initialize() {
	RobotMap::Log.AddEntry("VisionUpdateTurret::Initialize()");
}

void VisionUpdateTurret::Execute() {
	Robot::vision->UpdateInfo();
	TimeStampedValue timeStampedVisionInfo = Robot::vision->GetInfo();
	bool visionSawTarget = timeStampedVisionInfo.GetValue1() != 0.0;
	double visionAngle = timeStampedVisionInfo.GetValue2();
	double visionTimeStamp = timeStampedVisionInfo.GetTimeStamp();
	if(visionTimeStamp == m_lastTimeStamp) {
		RobotMap::Log.AddEntry("VisionUpdateTurret::Execute stale");
		return;
	}
	if(visionSawTarget == true && fabs(visionAngle) > .5) {
		double currentDesiredAngle = Robot::turret->GetDesiredAngle();

		Robot::turret->SetDesiredAngle(currentDesiredAngle - (visionAngle * 0.2), visionTimeStamp);
		m_lastTimeStamp = visionTimeStamp;
	} else {
		RobotMap::Log.AddEntry("VisionUpdateTurret::Execute not moving");
	}
}

bool VisionUpdateTurret::IsFinished() {
	return false;
}

void VisionUpdateTurret::End() {
	RobotMap::Log.AddEntry("VisionUpdateTurret::End()");
}

void VisionUpdateTurret::Interrupted() {
	RobotMap::Log.AddEntry("VisionUpdateTurret::Interrupted()");
}
