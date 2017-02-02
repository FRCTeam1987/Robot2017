#ifndef SetPTO_H
#define SetPTO_H

#include "WPILib.h"
#include <CANTalon.h>
#include "../../Robot.h"

class SetPTO : public frc::Command {
private:
	bool m_isEnabled;
public:
	SetPTO(bool isEnabled);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SetPTO_H
