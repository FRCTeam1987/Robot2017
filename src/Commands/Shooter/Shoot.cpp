#include "Shoot.h"
#include "SetShooter.h"
#include "SetShooterPercent.h"
#include "SetRoller.h"
#include "SetElevator.h"
#include "../Collector/SetCollector.h"
#include "../Collector/SetCollectorDefaultCommand.h"

Shoot::Shoot() {
	AddSequential(new SetCollectorDefaultCommand(false));
	AddSequential(new SetShooter(3400)); //3100 RPM for Hopper && 3900 RPM for Gear (~3770 RPM)
	AddSequential(new SetRoller(-0.5));
	AddSequential(new SetElevator(0.95));
	AddSequential(new SetCollector(0.95));
}
