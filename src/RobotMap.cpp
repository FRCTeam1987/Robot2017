#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "Robot.h"

//Collector
std::shared_ptr<Talon> RobotMap::collectorRoller;
std::shared_ptr<frc::DigitalInput> RobotMap::collectorBallSensor;
std::shared_ptr<PDP> RobotMap::collectorPdp;

//Drive Train
std::shared_ptr<CANTalon> RobotMap::driveLeftMaster;
std::shared_ptr<CANTalon> RobotMap::driveRightMaster;
std::shared_ptr<CANTalon> RobotMap::driveLeftSlave;
std::shared_ptr<CANTalon> RobotMap::driveRightSlave;
std::shared_ptr<RobotDrive> RobotMap::robotDrive;
std::shared_ptr<AHRS> RobotMap::driveAhrs;
std::shared_ptr<navXSensor> RobotMap::driveNavx;
std::shared_ptr<DoubleSolenoid> RobotMap::driveShifter;
std::shared_ptr<DoubleSolenoid> RobotMap::climberPTO;
std::shared_ptr<DigitalInput> RobotMap::climberPlateSensor;
std::shared_ptr<frc::Encoder> RobotMap::driveLeftEncoder;
std::shared_ptr<frc::Encoder> RobotMap::driveRightEncoder;
std::shared_ptr<frc::AnalogOutput> RobotMap::driveFlashlight;

//Gear Manipulator
std::shared_ptr<frc::DigitalInput> RobotMap::gearSensor;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::gearLift;
std::shared_ptr<frc::DigitalInput> RobotMap::gearPositionRaised;
std::shared_ptr<frc::DigitalInput> RobotMap::gearPositionLowered;
std::shared_ptr<CANTalon> RobotMap::gearRoller;

//Shooter
std::shared_ptr<CANTalon> RobotMap::shooterWheelMaster;
std::shared_ptr<CANTalon> RobotMap::shooterWheelSlave;
std::shared_ptr<Talon> RobotMap::shooterElevator;
std::shared_ptr<CANTalon> RobotMap::shooterRoller;

//Turret
std::shared_ptr<CANTalon> RobotMap::turretMotor;

//OI
std::shared_ptr<frc::XboxController> RobotMap::xbox;
std::shared_ptr<frc::XboxController> RobotMap::co;

//Logging
RoboLog RobotMap::Log;

void RobotMap::init() {
	initCollector();
	initDriveTrain();
	initGearManipulator();
	initShooter();
	initTurret();
	initOI();
}

void RobotMap::initCollector() {
	collectorRoller.reset(new Talon(COLLECTOR_PWM_ROLLER));
	collectorBallSensor.reset(new DigitalInput(COLLECTOR_DIO_BALL));
	collectorPdp.reset(new PDP(COLLECTOR_PDP));
}

void RobotMap::initDriveTrain() {
	LiveWindow *lw = LiveWindow::GetInstance();

	const int wheelDiameter = 4;

	const double PI = 3.141593;

	const int ENCODER_TICKS = 1023; //change value

	driveLeftMaster.reset(new CANTalon(DRIVE_CAN_LEFT_MASTER));  // Green motor
	lw->AddActuator("Drive Train", "Left Master", driveLeftMaster);
	driveLeftMaster.get()->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Brake);

	driveRightMaster.reset(new CANTalon(DRIVE_CAN_RIGHT_MASTER));
	lw->AddActuator("Drive Train", "Right Master", driveRightMaster);
	driveRightMaster.get()->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Brake);


	driveLeftSlave.reset(new CANTalon(DRIVE_CAN_LEFT_SLAVE));  // Yellow motor
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

	climberPTO.reset(new DoubleSolenoid(CLIMBER_PCM_LEFTPTO, CLIMBER_PCM_RIGHTPTO));
	lw->AddActuator("Climber", "Climber PTO", climberPTO);

	climberPlateSensor.reset(new DigitalInput(CLIMBER_DIO_PLATE));
	lw->AddSensor("Climber", "Is Plate Touched", climberPlateSensor);

	driveLeftEncoder.reset(new Encoder(DRIVE_DIO_LEFT_ENCODER_A, DRIVE_DIO_LEFT_ENCODER_B));
	driveLeftEncoder->SetDistancePerPulse((PI * wheelDiameter) / ENCODER_TICKS);
	lw->AddActuator("DriveTrain", "left Drive Encoder", driveLeftEncoder);

	driveRightEncoder.reset(new Encoder(DRIVE_DIO_RIGHT_ENCODER_A, DRIVE_DIO_RIGHT_ENCODER_B));
	driveRightEncoder->SetDistancePerPulse((PI * wheelDiameter) / ENCODER_TICKS);
	lw->AddActuator("DriveTrain", "right Drive Encoder", driveRightEncoder);

	driveFlashlight.reset(new frc::AnalogOutput(DRIVE_AIO_FLASHLIGHT));
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

	gearLift.reset(new DoubleSolenoid(GEAR_PCM_TOPLIFT, GEAR_PCM_BOTTOMLIFT));
	lw->AddActuator("Gear Manipulator", "Gear Lift", gearLift);
}

void RobotMap::initShooter() {
	LiveWindow *lw = LiveWindow::GetInstance();

	shooterWheelMaster.reset(new CANTalon(SHOOTER_CAN_WHEEL_MASTER));
	shooterWheelMaster.get()->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Coast);
	lw->AddActuator("Shooter", "Wheel Master", shooterWheelMaster);

	shooterWheelSlave.reset(new CANTalon(SHOOTER_CAN_WHEEL_SLAVE));
	shooterWheelSlave.get()->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Coast);
	shooterWheelSlave.get()->SetControlMode(CANTalon::kFollower);
	shooterWheelSlave.get()->Set(SHOOTER_CAN_WHEEL_MASTER);
	lw->AddActuator("Shooter", "Wheel Slave", shooterWheelSlave);

	shooterElevator.reset(new Talon(SHOOTER_PWM_ELEVATOR));
	lw->AddActuator("Shooter", "Elevator", shooterElevator);

	shooterRoller.reset(new CANTalon(SHOOTER_CAN_ROLLER));
	lw->AddActuator("Shooter", "Roller", shooterRoller);
}

void RobotMap::initTurret() {
	LiveWindow *lw = LiveWindow::GetInstance();

	turretMotor.reset(new CANTalon(TURRET_CAN_MOTOR));
	lw->AddActuator("Turret", "Motor", turretMotor);

}

void RobotMap::initOI() {
	xbox.reset(new frc::XboxController(DRIVER_XBOX));
	co.reset(new frc::XboxController(CODRIVER_CO));
}
