#include "AnchorTurret.h"

#include <math.h>

#define TURRET_NOGO_LO 145.0
#define TURRET_NOGO_HI 215.0

AnchorTurret::AnchorTurret() {
	Requires(Robot::turret.get());
}

void AnchorTurret::Initialize() {
	RobotMap::Log.AddEntry("AnchorTurret::Initialize()");
}

void AnchorTurret::Execute() {
//	printf("running anchor turret\n");
	Robot::turret->UpdateHistory();
	double chassisAngle = Robot::driveTrain->GetAngle();
	double desiredTurretAngle = Robot::turret->GetDesiredAngle();
	double posTurret = fabs(fmod(desiredTurretAngle - chassisAngle + 360.0, 360.0));
	if (posTurret < TURRET_NOGO_LO || posTurret > TURRET_NOGO_HI) {
//		printf("if \n");

		; // already there
	} else {
//		printf("else\n");

		double posNoGoMid = (TURRET_NOGO_LO + TURRET_NOGO_HI) / 2.0;
		posTurret = posTurret < posNoGoMid ? TURRET_NOGO_LO : TURRET_NOGO_HI;
	}
//	printf("end execute\n");

	Robot::turret->SetAbsoluteAngle(posTurret);
}

bool AnchorTurret::IsFinished() {
//	return Robot::turret->isOnTarget();
	return false;
}

void AnchorTurret::End() {
	RobotMap::Log.AddEntry("AnchorTurret::End()");
}

void AnchorTurret::Interrupted() {
//	printf("Interrupted\n");

	RobotMap::Log.AddEntry("AnchorTurret::Interrupted()");
}
