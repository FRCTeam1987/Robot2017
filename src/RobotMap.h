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
		COLLECTOR_CAN_ROLLER = 11,
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
	static std::shared_ptr<DoubleSolenoid> climberPTO;
	static std::shared_ptr<frc::DigitalInput> climberPlateSensor;

	enum {
		DRIVE_CAN_LEFT_MASTER = 1,
		DRIVE_CAN_RIGHT_MASTER = 2,
		DRIVE_CAN_LEFT_SLAVE = 3,
		DRIVE_CAN_RIGHT_SLAVE = 4,
		DRIVE_PCM_SHIFT_HIGH = 0,
		DRIVE_PCM_SHIFT_LOW = 1,
		CLIMBER_PCM_LEFTPTO = 3,
		CLIMBER_PCM_RIGHTPTO = 4,
		CLIMBER_DIO_PLATE = 11,
	};

	//Gear Manipulator
	static std::shared_ptr<frc::DigitalInput> gearSensor;
	static std::shared_ptr<frc::Solenoid> gearLift;
	static std::shared_ptr<frc::DigitalInput> gearPositionRaised;
	static std::shared_ptr<frc::DigitalInput> gearPositionLowered;
	static std::shared_ptr<CANTalon> gearRoller;

	enum {
		GEAR_CAN_ROLLER = 9,
		GEAR_DIO_GEAR = 5,
		GEAR_DIO_POSITION_RAISED = 10,
		GEAR_DIO_POSITION_LOWERED = 8,
		GEAR_PCM_LIFT = 2,
	};

	//Shooter
	static std::shared_ptr<CANTalon> shooterWheel;
	static std::shared_ptr<CANTalon> shooterElevator;
	static std::shared_ptr<CANTalon> shooterRoller;

	enum {
		SHOOTER_CAN_WHEEL = 7,
		SHOOTER_CAN_ELEVATOR = 6,
		SHOOTER_CAN_ROLLER = 5,
	};

	//OI
	static std::shared_ptr<frc::XboxController> xbox;

	enum {
		DRIVER_XBOX = 0,
	};

	static void init();
	static void initCollector();
	static void initDriveTrain();
	static void initGearManipulator();
	static void initShooter();
	static void initClimber();
	static void initOI();
};

#endif  // ROBOTMAP_H
