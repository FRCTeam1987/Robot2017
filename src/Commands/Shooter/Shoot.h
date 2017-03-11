#ifndef Shoot_H
#define Shoot_H

#include <Commands/CommandGroup.h>

class Shoot : public frc::CommandGroup {
public:
	Shoot();
	void Initialize();
	void End();
};

#endif  // Shoot_H
