#ifndef SetCollectorDefaultCommand_H
#define SetCollectorDefaultCommand_H

#include "../../Robot.h"

class SetCollectorDefaultCommand : public frc::Command {
private:
	bool m_setOnOff;
public:
	SetCollectorDefaultCommand(bool setOnOff);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SetCollectorDefaultCommand_H
