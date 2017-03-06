#include "AutoTarget.h"

#include "Timer.h"

AutoTarget::AutoTarget() {
	Requires(Robot::turret.get());
	m_anchorPoint = 0;
	m_angleToGoal = 0;

}

void AutoTarget::Initialize() {
//	Robot::turret->SetMyPosition(5);
}

void AutoTarget::Execute() {
	float robotAngle = Robot::driveTrain->GetAngle();
	Robot::turret->UpdateHistory();
	Robot::driveTrain->UpdateHistory();
	TimeStampedValue target = Robot::turret->FetchAngleToGoal();
	double timeOfGoal = target.GetTimeStamp();
	TimeStampedValue history = Robot::turret->GetHistory(timeOfGoal);
//	printf("history: %s\n", history.ToString().c_str());

	double delay = frc::SmartDashboard::GetNumber("timeDelta", 0);

	TimeStampedValue prevHistory = Robot::turret->GetHistory(timeOfGoal - delay);
//	printf("Previous History:  %s \n", prevHistory.ToString().c_str());


	m_angleToGoal = target.GetValue2();
	double prevTurretAngle = history.GetValue1();

	double prevAngleToGoal = prevHistory.GetValue1();

	double deltaAngleToGoal = m_angleToGoal - prevAngleToGoal;
	TimeStampedValue prevDriveTrain = Robot::driveTrain.get()->GetHistory(timeOfGoal - delay);
	double prevRobotAngle = prevDriveTrain.GetValue1();

	double currentTurretAngle = Robot::turret->GetAngle();

	double deltaRobotAngle = prevRobotAngle - Robot::driveTrain.get()->GetAngle();

//	printf("\nPrev Turret angle: %f,  current Turret Angle:  %f, Angle To Goal:  %f\n", prevTurretAngle, currentTurretAngle, m_angleToGoal);


//	double deltaTurretAngle = fabs(currentTurretAngle - prevTurretAngle);
//	printf("\nCurrent Robot Angle: %f,  Delta Robot Angle:  %f, Prev Robot Angle: %f\n", Robot::driveTrain.get()->GetAngle(), deltaRobotAngle, prevRobotAngle);
//
//	printf("\nAngle to Goal: %f,  Delta Turret Angle:  %f, Prev Angle To Goal %f\n", m_angleToGoal, deltaAngleToGoal, prevAngleToGoal);

	m_angleToGoal = (deltaRobotAngle - prevAngleToGoal);



	if (!target.GetValue1()) {
		return;
	}
	printf("Voltage: %f \n", Robot::turret->GetOutputVoltage());

	if(fabs(m_angleToGoal) <= 1 || !Robot::turret->isOnTarget() || (Robot::turret->GetOutputVoltage() != 0.0)) {
		return;
	}
	printf("isOnTarget, angle To goal:  %f \n", m_angleToGoal);
	Robot::turret.get()->SetMyPosition(m_angleToGoal);

}

bool AutoTarget::IsFinished() {

//	printf("Position: %f, PositionError: %f\n", Robot::turret->GetPosition(), Robot::turret->GetPositionError());
//	return (Robot::turret.get()->isOnTarget());
	return false;
}

void AutoTarget::End() {
//	printf("CurrentAngle %f\n", Robot::turret->GetAngle());
}

void AutoTarget::Interrupted() {

}
