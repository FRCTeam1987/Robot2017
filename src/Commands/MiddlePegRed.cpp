#include "MiddlePegRed.h"

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
#include "Turret/AddToCurrentAngle.h"


MiddlePegRed::MiddlePegRed() {
	//Middle (RED)
//	AddSequential(new ZeroDriveTrain());
//	AddSequential(new ZeroTurretEncoder());
//
//	AddSequential(new AddToCurrentAngle(-60));

	AddSequential(new ZeroDriveTrain());
	AddSequential(new ZeroTurretEncoder());
	AddSequential(new SetDesiredAngle(-40));

	AddSequential(new DriveStraight(-77, 0, 0));
	//Place Gear
	AddSequential(new SetGearPosition(false));
	AddSequential(new WaitCommand(.25));
	AddSequential(new SetGearManipulatorRoller(-0.75));
	AddSequential(new WaitCommand(.5));
	AddSequential(new SetGearManipulatorRoller(0));

	AddSequential(new DriveStraight(25 , 0, .20));
	AddSequential(new SetGearPosition(true));

	AddSequential(new WaitCommand(1));

	AddSequential(new Shoot());

//	AddSequential(new StopShoot());
//	AddSequential(new DriveArcPower(true, 45));
//	AddSequential(new DriveStraight(4, 0, 0));
//	AddSequential(new WaitCommand(2));


//	AddSequential(new SetDesiredAngle(-60));
////	AddSequential(new WaitForOnTarget());
////	AddSequential(new SetGearPosition(false));
////	AddSequential(new WaitCommand(2));
//
//	AddSequential(new Shoot());
}
void MiddlePegRed::Initialize() {
	RobotMap::Log.AddEntry("MiddlePegRed::Initialize()");

}
void MiddlePegRed::End() {
	RobotMap::Log.AddEntry("MiddlePegRed::End()");

}
