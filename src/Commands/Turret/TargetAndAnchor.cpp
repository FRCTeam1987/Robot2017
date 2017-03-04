#include "TargetAndAnchor.h"

TargetAndAnchor::TargetAndAnchor() {
	AddSequential(new AutoTarget());
	AddSequential(new AnchorTurret(20)); // parameter means nothing currently
}
