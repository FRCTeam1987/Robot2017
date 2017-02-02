#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include <navXSensor.h>
#include <CANTalon.h>
#include <AHRS.h>

class DriveTrain : public frc::Subsystem {
private:
	std::shared_ptr<CANTalon> leftMaster;
	std::shared_ptr<CANTalon> rightMaster;
	std::shared_ptr<CANTalon> leftSlave;
	std::shared_ptr<CANTalon> rightSlave;
	std::shared_ptr<RobotDrive> robotDrive;
	std::shared_ptr<AHRS> ahrs;
	std::shared_ptr<navXSensor> navx;
	std::shared_ptr<DoubleSolenoid> shifter;
	std::shared_ptr<frc::DoubleSolenoid> PTO;
	std::shared_ptr<frc::DigitalInput> plateSensor;

public:
	DriveTrain();
	void InitDefaultCommand();
	void DriveArcade(frc::XboxController *xbox);
	void Shift(bool isHighGear);
	void StartMotor(float percent);
	void StopMotor();
	void SetPTO(bool isEnabled);
	bool IsTouchingPlate();
};

#endif  // DriveTrain_H
