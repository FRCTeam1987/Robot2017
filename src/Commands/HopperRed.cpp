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
#include "Turret/AddToCurrentAngle.h"


HopperRed::HopperRed() {
	AddSequential(new frc::WaitCommand(2));
	AddSequential(new ZeroDriveTrain());
	AddSequential(new ZeroTurretEncoder());
////	AddSequential(new SetDesiredAngle(144));
	AddSequential(new DriveStraight(24, 0, -.10)); //129
	AddSequential(new frc::WaitCommand(1));
////	AddSequential(new DriveArcPower(true, 20));
	AddSequential(new DriveRotate(90));//90
////	AddSequential(new VisionUpdateTurret());
//	AddSequential(new WaitCommand(.45));
//	AddSequential(new SetDesiredAngle(160));
//	AddSequential(new WaitCommand(2));
//	AddParallel(new )


//	AddSequential(new DriveStraight(34, 0, -.10));
//	AddSequential(new SetDesiredAngle(85));
//	AddSequential(new AddToCurrentAngle(40));
//	AddSequential(new AnchorTurret());

//	AddSequential(new DriveStraight(35, 0, -.10));
//	AddSequential(new SetDesiredAngle(90));
//	AddSequential(new AnchorTurret());
//	AddSequential(new Shoot());
	AddSequential(new frc::WaitCommand(6));
}
