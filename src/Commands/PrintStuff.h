#ifndef PrintStuff_H
#define PrintStuff_H

#include "WPILib.h"
#include <CANTalon.h>
#include "../Robot.h"

class PrintStuff : public frc::Command {
public:
	PrintStuff();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // PrintStuff_H
