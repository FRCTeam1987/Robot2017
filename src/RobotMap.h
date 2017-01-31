#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include <CANTalon.h>
#include <AHRS.h>
#include <navXSensor.h>

class RobotMap {
public:
	//Collector
	static std::shared_ptr<CANTalon> collectorRoller;
	static std::shared_ptr<frc::DigitalInput> collectorBallSensor;

	enum {
		COLLECTOR_CAN_ROLLER = 6,
		COLLECTOR_DIO_BALL = 4,
	};

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

	//Gear Manipulator
	static std::shared_ptr<frc::DigitalInput> gearSensor;
	static std::shared_ptr<frc::Solenoid> gearLift;
	static std::shared_ptr<frc::DigitalInput> gearPositionRaised;
	static std::shared_ptr<frc::DigitalInput> gearPositionLowered;
	static std::shared_ptr<CANTalon> gearRoller;

	enum {
		GEAR_CAN_ROLLER = 5,
		GEAR_DIO_GEAR = 5,
		GEAR_DIO_POSITION_RAISED = 6,
		GEAR_DIO_POSITION_LOWERED = 7,
		GEAR_PCM_LIFT = 2,
	};

	//OI
	static std::shared_ptr<frc::XboxController> xbox;

	enum{
		DRIVER_XBOX = 0,
	};

	static void init();
	static void initCollector();
	static void initDriveTrain();
	static void initGearManipulator();
	static void initOI();
};

#endif  // ROBOTMAP_H
