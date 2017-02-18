#ifndef HasBall_H
#define HasBall_H

#include "WPILib.h"
#include "../../Robot.h"

class HasBall : public frc::Command {
public:
	HasBall();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // HasBall_H
