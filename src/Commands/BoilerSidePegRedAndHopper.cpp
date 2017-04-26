#include "BoilerSidePegRedAndHopper.h"
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
#include "Shooter/StopShoot.h"


BoilerSidePegRedAndHopper::BoilerSidePegRedAndHopper() {

	AddSequential(new ZeroDriveTrain());
	AddSequential(new ZeroTurretEncoder());
	AddSequential(new DriveStraight(-96, 0, -.25));
	AddSequential(new DriveRotate(-57));
	AddSequential(new frc::WaitCommand(.25));
	AddSequential(new DriveStraight(-22, 0, -.10));
	AddSequential(new SetGearPosition(false));
	AddSequential(new frc::WaitCommand(.25));
	AddSequential(new SetGearManipulatorRoller(-0.75));
	AddSequential(new frc::WaitCommand(.5));
	AddSequential(new SetGearManipulatorRoller(0));

	AddSequential(new DriveStraight(18, 0, .27));
	AddSequential(new SetGearPosition(true));

	AddSequential(new SetDesiredAngle(30));

	AddSequential(new frc::WaitCommand(1.5));
	AddSequential(new Shoot());

	AddSequential(new frc::WaitCommand(5));
	AddSequential(new DriveRotate(-40));
	AddSequential(new StopShoot());
	AddSequential(new DriveStraight(50, 0 , .1));
}
