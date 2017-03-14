#ifndef SetVisionDefaultCommand_H
#define SetVisionDefaultCommand_H

#include "../../Robot.h"

class SetVisionDefaultCommand : public frc::Command {
private:
	bool m_onOff;
public:
	SetVisionDefaultCommand(bool setOnOff);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SetVisionDefaultCommand_H
