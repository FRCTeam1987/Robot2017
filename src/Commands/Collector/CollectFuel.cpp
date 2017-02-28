#include "CollectFuel.h"
#include "SetCollectorDefaultCommand.h"
#include "HasBall.h"
#include "../Shooter/SetElevator.h"
#include "RunCollectorUntilNotTripped.h"

CollectFuel::CollectFuel() {
	AddSequential(new SetCollectorDefaultCommand(false));
	AddSequential(new HasBall());
	AddSequential(new SetElevator(-0.5));
	AddSequential(new RunCollectorUntilNotTripped(1));
	AddSequential(new WaitCommand(.5));
	//Removed Wait Due To Jumpy Hopper
	AddSequential(new SetElevator(0));
	AddSequential(new SetCollectorDefaultCommand(true));
}
