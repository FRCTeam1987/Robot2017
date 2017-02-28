#include "CollectGear.h"
#include"SetGearManipulator.h"
#include "SetGearPosition.h"

CollectGear::CollectGear() {
	AddSequential(new SetGearPosition(false));
	AddSequential(new SetGearManipulator(0.75));
	AddSequential(new SetGearPosition(true));
}
