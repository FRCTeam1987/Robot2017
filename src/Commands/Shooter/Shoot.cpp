#include "Shoot.h"
#include "SetShooter.h"
#include "SetShooterPercent.h"
#include "SetRoller.h"
#include "SetElevator.h"
#include "../Collector/SetCollector.h"
#include "../Collector/SetCollectorDefaultCommand.h"

Shoot::Shoot() {
	AddSequential(new SetCollectorDefaultCommand(false));
	AddSequential(new SetShooter(3000));
	AddSequential(new SetRoller(0.5));
	AddSequential(new SetElevator(0.95));
	AddSequential(new SetCollector(0.95));
}
