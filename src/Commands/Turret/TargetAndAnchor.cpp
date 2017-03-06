#include "TargetAndAnchor.h"

TargetAndAnchor::TargetAndAnchor() {
	AddSequential(new AutoTarget());
	// TODO: update to use parallel anchoring
//	AddSequential(new AnchorTurret(0, true)); // parameter means nothing currently
}
