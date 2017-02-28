#include "PlaceGearFromDriveStation.h"
#include "ClearRecentHeadings.h"
#include "ZeroDriveTrain.h"
#include "DriveStraight.h"
#include "DriveRotate.h"

PlaceGearFromDriveStation::PlaceGearFromDriveStation() {
	AddSequential(new ClearRecentHeadings());
	AddSequential(new ZeroDriveTrain());
	AddSequential(new DriveStraight(-95, 0, 0));
	AddSequential(new DriveRotate(50));
	AddSequential(new ClearRecentHeadings());
	AddSequential(new DriveStraight(12, 0, 0));
}
