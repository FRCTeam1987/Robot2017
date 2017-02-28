#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include <navXSensor.h>
#include <CANTalon.h>
#include <AHRS.h>
#include "../Lib/TimeStampedHistory.h"

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
	double m_autoTurn;
	double m_headingOffset;
	double m_azimuth;
	bool m_isHigh;
	std::vector<double> m_recentHeadings;
	ADXRS450_Gyro* gyro;
	TimeStampedHistory m_history;

	double GetRecentHeadingChange();

public:
	DriveTrain();
	void ClearRecentHeadings() { m_recentHeadings.clear(); }
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	void DriveArcade(frc::XboxController *xbox);
	void DriveTank(float left, float right);
	void Shift(bool isHighGear);
	void SetPTO(bool isEnabled);
	bool IsTouchingPlate();
	bool IsRotating();
	double GetLeftEncoderDistance();
	double GetRightEncoderDistance();
	float GetAngle();
	void ZeroAngle();
	void ZeroEncoders();
	float GetHeadingChange();
	void AutoDrive(float move, float rotate);
	void SetAutoSpeed(double autoSpeed);
	void SetAutoTurn(float autoTurn);
	void SetSetpoint(double setpoint);
	void SetBrake();
	void SetCoast();
	void ResetHeadingOffset();
	void SetAzimuth(double azimuth);
	double GetAzimuth();
	double GetGyroAngle();
	void ResetGyro();
	void UpdateHistory();
	TimeStampedValue GetHistory(double timeStamp);
	void ToggleShift();
};

#endif  // DriveTrain_H
