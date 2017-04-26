#include "StopShoot.h"
#include "SetShooter.h"
#include "SetShooterPercent.h"
#include "SetRoller.h"
#include "SetElevator.h"
#include "../Collector/SetCollector.h"
#include "../Collector/SetCollectorDefaultCommand.h"
#include "../Vision/SetVisionDefaultCommand.h"

StopShoot::StopShoot() {
	AddSequential(new SetVisionDefaultCommand(true));
//	AddSequential(new SetCollectorDefaultCommand(true));
	AddSequential(new SetRoller(0));
	AddSequential(new SetElevator(0));

	AddSequential(new SetShooter(0));
	AddParallel(new SetCollector(0));

}
