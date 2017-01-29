#include "OI.h"

#include <WPILib.h>
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/DriveTrain/TestMotors.h"
#include "Commands/DriveTrain/Shift.h"
#include "Commands/Collector/StartCollector.h"
#include "Commands/Collector/StopCollector.h"


OI::OI() {
	frc::SmartDashboard::PutData("TestMotors", new TestMotors());
	frc::SmartDashboard::PutData("ShiftHigh", new Shift(true));
	frc::SmartDashboard::PutData("ShifthLow", new Shift(false));
	frc::SmartDashboard::PutData("StartCollector", new StartCollector());
	frc::SmartDashboard::PutData("StopCollector", new StopCollector());
}
