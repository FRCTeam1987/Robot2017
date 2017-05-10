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

	AddSequential(new ZeroDriveTrain());
	AddSequential(new ZeroTurretEncoder());
	AddSequential(new DriveStraight(128, 0, .950)); //129
	AddSequential(new DriveStraight(0, 0, .0));

	AddSequential(new DriveRotate(90));
	AddSequential(new SetShooterPercent(.65));


	AddSequential(new SetDesiredAngle(78));

	AddSequential(new DriveStraight(32, 0, .850));
	AddSequential(new DriveStraight(0, 0, .0));

//	AddSequential(new SetVisionDefaultCommand(false));
	AddSequential(new frc::WaitCommand(1));

	AddSequential(new Shoot());
	AddSequential(new frc::WaitCommand(4.75));
	AddSequential(new Shoot());
	AddSequential(new frc::WaitCommand(4.75));
	AddSequential(new Shoot());




}
