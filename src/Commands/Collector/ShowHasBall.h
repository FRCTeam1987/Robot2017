#ifndef ShowHasBall_H
#define ShowHasBall_H

#include "WPILib.h"
#include "../../Robot.h"

class ShowHasBall : public frc::Command {
public:
	ShowHasBall();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ShowHasBall_H
