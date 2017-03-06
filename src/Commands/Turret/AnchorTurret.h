#ifndef AnchorTurret_H
#define AnchorTurret_H

#include "WPILib.h"
#include "../../Robot.h"


class AnchorTurret : public frc::Command {
private:
public:
	AnchorTurret();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AnchorTurret_H
