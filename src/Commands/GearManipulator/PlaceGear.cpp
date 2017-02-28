#include "PlaceGear.h"

#include "SetGearManipulatorRoller.h"
#include "SetGearPosition.h"

PlaceGear::PlaceGear() {
	AddSequential(new SetGearPosition(false));
	AddSequential(new WaitCommand(.25));
	AddSequential(new SetGearManipulatorRoller(-0.75));
	AddSequential(new WaitCommand(1));
	AddSequential(new SetGearManipulatorRoller(0));
	AddSequential(new SetGearPosition(true));
}
