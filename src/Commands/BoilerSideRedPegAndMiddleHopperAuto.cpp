#include "BoilerSideRedPegAndMiddleHopperAuto.h"
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
#include "DriveTrain/Shift.h"
#include "Commands/DriveTrain/DriveArcPower.h"
#include "Commands/Vision/SetVisionDefaultCommand.h"

BoilerSideRedPegAndMiddleHopperAuto::BoilerSideRedPegAndMiddleHopperAuto() {
	AddSequential(new Shift(true));
	AddSequential(new ZeroDriveTrain());
	AddSequential(new ZeroTurretEncoder());
	AddSequential(new DriveStraight(-85, 0, -.45));
	AddSequential(new DriveStraight(0, 0, 0));
	AddSequential(new DriveRotate(-57));
	AddSequential(new frc::WaitCommand(.15));
	AddSequential(new DriveStraight(-22, 0, -.6));
	AddSequential(new DriveStraight(0, 0, 0));
	AddSequential(new SetGearPosition(false));
	AddSequential(new frc::WaitCommand(.15));
	AddSequential(new SetGearManipulatorRoller(-0.75));
	AddSequential(new frc::WaitCommand(.15));
	AddSequential(new SetGearManipulatorRoller(0));

	AddSequential(new DriveStraight(20, 0, .65));
	AddSequential(new DriveStraight(0, 0, 0));
	AddSequential(new SetGearPosition(true));

	AddSequential(new SetVisionDefaultCommand(false));
	AddSequential(new SetDesiredAngle(11));

//	AddSequential(new frc::WaitCommand(1));
	AddSequential(new Shoot());
//	AddSequential(new frc::WaitCommand(1));




//	AddSequential(new frc::WaitCommand(4));
	AddSequential(new StopShoot());
	AddSequential(new SetVisionDefaultCommand(false));

	AddSequential(new DriveRotate(55));
//	AddSequential(new DriveArcPower(true, ))
	AddSequential(new Shift(false));
//	AddSequential(new DriveArcPower(false, -50));
	AddSequential(new DriveStraight(-140, 0, -.95));
	AddSequential(new DriveStraight(0, 0, 0));
	AddSequential(new DriveRotate(-90));
	AddSequential(new DriveStraight(50, 0, -.7));
	AddSequential(new DriveStraight(0, 0, 0));
}
