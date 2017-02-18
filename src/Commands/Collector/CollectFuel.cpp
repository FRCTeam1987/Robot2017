#include "../Shooter/SetElevator.h"
#include "CollectFuel.h"
#include "HasBall.h"
#include "SetCollector.h"

CollectFuel::CollectFuel() {
	AddSequential(new HasBall());
	AddSequential(new SetElevator(-0.5));
	AddSequential(new SetCollector(0.9));
	AddSequential(new WaitCommand(1)); //Was 0.25
	AddSequential(new SetCollector(0));
	AddSequential(new SetElevator(0));
}
