#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "Robot.h"

//Collector
std::shared_ptr<CANTalon> RobotMap::collectorRoller;

//DriveTrain
std::shared_ptr<CANTalon> RobotMap::driveLeftMaster;
std::shared_ptr<CANTalon> RobotMap::driveRightMaster;
std::shared_ptr<CANTalon> RobotMap::driveLeftSlave;
std::shared_ptr<CANTalon> RobotMap::driveRightSlave;
std::shared_ptr<RobotDrive> RobotMap::robotDrive;
std::shared_ptr<AHRS> RobotMap::driveAhrs;
std::shared_ptr<navXSensor> RobotMap::driveNavx;
std::shared_ptr<DoubleSolenoid> RobotMap::driveShifter;

//OI
std::shared_ptr<frc::XboxController> RobotMap::xbox;

void RobotMap::init() {
	initCollector();
	initDriveTrain();
	initOI();
}

void RobotMap::initCollector() {
	collectorRoller.reset(new CANTalon(COLLECTOR_CAN_ROLLER));
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

void RobotMap::initOI() {
	xbox.reset(new frc::XboxController(DRIVER_XBOX));
}


