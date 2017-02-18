#ifndef ZeroTurretEncoder_H
#define ZeroTurretEncoder_H

#include "../../Robot.h"

class ZeroTurretEncoder : public frc::Command {
public:
	ZeroTurretEncoder();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ZeroTurretEncoder_H
