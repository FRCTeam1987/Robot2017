#include "PlaceGearAndHopperAuto.h"
#include "DriveTrain/ZeroDriveTrain.h"
#include "DriveTrain/DriveStraight.h"
#include "DriveTrain/DriveRotate.h"
#include "Turret/AutoTarget.h"
#include "Turret/AnchorTurret.h"
#include "Turret/ZeroTurretEncoder.h"
#include "Turret/SetDesiredAngle.h"
#include "Shooter/Shoot.h"
#include "GearManipulator/PlaceGear.h"
#include "GearManipulator/SetGearPosition.h"
#include "GearManipulator/SetGearManipulatorRoller.h"


PlaceGearAndHopperAuto::PlaceGearAndHopperAuto() {


	//Right Side (RED)
	AddSequential(new ZeroDriveTrain());
	AddSequential(new ZeroTurretEncoder());
	AddSequential(new DriveStraight(-93, 0, -.10));
	AddSequential(new DriveRotate(-57));
	AddSequential(new WaitCommand(.25));
	AddSequential(new DriveStraight(-24, 0, -.30));
	AddSequential(new SetGearPosition(false));
	AddSequential(new WaitCommand(.25));
	AddSequential(new SetGearManipulatorRoller(-0.75));
	AddSequential(new WaitCommand(.5));
	AddSequential(new SetGearManipulatorRoller(0));

	AddSequential(new DriveStraight(24, 0, .3));
	AddSequential(new SetGearPosition(true));

	AddSequential(new SetDesiredAngle(30));


	//Middle (RED)
//	AddSequential(new ZeroDriveTrain());
//	AddSequential(new ZeroTurretEncoder());
//	AddSequential(new DriveStraight(-77, 0, 0));
//	//Place Gear
//	AddSequential(new SetGearPosition(false));
//	AddSequential(new WaitCommand(.25));
//	AddSequential(new SetGearManipulatorRoller(-0.75));
//	AddSequential(new WaitCommand(.5));
//	AddSequential(new SetGearManipulatorRoller(0));
//
//	AddSequential(new DriveStraight(28 , 0, .20));
//	AddSequential(new SetGearPosition(true));
//
//	AddSequential(new SetDesiredAngle(-60));
//	AddSequential(new WaitCommand(.50));
//	AddSequential(new Shoot());

}
