#include "CollectGear.h"
#include"SetGearManipulator.h"
#include "SetGearPosition.h"
#include "../SetRumble.h"

CollectGear::CollectGear() {
	AddSequential(new SetGearPosition(false));
	AddSequential(new SetGearManipulator(0.75));
	AddParallel(new SetGearPosition(true));
	AddSequential(new SetRumble(1));
	AddSequential(new WaitCommand(1));
	AddSequential(new SetRumble(0));
}
