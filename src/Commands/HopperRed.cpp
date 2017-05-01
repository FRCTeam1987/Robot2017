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
#include "Shooter/SetShooterPercent.h"
#include "Shooter/SetShooter.h"
#include "Shooter/SetRoller.h"
#include "Shooter/SetElevator.h"
#include "Collector/SetCollector.h"
#include "DriveTrain/Shift.h"



HopperRed::HopperRed() {
	AddSequential(new Shift(true));

	//	AddSequential(new frc::WaitCommand(.25));
	AddSequential(new ZeroDriveTrain());
	AddSequential(new ZeroTurretEncoder());
//	AddSequential(new SetDesiredAngle(90));
	AddSequential(new DriveStraight(130, 0, -.10)); //129
//	AddSequential(new frc::WaitCommand(.5));
//	AddSequential(new DriveArcPower(true, 20));
	AddSequential(new DriveRotate(90));//90
	AddSequential(new SetShooterPercent(.65));
	AddSequential(new SetDesiredAngle(75));

////	AddSequential(new VisionUpdateTurret());
//	AddSequential(new frc::WaitCommand(.8));
//	AddSequential(new SetDesiredAngle(160));
//	AddSequential(new WaitCommand(2));
//	AddParallel(new )

	AddSequential(new DriveStraight(32, 0, -.10));
	AddSequential(new frc::WaitCommand(.25));
	AddSequential(new Shoot());




//	AddSequential(new SetDesiredAngle(120));
//	AddSequential(new AddToCurrentAngle(40));
//	AddSequential(new AnchorTurret());


//	AddSequential(new DriveStraight(35, 0, -.10));
//	AddSequential(new SetDesiredAngle(90));
//	AddSequential(new AnchorTurret());
//	AddSequential(new Shoot());
//	AddSequential(new frc::WaitCommand(6));
}
