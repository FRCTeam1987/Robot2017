#include "ZeroAndMove.h"
#include "SetTurretPercent.h"
#include "ZeroTurret.h"

ZeroAndMove::ZeroAndMove() {
	AddSequential(new ZeroTurret(.25));
	AddSequential(new SetTurretPercent(-.1));
	AddSequential(new WaitCommand(.5));
	AddSequential(new SetTurretPercent(0));
}
