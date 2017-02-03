#include "OI.h"

#include <WPILib.h>
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/Collector/StartCollector.h"
#include "Commands/Collector/StopCollector.h"
#include "Commands/DriveTrain/TestMotors.h"
#include "Commands/DriveTrain/Shift.h"
#include "Commands/DriveTrain/Climb.h"
#include "Commands/GearManipulator/StartGearManipulator.h"
#include "Commands/GearManipulator/StopGearManipulator.h"
#include "Commands/GearManipulator/SetGearPosition.h"
#include "Commands/Shooter/StartShooter.h"
#include "Commands/Shooter/StopShooter.h"
#include "Commands/Shooter/StartElevator.h"
#include "Commands/Shooter/StopElevator.h"
#include "Commands/Shooter/StartRoller.h"
#include "Commands/Shooter/StopRoller.h"
#include "Commands/PrintStuff.h"


OI::OI() {
	//Collector
	frc::SmartDashboard::PutData("StartCollector", new StartCollector());
	frc::SmartDashboard::PutData("StopCollector", new StopCollector());

	//Drive Train
	frc::SmartDashboard::PutData("TestMotors", new TestMotors(0.5));
	frc::SmartDashboard::PutData("ShiftHigh", new Shift(true));
	frc::SmartDashboard::PutData("ShifthLow", new Shift(false));
	frc::SmartDashboard::PutData("Climb", new Climb());

	//Gear Manipulator
	frc::SmartDashboard::PutData("Start Gear Manipulator", new StartGearManipulator(0.25));
	frc::SmartDashboard::PutData("Stop Gear Manipulator", new StopGearManipulator());
	frc::SmartDashboard::PutData("Raise Gear", new SetGearPosition(true));
	frc::SmartDashboard::PutData("Lower Gear", new SetGearPosition(false));

	//Shooter
	frc::SmartDashboard::PutData("Start Shooter", new StartShooter(0.25));
	frc::SmartDashboard::PutData("Stop Shooter", new StopShooter());
	frc::SmartDashboard::PutData("Start Elevator", new StartElevator(.25));
	frc::SmartDashboard::PutData("Stop Elevator", new StopElevator());
	frc::SmartDashboard::PutData("Start Roller", new StartRoller(.25));
	frc::SmartDashboard::PutData("Stop Roller", new StopRoller());

	//PrintStuff
	frc::SmartDashboard::PutData("PrintStuff", new PrintStuff());

}
