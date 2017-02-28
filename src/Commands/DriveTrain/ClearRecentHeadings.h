#ifndef ClearRecentHeadings_H
#define ClearRecentHeadings_H

#include "WPILib.h"
#include "../../Robot.h"

class ClearRecentHeadings : public frc::Command {
public:
	ClearRecentHeadings();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ClearRecentHeadings_H
