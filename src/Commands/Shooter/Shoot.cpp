#include "Shoot.h"
#include "SetShooter.h"
#include "SetShooterPercent.h"
#include "SetRoller.h"
#include "SetElevator.h"
#include "../Collector/SetCollector.h"
#include "../Collector/SetCollectorDefaultCommand.h"
#include "ShootDistance.h"
#include "../Turret/WaitForOnTarget.h"

Shoot::Shoot() {
//	AddSequential(new WaitForOnTarget());
	AddSequential(new SetCollectorDefaultCommand(false));
	AddSequential(new ShootDistance()); //3100 RPM for Hopper && 3900 RPM for Gear (~3770 RPM)
	AddSequential(new SetRoller(-0.5));
	AddSequential(new SetElevator(0.95));
	AddSequential(new SetCollector(0.95));
}
void Shoot::Initialize() {
	RobotMap::Log.AddEntry("Shoot::Initialize()");

}
void Shoot::End() {
	RobotMap::Log.AddEntry("Shoot::End()");

}
