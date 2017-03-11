#ifndef RoboLogCommand_H
#define RoboLogCommand_H

#include "../Robot.h"

class RoboLogCommand : public frc::Command {
public:
	RoboLogCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // RoboLogCommand_H
