#include "Climb.h"
#include "SetPTO.h"
#include "ClimbToPlate.h"

Climb::Climb() {
	AddSequential(new SetPTO(true));
	AddSequential(new ClimbToPlate(0.5));
	AddSequential(new SetPTO(false));
}
