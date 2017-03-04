#include "AnchorTurret.h"

#include <math.h>

#define TURRET_NOGO_LO 150.0
#define TURRET_NOGO_HI 210.0

AnchorTurret::AnchorTurret(double anchorPoint) {
	Requires(Robot::turret.get());
	m_anchorPoint = anchorPoint;

	m_anchorPoint = Robot::turret.get()->GetTargetAngle();
}

void AnchorTurret::Initialize() {

}

void AnchorTurret::Execute() {
	double chassisAngle = Robot::driveTrain->GetAngle();
	double posTurret = fabs(fmod(m_anchorPoint - chassisAngle + 360.0, 360.0));

	if (posTurret < TURRET_NOGO_LO || posTurret > TURRET_NOGO_HI) {
		; // already there
	} else {
		double posNoGoMid = (TURRET_NOGO_LO + TURRET_NOGO_HI) / 2.0;
		posTurret = posTurret < posNoGoMid ? TURRET_NOGO_LO : TURRET_NOGO_HI;
	}

	Robot::turret->SetAbsoluteAngle(posTurret);
//	printf("Turret Position: %f\n", posTurret);
}

bool AnchorTurret::IsFinished() {
	return false;
}

void AnchorTurret::End() {

}

void AnchorTurret::Interrupted() {

}
