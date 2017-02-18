#include "StopShoot.h"
#include "SetShooter.h"
#include "SetShooterPercent.h"
#include "SetRoller.h"
#include "SetElevator.h"
#include "../Collector/SetCollector.h"
#include "../Collector/SetCollectorDefaultCommand.h"

StopShoot::StopShoot() {
	AddSequential(new SetCollectorDefaultCommand(true));
	AddSequential(new SetShooter(0));
	AddSequential(new SetRoller(0));
	AddSequential(new SetElevator(0));
	AddSequential(new SetCollector(0));
}
