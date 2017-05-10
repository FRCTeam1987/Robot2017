#include "BoilerSidePegBlueAndChuteAuto.h"
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
#include "DriveTrain/Shift.h"

BoilerSidePegBlueAndChuteAuto::BoilerSidePegBlueAndChuteAuto() {
	AddSequential(new Shift(true));
	AddSequential(new ZeroDriveTrain());
	AddSequential(new ZeroTurretEncoder());

	AddSequential(new DriveStraight(-93, 0, -.25));
	AddSequential(new DriveRotate(57));
	AddSequential(new frc::WaitCommand(.25));
	AddSequential(new DriveStraight(-22, 0, -.25));
	AddSequential(new SetGearPosition(false));
	AddSequential(new frc::WaitCommand(.25));
	AddSequential(new SetGearManipulatorRoller(-0.75));
	AddSequential(new frc::WaitCommand(.25));

	AddSequential(new SetGearManipulatorRoller(0));

	AddSequential(new DriveStraight(22, 0, .26));
	AddSequential(new SetShooterPercent(.6));

	AddSequential(new SetGearPosition(true));

	AddSequential(new SetDesiredAngle(-30));

	AddSequential(new frc::WaitCommand(1.5));
	AddSequential(new Shoot());

	AddSequential(new frc::WaitCommand(4));
	AddSequential(new StopShoot());
	AddSequential(new DriveRotate(30));
	AddSequential(new DriveStraight(-50, 0 , -.25));
}
