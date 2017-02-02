#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "Robot.h"

//Collector
std::shared_ptr<CANTalon> RobotMap::collectorRoller;
std::shared_ptr<frc::DigitalInput> RobotMap::collectorBallSensor;

//Drive Train
std::shared_ptr<CANTalon> RobotMap::driveLeftMaster;
std::shared_ptr<CANTalon> RobotMap::driveRightMaster;
std::shared_ptr<CANTalon> RobotMap::driveLeftSlave;
std::shared_ptr<CANTalon> RobotMap::driveRightSlave;
std::shared_ptr<RobotDrive> RobotMap::robotDrive;
std::shared_ptr<AHRS> RobotMap::driveAhrs;
std::shared_ptr<navXSensor> RobotMap::driveNavx;
std::shared_ptr<DoubleSolenoid> RobotMap::driveShifter;

//Gear Manipulator
std::shared_ptr<frc::DigitalInput> RobotMap::gearSensor;
std::shared_ptr<frc::Solenoid> RobotMap::gearLift;
std::shared_ptr<frc::DigitalInput> RobotMap::gearPositionRaised;
std::shared_ptr<frc::DigitalInput> RobotMap::gearPositionLowered;
std::shared_ptr<CANTalon> RobotMap::gearRoller;

//Shooter
std::shared_ptr<CANTalon> RobotMap::shooterWheel;
std::shared_ptr<CANTalon> RobotMap::shooterElevator;
std::shared_ptr<CANTalon> RobotMap::shooterRoller;

//OI
std::shared_ptr<frc::XboxController> RobotMap::xbox;

void RobotMap::init() {
	initCollector();
	initDriveTrain();
	initGearManipulator();
	initShooter();
	initOI();
}

void RobotMap::initCollector() {
	collectorRoller.reset(new CANTalon(COLLECTOR_CAN_ROLLER));
	collectorBallSensor.reset(new DigitalInput(COLLECTOR_DIO_BALL));
}

void RobotMap::initDriveTrain() {
	LiveWindow *lw = LiveWindow::GetInstance();

	driveLeftMaster.reset(new CANTalon(DRIVE_CAN_LEFT_MASTER));
	lw->AddActuator("Drive Train", "Left Master", driveLeftMaster);

	driveRightMaster.reset(new CANTalon(DRIVE_CAN_RIGHT_MASTER));
	lw->AddActuator("Drive Train", "Right Master", driveRightMaster);

	driveLeftSlave.reset(new CANTalon(DRIVE_CAN_LEFT_SLAVE));
	lw->AddActuator("Drive Train", "Left Slave", driveLeftSlave);
	driveLeftSlave.get()->SetControlMode(CANTalon::kFollower);
	driveLeftSlave.get()->Set(DRIVE_CAN_LEFT_MASTER);

	driveRightSlave.reset(new CANTalon(DRIVE_CAN_RIGHT_SLAVE));
	lw->AddActuator("Drive Train", "Right Slave", driveRightSlave);
	driveRightSlave.get()->SetControlMode(CANTalon::kFollower);
	driveRightSlave.get()->Set(DRIVE_CAN_RIGHT_MASTER);

	robotDrive.reset(new RobotDrive(driveLeftMaster, driveRightMaster));
	robotDrive.get()->SetSafetyEnabled(false);

	driveAhrs.reset(new AHRS(frc::SerialPort::kMXP));

	driveShifter.reset(new DoubleSolenoid(DRIVE_PCM_SHIFT_HIGH, DRIVE_PCM_SHIFT_LOW));
}

void RobotMap::initGearManipulator() {
	LiveWindow *lw = LiveWindow::GetInstance();

	gearRoller.reset(new CANTalon(GEAR_CAN_ROLLER));
	lw->AddActuator("Gear Manipulator", "Roller", gearRoller);

	gearSensor.reset(new DigitalInput(GEAR_DIO_GEAR));
	lw->AddSensor("Gear Manipulator", "Has Gear Sensor", gearSensor);

	gearPositionRaised.reset(new DigitalInput(GEAR_DIO_POSITION_RAISED));
	lw->AddSensor("Gear Manipulator", "Is Gear Raised", gearPositionRaised);

	gearPositionLowered.reset(new DigitalInput(GEAR_DIO_POSITION_LOWERED));
	lw->AddSensor("Gear Manipulator", "Is Gear Lowered", gearPositionLowered);

	gearLift.reset(new Solenoid(GEAR_PCM_LIFT));
	lw->AddActuator("Gear Manipulator", "Gear Lift", gearLift);
}

void RobotMap::initShooter() {
	LiveWindow *lw = LiveWindow::GetInstance();

	shooterWheel.reset(new CANTalon(SHOOTER_CAN_WHEEL));
	lw->AddActuator("Shooter", "Wheel", shooterWheel);

	shooterElevator.reset(new CANTalon(SHOOTER_CAN_ELEVATOR));
	lw->AddActuator("Shooter", "Elevator", shooterElevator);

	shooterRoller.reset(new CANTalon(SHOOTER_CAN_ROLLER));
	lw->AddActuator("Shooter", "Roller", shooterRoller);
}

void RobotMap::initOI() {
	xbox.reset(new frc::XboxController(DRIVER_XBOX));
}