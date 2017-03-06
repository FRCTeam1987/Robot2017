#ifndef MiddlePeg_H
#define MiddlePeg_H

#include <Commands/ConditionalCommand.h>

class MiddlePeg : public frc::ConditionalCommand {
public:
	MiddlePeg(frc::Command *ifTrue, frc::Command *ifElse);

protected:
	virtual bool Condition();
};

#endif  // MiddlePeg_H
