#include "MiddlePegBlue.h"

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
#include "DriveTrain/DriveArcPower.h"
#include "Turret/WaitForOnTarget.h"

MiddlePegBlue::MiddlePegBlue() {
	//Middle (BLUE)
	AddSequential(new ZeroDriveTrain());
	AddSequential(new ZeroTurretEncoder());

	AddSequential(new DriveStraight(-73, 0, -.25));
	//Place Gear
	AddSequential(new SetGearPosition(false));
	AddSequential(new frc::WaitCommand(.25));
	AddSequential(new SetGearManipulatorRoller(-0.75));
	AddSequential(new frc::WaitCommand(.5));
	AddSequential(new SetGearManipulatorRoller(0));
	AddSequential(new SetDesiredAngle(45));

	AddSequential(new DriveStraight(25, 0, .4));
	AddSequential(new DriveStraight(0, 0, 0));

	AddSequential(new SetGearPosition(true));

	AddSequential(new Shoot());
}
