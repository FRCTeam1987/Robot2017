#include "OI.h"

#include <WPILib.h>
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/DriveTrain/TestMotors.h"
#include "Commands/DriveTrain/Shift.h"

OI::OI() {
	frc::SmartDashboard::PutData("TestMotors", new TestMotors());
	frc::SmartDashboard::PutData("ShiftHigh", new Shift(true));
	frc::SmartDashboard::PutData("ShifthLow", new Shift(false));
}
