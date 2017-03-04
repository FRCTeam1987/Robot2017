#ifndef AnchorTurret_H
#define AnchorTurret_H

#include "WPILib.h"
#include "../../Robot.h"


class AnchorTurret : public frc::Command {
private:
	double m_anchorPoint;
public:
	AnchorTurret(double anchorPoint);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AnchorTurret_H
