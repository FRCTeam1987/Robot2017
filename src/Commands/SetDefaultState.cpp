#include "SetDefaultState.h"
#include "Collector/SetCollector.h"
#include "Shooter/SetElevator.h"
#include "Shooter/SetRoller.h"
#include "Shooter/SetShooter.h"
#include "Shooter/SetShooterPercent.h"
#include "GearManipulator/SetGearManipulator.h"
#include "GearManipulator/SetGearPosition.h"
#include "Collector/SetCollectorDefaultCommand.h"


SetDefaultState::SetDefaultState() {
	AddSequential(new SetShooterPercent(0.0));
	AddSequential(new SetRoller(0));
	AddSequential(new SetElevator(0));
	AddSequential(new SetCollector(0));
	AddSequential(new SetGearManipulator(0));
	AddSequential(new SetGearPosition(false));
	AddSequential(new SetCollectorDefaultCommand(true));
//	AddSequential();
}
