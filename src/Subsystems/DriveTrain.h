#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include <navXSensor.h>
#include <CANTalon.h>
#include <AHRS.h>

class DriveTrain : public frc::PIDSubsystem {
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
	std::shared_ptr<frc::Encoder> leftEncoder;
	std::shared_ptr<frc::Encoder> rightEncoder;
	double m_output;
	double m_autoSpeed;

public:
	DriveTrain();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	void DriveArcade(frc::XboxController *xbox);
	void DriveTank(float left, float right);
	void Shift(bool isHighGear);
	void SetPTO(bool isEnabled);
	bool IsTouchingPlate();
	double GetLeftEncoderDistance();
	double GetRightEncoderDistance();
	double GetAngle();
	void ZeroAngle();
	void ZeroEncoders();
	double GetHeadingChange();
	void AutoDrive(float move, float rotate);
	void SetAutoSpeed(double autoSpeed);
	void SetSetpoint(double setpoint);
	void SetBrake();
	void SetCoast();
};

#endif  // DriveTrain_H
