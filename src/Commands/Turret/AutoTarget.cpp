#include "AutoTarget.h"

AutoTarget::AutoTarget() {
	Requires(Robot::turret.get());
}

void AutoTarget::Initialize() {
//	Robot::turret->SetMyPosition(5);
//	printf("thingy - %f\n", frc::SmartDashboard::GetNumber("angle", 0));
}

void AutoTarget::Execute() {
	float robotAngle = Robot::driveTrain->GetAngle();
	Robot::turret->UpdateHistory();
	TimeStampedValue target = Robot::turret->FetchAngleToGoal();
	TimeStampedValue history = Robot::turret->GetHistory(target.GetTimeStamp());

	double cameraAngle = -frc::SmartDashboard::GetNumber("angle", 0);
	if(fabs(cameraAngle) <= 1){
		return;
	}
	Robot::turret->SetMyPosition(cameraAngle * .5);
//	if(!target.GetValue1()) {
//		printf("No Target Value 1\n");
//		return;
//	}

}

bool AutoTarget::IsFinished() {
	printf("Position: %f, PositionError: %f\n", Robot::turret->GetPosition(), Robot::turret->GetPositionError());
	return (Robot::turret.get()->isOnTarget());
}

void AutoTarget::End() {
	printf("CurrentAngle %f\n", Robot::turret->GetAngle());
}

void AutoTarget::Interrupted() {

}
