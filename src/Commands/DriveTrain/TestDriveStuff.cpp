#include "TestDriveStuff.h"

#include "ZeroDriveTrain.h"
#include "DriveStraight.h"
#include "DriveArcPower.h"

TestDriveStuff::TestDriveStuff() {
	AddSequential(new ZeroDriveTrain());
	AddSequential(new DriveStraight(48, 0, 0.675)); //Tweak On Proper Field
	AddSequential(new DriveArcPower(true, 30));
	AddSequential(new ZeroDriveTrain());
//	AddSequential(new DriveArcPower(false));
	AddSequential(new DriveStraight(48, 0.675, 0)); //Tweak On Proper Field
}
