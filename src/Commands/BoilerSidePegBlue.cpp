#include "BoilerSidePegBlue.h"
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
#include "Shooter/SetShooter.h"
#include "Shooter/SetShooterPercent.h"


BoilerSidePegBlue::BoilerSidePegBlue() {

	AddSequential(new ZeroDriveTrain());
	AddSequential(new ZeroTurretEncoder());

	AddSequential(new DriveStraight(-91, 0, -.10));
	AddSequential(new DriveRotate(57));
	AddSequential(new WaitCommand(.25));
	AddSequential(new DriveStraight(-22, 0, -.30));
	AddSequential(new SetGearPosition(false));
	AddSequential(new WaitCommand(.25));
	AddSequential(new SetGearManipulatorRoller(-0.75));
	AddSequential(new WaitCommand(.5));

	AddSequential(new SetGearManipulatorRoller(0));

	AddSequential(new DriveStraight(24, 0, .25));
	AddSequential(new SetShooterPercent(.6));

	AddSequential(new SetGearPosition(true));

	AddSequential(new SetDesiredAngle(-30));

	AddSequential(new WaitCommand(1.5));
	AddSequential(new Shoot());

//	AddSequential(new StopShoot());
//	AddSequential(new DriveRotate(123));
//	AddSequential(new DriveStraight(4, 0, 0));
}
