#include "OI.h"

#include <WPILib.h>
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/Collector/SetCollector.h"
#include "Commands/DriveTrain/Shift.h"
#include "Commands/DriveTrain/Climb.h"
#include "Commands/GearManipulator/SetGearManipulator.h"
#include "Commands/GearManipulator/SetGearPosition.h"
#include "Commands/Shooter/SetShooter.h"
#include "Commands/Shooter/SetElevator.h"
#include "Commands/Shooter/SetRoller.h"
#include "Commands/Turret/ZeroTurret.h"
#include "Commands/Turret/SetPosition.h"
#include "Commands/PrintStuff.h"

OI::OI() {
	//Collector
	frc::SmartDashboard::PutData("Start Collector", new SetCollector(0.25));
	frc::SmartDashboard::PutData("Stop Collector", new SetCollector(0));

	//Drive Train
	frc::SmartDashboard::PutData("Shift High", new Shift(true));
	frc::SmartDashboard::PutData("Shift Low", new Shift(false));
	frc::SmartDashboard::PutData("Climb", new Climb());

	//Gear Manipulator
	frc::SmartDashboard::PutData("Start Gear Manipulator", new SetGearManipulator(0.25));
	frc::SmartDashboard::PutData("Stop Gear Manipulator", new SetGearManipulator(0));
	frc::SmartDashboard::PutData("Raise Gear", new SetGearPosition(true));
	frc::SmartDashboard::PutData("Lower Gear", new SetGearPosition(false));

	//Shooter
	frc::SmartDashboard::PutData("Start Shooter", new SetShooter(0.25));
	frc::SmartDashboard::PutData("Stop Shooter", new SetShooter(0));
	frc::SmartDashboard::PutData("Start Elevator", new SetElevator(.25));
	frc::SmartDashboard::PutData("Stop Elevator", new SetElevator(0));
	frc::SmartDashboard::PutData("Start Roller", new SetRoller(.25));
	frc::SmartDashboard::PutData("Stop Roller", new SetRoller(0));

	//Turret
	frc::SmartDashboard::PutData("ZeroTurret", new ZeroTurret(.1));
	frc::SmartDashboard::PutData("Set Turret 180", new SetPosition(180));
	frc::SmartDashboard::PutData("Set Turret -180", new SetPosition(-180));

	//PrintStuff
	frc::SmartDashboard::PutData("Print Stuff", new PrintStuff());
}
