#include "HopperBlue.h"
#include "DriveTrain/ZeroDriveTrain.h"
#include "DriveTrain/DriveStraight.h"
#include "DriveTrain/DriveRotate.h"
#include "Turret/AutoTarget.h"
#include "Turret/AnchorTurret.h"
#include "Turret/ZeroTurretEncoder.h"
#include "Turret/SetDesiredAngle.h"
#include "Shooter/Shoot.h"
#include "DriveTrain/DriveArcPower.h"
#include "Shooter/ShootDistance.h"


HopperBlue::HopperBlue() {
	AddSequential(new ZeroDriveTrain());
	AddSequential(new ZeroTurretEncoder());
	AddSequential(new DriveStraight(66, 0, -.10));
	AddSequential(new DriveArcPower(false, 38));
//	AddSequential(new DriveStraight(35, 0, -.10));
//	AddSequential(new SetDesiredAngle(-90));
//	AddSequential(new AnchorTurret());
//	AddSequential(new Shoot());
}
