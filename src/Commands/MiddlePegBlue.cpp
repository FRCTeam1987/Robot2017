#include "MiddlePegBlue.h"

#include "PlaceGearAndHopperAuto.h"
#include "DriveTrain/ZeroDriveTrain.h"
#include "DriveTrain/DriveStraight.h"
#include "DriveTrain/DriveRotate.h"
#include "Turret/AutoTarget.h"
#include "Turret/AnchorTurret.h"
#include "Turret/ZeroTurretEncoder.h"
#include "Shooter/Shoot.h"
#include "GearManipulator/PlaceGear.h"
#include "GearManipulator/SetGearPosition.h"
#include "GearManipulator/SetGearManipulatorRoller.h"
#include "Turret/TargetAndAnchor.h"
#include "DriveTrain/DriveArcPower.h"

MiddlePegBlue::MiddlePegBlue() {
	//Middle (BLUE)
	AddSequential(new ZeroDriveTrain());
	AddSequential(new ZeroTurretEncoder());
	AddSequential(new DriveStraight(-77, 0, 0));
	//Place Gear
	AddSequential(new SetGearPosition(false));
	AddSequential(new WaitCommand(.25));
	AddSequential(new SetGearManipulatorRoller(-0.75));
	AddSequential(new WaitCommand(.5));
	AddSequential(new SetGearManipulatorRoller(0));

	AddSequential(new DriveStraight(28 , 0, .20));
	AddSequential(new SetGearPosition(true));

	// TODO: update to use parallel anchoring
//	AddSequential(new AnchorTurret(60, false));
	AddSequential(new WaitCommand(.5));
	AddSequential(new TargetAndAnchor());
//	AddSequential(new WaitCommand(.50));
//	AddSequential(new Shoot());
}
