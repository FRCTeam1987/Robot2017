#include "AutoTarget.h"

AutoTarget::AutoTarget() {
	Requires(Robot::turret.get());
}

void AutoTarget::Initialize() {
//	Robot::turret->SetMyPosition(5);
}

void AutoTarget::Execute() {
	float robotAngle = Robot::driveTrain->GetAngle();
	Robot::turret->UpdateHistory();
	TimeStampedValue target = Robot::turret->FetchAngleToGoal();
	TimeStampedValue history = Robot::turret->GetHistory(target.GetTimeStamp());
	printf("history: %s\n", history.ToString().c_str());
	if (!target.GetValue1()) {
		return;
	}

	double cameraAngle = -frc::SmartDashboard::GetNumber("angle", 0);

	if(fabs(cameraAngle) <= 1 || !Robot::turret->isOnTarget()){
		return;
	}
	Robot::turret->SetMyPosition(cameraAngle * .15);


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
