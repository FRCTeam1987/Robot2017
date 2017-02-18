#include "OI.h"

#include <WPILib.h>
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/Collector/SetCollector.h"
#include "Commands/Collector/ShowHasBall.h"
#include "Commands/DriveTrain/Shift.h"
#include "Commands/DriveTrain/Climb.h"
#include "Commands/GearManipulator/SetGearManipulator.h"
#include "Commands/GearManipulator/SetGearPosition.h"
#include "Commands/GearManipulator/CollectGear.h"
#include "Commands/GearManipulator/PlaceGear.h"
#include "Commands/Shooter/SetShooter.h"
#include "Commands/Shooter/SetElevator.h"
#include "Commands/Shooter/SetRoller.h"
#include "Commands/Shooter/Shoot.h"
#include "Commands/Shooter/SetShooterPercent.h"
#include "Commands/Turret/ZeroTurret.h"
#include "Commands/Turret/SetTurretPercent.h"
#include "Commands/PrintStuff.h"
#include "Commands/Turret/SetPosition.h"
#include "Commands/DriveTrain/UpdateSmartDashboard.h"
#include "Commands/DriveTrain/ZeroDriveTrain.h"
#include "Commands/DriveTrain/DriveStraight.h"
#include "Commands/DriveTrain/DriveArc.h"
#include "Commands/Shooter/StopShoot.h"
#include "Commands/SetDefaultState.h"
#include "Commands/Turret/ZeroAndMove.h"
#include "Commands/Turret/ZeroTurretEncoder.h"
#include "Commands/Turret/AddToCurrentAngle.h"

OI::OI() {
	//Collector
	frc::SmartDashboard::PutData("Start Collector", new SetCollector(0.95));
	frc::SmartDashboard::PutData("Reverse Collector", new SetCollector(-0.95));
	frc::SmartDashboard::PutData("Stop Collector", new SetCollector(0));
	frc::SmartDashboard::PutData("Show Has Ball Sensor", new ShowHasBall());

	//Drive Train
	frc::SmartDashboard::PutData("Shift High", new Shift(true));
	frc::SmartDashboard::PutData("Shift Low", new Shift(false));
	frc::SmartDashboard::PutData("Climb", new Climb());
	frc::SmartDashboard::PutData("Update Smart Dash Board", new UpdateSmartDashboard());
	frc::SmartDashboard::PutData("Zero Sensors", new ZeroDriveTrain());
	frc::SmartDashboard::PutData("Drive 4 feet", new DriveStraight(-48, 0, 0));
	frc::SmartDashboard::PutData("Drive 8 feet", new DriveStraight(96, 0, 0));
	frc::SmartDashboard::PutData("Drive Arc", new DriveArc(0, 0, 36, 45));

	//Gear Manipulator
	frc::SmartDashboard::PutData("Start Gear Manipulator", new SetGearManipulator(0.75));
	frc::SmartDashboard::PutData("Stop Gear Manipulator", new SetGearManipulator(0));
	frc::SmartDashboard::PutData("Raise Gear", new SetGearPosition(true));
	frc::SmartDashboard::PutData("Lower Gear", new SetGearPosition(false));
	frc::SmartDashboard::PutData("Collect Gear", new CollectGear());
	frc::SmartDashboard::PutData("Place Gear", new PlaceGear());

	//Shooter
	frc::SmartDashboard::PutData("Stop Shooter", new SetShooter(0));
	frc::SmartDashboard::PutData("Shooter RPM 2500", new SetShooter(2500));
	frc::SmartDashboard::PutData("Shooter RPM 1000", new SetShooter(1000));
	frc::SmartDashboard::PutData("Shooter RPM 0", new SetShooter(0));
	frc::SmartDashboard::PutData("Start Elevator", new SetElevator(.75));
	frc::SmartDashboard::PutData("Stop Elevator", new SetElevator(0));
	frc::SmartDashboard::PutData("Start Roller", new SetRoller(.5));
	frc::SmartDashboard::PutData("Stop Roller", new SetRoller(0));
	frc::SmartDashboard::PutData("Shoot", new Shoot());
	frc::SmartDashboard::PutData("Stop Shooter Sequence", new StopShoot());
	frc::SmartDashboard::PutData("Set Shooter Percent (Hard Coded)", new SetShooterPercent());
	frc::SmartDashboard::PutData("Zero Turret Encoder", new ZeroTurretEncoder());

	//Turret
	frc::SmartDashboard::PutData("ZeroTurret", new ZeroTurret(.2));
	frc::SmartDashboard::PutData("Set Turret 180", new SetPosition(180));
	frc::SmartDashboard::PutData("Set Turret -180", new SetPosition(-180));
	frc::SmartDashboard::PutData("Set Turret 100", new SetPosition(100));
	frc::SmartDashboard::PutData("Set Turret 50", new SetPosition(50));
	frc::SmartDashboard::PutData("Set Turret 90", new SetPosition(90));
	frc::SmartDashboard::PutData("Set Turret -90", new SetPosition(-90));
	frc::SmartDashboard::PutData("Set Turret 270", new SetPosition(270));


	frc::SmartDashboard::PutData("Turret Angle +5", new AddToCurrentAngle(5));
	frc::SmartDashboard::PutData("Turret Angle -5", new AddToCurrentAngle(-5));

	frc::SmartDashboard::PutData("Turret Angle +1", new AddToCurrentAngle(1));
	frc::SmartDashboard::PutData("Turret Angle -1", new AddToCurrentAngle(-1));

	frc::SmartDashboard::PutData("Turret Angle +2", new AddToCurrentAngle(2));
	frc::SmartDashboard::PutData("Turret Angle -2", new AddToCurrentAngle(-2));


	frc::SmartDashboard::PutData("Set Turret 0", new SetPosition(0));

	frc::SmartDashboard::PutData("Zero Turret And Move", new ZeroAndMove());

	frc::SmartDashboard::PutData("Set Turret Speed To 0.5", new SetTurretPercent(0.5));
	frc::SmartDashboard::PutData("Set Turret Speed To -0.5", new SetTurretPercent(-0.5));

	//PrintStuff
	frc::SmartDashboard::PutData("Print Stuff", new PrintStuff());

	//All
	frc::SmartDashboard::PutData("Set Default State", new SetDefaultState());
}
