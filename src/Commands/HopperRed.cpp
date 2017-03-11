#include "HopperRed.h"
#include "DriveTrain/ZeroDriveTrain.h"
#include "DriveTrain/DriveStraight.h"
#include "DriveTrain/DriveRotate.h"
#include "Turret/AutoTarget.h"
#include "Turret/AnchorTurret.h"
#include "Turret/ZeroTurretEncoder.h"
#include "Turret/SetDesiredAngle.h"
#include "Shooter/Shoot.h"
#include "DriveTrain/DriveArcPower.h"
#include "Vision/VisionUpdateTurret.h"


HopperRed::HopperRed() {
	AddSequential(new ZeroDriveTrain());
//	AddSequential(new ZeroTurretEncoder());
	AddSequential(new SetDesiredAngle(90));
	AddSequential(new DriveStraight(124, 0, -.10));
//	AddSequential(new DriveArcPower(true, 20));
	AddSequential(new DriveRotate(90));
	AddSequential(new VisionUpdateTurret());
	AddSequential(new WaitCommand(.25));
	AddSequential(new DriveStraight(36, 0, -.10));
//	AddSequential(new DriveStraight(35, 0, -.10));
//	AddSequential(new SetDesiredAngle(90));
//	AddSequential(new AnchorTurret());
//	AddSequential(new Shoot());

}
