#include "OI.h"

#include <WPILib.h>
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/Collector/StartCollector.h"
#include "Commands/Collector/StopCollector.h"
#include "Commands/DriveTrain/TestMotors.h"
#include "Commands/DriveTrain/Shift.h"
#include "Commands/GearManipulator/StartGearManipulator.h"
#include "Commands/GearManipulator/StopGearManipulator.h"
#include "Commands/GearManipulator/SetGearPosition.h"


OI::OI() {
	//Collector
	frc::SmartDashboard::PutData("StartCollector", new StartCollector());
	frc::SmartDashboard::PutData("StopCollector", new StopCollector());

	//Drive Train
	frc::SmartDashboard::PutData("TestMotors", new TestMotors());
	frc::SmartDashboard::PutData("ShiftHigh", new Shift(true));
	frc::SmartDashboard::PutData("ShifthLow", new Shift(false));

	//Gear Manipulator
	frc::SmartDashboard::PutData("Start Gear Manipulator", new StartGearManipulator(0.25));
	frc::SmartDashboard::PutData("Stop Gear Manipulator", new StopGearManipulator());
	frc::SmartDashboard::PutData("Raise Gear", new SetGearPosition(true));
	frc::SmartDashboard::PutData("Lower Gear", new SetGearPosition(false));
}
