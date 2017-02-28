#include "BlueEdgeDriveStationToHopper.h"
#include "ZeroDriveTrain.h"
#include "DriveStraight.h"
#include "DriveRotate.h"
#include "ClearRecentHeadings.h"

BlueEdgeDriveStationToHopper::BlueEdgeDriveStationToHopper() {
	AddSequential(new ZeroDriveTrain());
	AddSequential(new DriveStraight(83, 0, 0)); //Tweak On Proper Field
	AddSequential(new DriveRotate(270));
	AddSequential(new ClearRecentHeadings());
	AddSequential(new DriveStraight(35.5, 0, 0));
}
