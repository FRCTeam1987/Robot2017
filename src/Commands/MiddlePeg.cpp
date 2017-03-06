#include "MiddlePeg.h"

#include <DriverStation.h>

MiddlePeg::MiddlePeg(frc::Command *ifTrue, frc::Command *ifFalse) :
	frc::ConditionalCommand(ifTrue, ifFalse)
{

}

bool MiddlePeg::Condition() {
	bool value = frc::DriverStation::GetInstance().GetAlliance() == frc::DriverStation::kRed;
	printf("MiddlePeg::Condition() returns %s\n", value?"true":"false");
	return frc::DriverStation::GetInstance().GetAlliance() == frc::DriverStation::kRed;
}
