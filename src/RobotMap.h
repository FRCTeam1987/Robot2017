#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include <CANTalon.h>
#include <AHRS.h>
#include <navXSensor.h>

class RobotMap {
public:
	//Drive Train
	static std::shared_ptr<CANTalon> driveLeftMaster;
	static std::shared_ptr<CANTalon> driveRightMaster;
	static std::shared_ptr<CANTalon> driveLeftSlave;
	static std::shared_ptr<CANTalon> driveRightSlave;
	static std::shared_ptr<RobotDrive> robotDrive;
	static std::shared_ptr<AHRS> driveAhrs;
	static std::shared_ptr<navXSensor> driveNavx;
	static std::shared_ptr<DoubleSolenoid> driveShifter;


	enum {
		DRIVE_CAN_LEFT_MASTER = 1,
		DRIVE_CAN_RIGHT_MASTER = 2,
		DRIVE_CAN_LEFT_SLAVE = 3,
		DRIVE_CAN_RIGHT_SLAVE = 4,
		DRIVE_PCM_SHIFT_HIGH = 0,
		DRIVE_PCM_SHIFT_LOW = 1,
	};

	//OI
	static std::shared_ptr<frc::XboxController> xbox;

	enum{
		DRIVER_XBOX = 0,
	};

	static void init();
	static void initDriveTrain();
	static void initOI();
};

#endif  // ROBOTMAP_H
