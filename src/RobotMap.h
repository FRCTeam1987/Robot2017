
#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include <CANTalon.h>
#include <Talon.h>
#include <AHRS.h>
#include <navXSensor.h>
#include "RoboLog.h"

class RobotMap {
public:
	//Collector
	static std::shared_ptr<Talon> collectorRoller;
	static std::shared_ptr<frc::DigitalInput> collectorBallSensor;

	enum {
		COLLECTOR_PWM_ROLLER = 0,
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
	static std::shared_ptr<frc::Encoder> driveLeftEncoder;
	static std::shared_ptr<frc::Encoder> driveRightEncoder;

	enum {
		DRIVE_CAN_LEFT_MASTER = 1,
		DRIVE_CAN_RIGHT_MASTER = 2,
		DRIVE_CAN_LEFT_SLAVE = 3,
		DRIVE_CAN_RIGHT_SLAVE = 4,
		DRIVE_PCM_SHIFT_HIGH = 4,
		DRIVE_PCM_SHIFT_LOW = 5,
		CLIMBER_PCM_LEFTPTO = 0,
		CLIMBER_PCM_RIGHTPTO = 1,
		CLIMBER_DIO_PLATE = 11,
		DRIVE_DIO_LEFT_ENCODER_A = 0,
		DRIVE_DIO_LEFT_ENCODER_B = 1,
		DRIVE_DIO_RIGHT_ENCODER_A = 2,
		DRIVE_DIO_RIGHT_ENCODER_B = 3,
	};

	//Gear Manipulator
	static std::shared_ptr<frc::DigitalInput> gearSensor;
	static std::shared_ptr<frc::DoubleSolenoid> gearLift;
	static std::shared_ptr<frc::DigitalInput> gearPositionRaised;
	static std::shared_ptr<frc::DigitalInput> gearPositionLowered;
	static std::shared_ptr<CANTalon> gearRoller;

	enum {
		GEAR_CAN_ROLLER = 8,
		GEAR_DIO_GEAR = 5,
		GEAR_DIO_POSITION_RAISED = 10,
		GEAR_DIO_POSITION_LOWERED = 8,
		GEAR_PCM_TOPLIFT = 2,
		GEAR_PCM_BOTTOMLIFT = 3,
	};

	//Shooter
	static std::shared_ptr<CANTalon> shooterWheelMaster;
	static std::shared_ptr<CANTalon> shooterWheelSlave;
	static std::shared_ptr<Talon> shooterElevator;
	static std::shared_ptr<CANTalon> shooterRoller;

	enum {
		SHOOTER_CAN_WHEEL_MASTER = 9,
		SHOOTER_CAN_WHEEL_SLAVE = 7,
		SHOOTER_PWM_ELEVATOR = 1,
		SHOOTER_CAN_ROLLER = 11,
	};

	//Turret
	static std::shared_ptr<CANTalon> turretMotor;

	enum {
		TURRET_CAN_MOTOR = 5,
	};

	//OI
	static std::shared_ptr<frc::XboxController> xbox;
	static std::shared_ptr<frc::XboxController> co;

	enum {
		BUTTON_PLACE_GEAR_XBOX = 4, 	//Y
		BUTTON_SHOOT_XBOX = 6, 			//RB
		BUTTON_STOP_SHOOT_XBOX = 2,		//B
		BUTTON_COLLECT_GEAR_XBOX = 3,	//X
		BUTTON_COLLECT_GEAR_HOPPER = 1, //A
		BUTTON_SHIFT_XBOX = 9,			//LS
		BUTTON_PTO_XBOX = 10, 			//RS
		DRIVER_XBOX = 0,
	};

	enum {
		BUTTON_GEAR_ROLLER_CO = 1,		//A
		BUTTON_REVERSE_BALL_CO = 4,		//Y
		BUTTON_REVERSE_ELEVATOR_CO = 3, //X
		BUTTON_STOP_ALL_CO = 2,			//B
		BUTTON_TURRET_RIGHT_CO = 6,		//RB
		BUTTON_TURRET_LEFT_CO = 5,		//LB
		BUTTON_SHOOT_CO = 8,			//START
		CODRIVER_CO = 1,
	};
	// Logging
	static RoboLog Log;

	static void init();
	static void initCollector();
	static void initDriveTrain();
	static void initGearManipulator();
	static void initShooter();
	static void initTurret();
	static void initOI();
};

#endif  // ROBOTMAP_H
