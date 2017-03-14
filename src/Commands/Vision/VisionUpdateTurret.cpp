#include "VisionUpdateTurret.h"

VisionUpdateTurret::VisionUpdateTurret() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::vision.get());
	m_lastTimeStamp = 0;
}

// Called just before this Command runs the first time
void VisionUpdateTurret::Initialize() {
	RobotMap::Log.AddEntry("VisionUpdateTurret::Initialize()");
}

// Called repeatedly when this Command is scheduled to run
void VisionUpdateTurret::Execute() {
//	printf("Vision Execute \n");
	Robot::vision->UpdateInfo();
	TimeStampedValue timeStampedVisionInfo = Robot::vision->GetInfo();
	bool visionSawTarget = timeStampedVisionInfo.GetValue1() != 0.0;
	double visionAngle = timeStampedVisionInfo.GetValue2();
	double visionTimeStamp = timeStampedVisionInfo.GetTimeStamp();
	if(visionTimeStamp == m_lastTimeStamp) {
		RobotMap::Log.AddEntry("VisionUpdateTurret::Execute stale");
//		printf("old!\n");
		return;
	}
//	printf("lastTimeStamp: %f, visionTimeStamp: %f, visionAngle: %f, visionSawTarget: %f\n", m_lastTimeStamp, visionTimeStamp, visionAngle, visionSawTarget ? 1.0 : 0.0);
	if(visionSawTarget == true && fabs(visionAngle) > .5) {
//		printf("here\n");
		double currentDesiredAngle = Robot::turret->GetDesiredAngle();
		Robot::turret->SetDesiredAngle(currentDesiredAngle - visionAngle);
//		printf("Desired Angle:  %f \n", currentDesiredAngle - (visionAngle * 0.175));
//
//		char msg[256];
//		sprintf(msg, "VisionUpdateTurret::Execute moving - currentDesiredAngle:%f - SetDesiredAngle(%f)",
//				currentDesiredAngle, currentDesiredAngle - (visionAngle * 0.175));
//		RobotMap::Log.AddEntry(msg);
		Robot::turret->SetDesiredAngle(currentDesiredAngle - (visionAngle * 0.175), visionTimeStamp);
		m_lastTimeStamp = visionTimeStamp;
	} else {
		RobotMap::Log.AddEntry("VisionUpdateTurret::Execute not moving");
	}
}

// Make this return true when this Command no longer needs to run execute()
bool VisionUpdateTurret::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void VisionUpdateTurret::End() {
	RobotMap::Log.AddEntry("VisionUpdateTurret::End()");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void VisionUpdateTurret::Interrupted() {
	RobotMap::Log.AddEntry("VisionUpdateTurret::Interrupted()");
}
