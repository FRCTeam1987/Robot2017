#include "Turret.h"
#include "../RobotMap.h"
#include "../Commands/Turret/ZeroTurret.h"
#include "../Commands/Turret/SetPosition.h"
#include "../Commands/Turret/AutoTarget.h"
#include "../Commands/Turret/AnchorTurret.h"

#include "Timer.h"

Turret::Turret() : Subsystem("Turret"), m_history(100) {
	m_angle = 0;
	m_desiredAngle = 0;
	m_tolerance = .030;
	motor = RobotMap::turretMotor;

	m_driveGearDiameter = 1.375;
	m_turretGearDiameter = 13;

	int absolutePosition = motor->GetPulseWidthPosition() & 0xFFF;

	motor->SetEncPosition(absolutePosition);
	motor->SetSensorDirection(true);

//	motor->SetControlMode(CANTalon::kPosition);
	motor->SetTalonControlMode(CANTalon::TalonControlMode::kPositionMode);

	motor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	motor->ConfigLimitMode(frc::CANSpeedController::kLimitMode_SwitchInputsOnly);
	motor->ConfigForwardSoftLimitEnable(true);
	motor->ConfigReverseSoftLimitEnable(true);
//	motor->ConfigForwardLimit(3.399169921875);
//	motor->ConfigReverseLimit(-3.399169921875);
	motor->ConfigNeutralMode(frc::CANSpeedController::NeutralMode::kNeutralMode_Brake);
	motor->SetAllowableClosedLoopErr(0);
	motor->SetClosedLoopOutputDirection(true);
	motor->ConfigPeakOutputVoltage(10, -10); // change this cuz mechanizm is lame //10 comp
//	motor->ConfigNominalOutputVoltage(3, -3);
//	motor->SetPID(.7, 0, 30.0, 0);
//	motor->SetPID(0.1, 0, 2.15, 0);
	motor->SetPID(0.05, 0, 2.25, 0);

	if(motor->IsSensorPresent(CANTalon::CtreMagEncoder_Relative) != CANTalon::FeedbackStatusPresent) {
		printf("Device Error: Could not detect turret encoder.\n");
	}

	ZeroPosition();
}

void Turret::InitDefaultCommand() {
	RobotMap::Log.AddEntry("Turret::InitDefaultCommand()");
	SetDefaultCommand(new AnchorTurret());
//	SetDefaultCommand(new ::AutoTarget());
}

void Turret::SetAbsoluteAngle(double targetAngle)
{
//	printf("SetAbsoluteAngle\n");

	double targetPosition = (targetAngle * m_rotationsToDegrees);//accounts for 10:1 gear ration on turret
	if (targetAngle > 180) {
		targetPosition -= 10.0;
	}

	motor->SetControlMode(CANTalon::kPosition);
//	printf("targetAngle: %3.0f, targetPosition: %4.1f\n", targetAngle, targetPosition);
	if (fabs(targetPosition) > 3.39) {
		return;
	}
	motor->Set(targetPosition);
}

void Turret::SetMyPosition(double deltaAngle) {
	double currentAngle = GetAngle();
	double targetAngle = currentAngle + deltaAngle;
	frc::SmartDashboard::PutNumber("Target Turret Angle", targetAngle);


	double targetPosition = (targetAngle * m_rotationsToDegrees);//accounts for 10:1 gear ration on turret

	motor->SetTalonControlMode(CANTalon::TalonControlMode::kPositionMode);
	motor->Set(targetPosition);
}

void Turret::SetPosition(double angle) {
	motor->SetControlMode(CANTalon::kPosition);

	frc::SmartDashboard::PutNumber("Pre Calc Turret Angle", angle);

	double targetAngle = angle;


	targetAngle = targetAngle - GetHeading(); //Accounts for robot heading

	frc::SmartDashboard::PutNumber("Target Angle First", targetAngle);


	frc::SmartDashboard::PutNumber("Target Angle Second", targetAngle);


	double deltaAngle = fabs(targetAngle - GetHeading());


	bool isCw = GetHeading() > targetAngle;

	if (deltaAngle > 180) {
		if (isCw) {
			deltaAngle = targetAngle - GetHeading() + (targetAngle>GetHeading()?0:360);
		} else {
			deltaAngle = GetHeading() - targetAngle + (GetHeading()>targetAngle?0:360);
		}
		isCw = !isCw;
	}


	frc::SmartDashboard::PutNumber("Target Angle Post Mod", targetAngle);

	if (fabs(targetAngle) > 120 && fabs(targetAngle) < 240) {
		frc::SmartDashboard::PutNumber("Short Circuit Hdg Second", fabs(targetAngle));
		 return;
	}


	m_angle = targetAngle;
	frc::SmartDashboard::PutNumber("Target Turret Angle", targetAngle);
	double targetPosition = (m_angle * m_rotationsToDegrees);//accounts for 10:1 gear ration on turret

	motor->Set(targetPosition);
}

double Turret::GetPosition() {
	return motor->GetPosition();
}

double Turret::GetAngle() {
	return  GetPosition() / m_rotationsToDegrees;
}

double Turret::GetPositionError() {
	return (motor->GetClosedLoopError() / 4096.0); // / m_rotationsToDegrees;
}

bool Turret::isOnTarget() {
	return (fabs(GetPositionError()) <= m_tolerance);
}

void Turret::SetVoltage(double voltage) {
	motor->SetControlMode(CANTalon::kPercentVbus);
	motor->Set(voltage);
}

void Turret::ZeroPosition() {
	motor->SetPosition(0);
}

int Turret::GetForwardLimit() {
	return motor->IsFwdLimitSwitchClosed();
}

int Turret::GetReverseLimit() {
	return motor->IsRevLimitSwitchClosed();
}

double Turret::GetHeading() {
	return Robot::driveTrain.get()->GetAngle();
}

void Turret::UpdateHistory() {
	TimeStampedValue value(GetAngle());
	m_history.Add(value);
}

TimeStampedValue Turret::GetHistory(double timeStamp) {
	return m_history.GetHistory(timeStamp);
}

TimeStampedValue Turret::FetchAngleToGoal() {
	const double defaultAngleToGoal = 0.0;
	const double defaultTimeToFindAngle = 0.0;
	const double timeFromPi = .05;
	const double defaultDistanceToGoal = 0.0;
	const bool targetSeen = false;

	double isTargetSeen = frc::SmartDashboard::GetBoolean("hasTarget", targetSeen) ? 1.0 : 0.0;
	double angleToGoal = frc::SmartDashboard::GetNumber("angle", defaultAngleToGoal);
	double timeOfGoal = frc::SmartDashboard::GetNumber("timeDelta", defaultTimeToFindAngle);
	double distanceToGoal = frc::SmartDashboard::GetNumber("distance", defaultDistanceToGoal);
	double currentTime = frc::Timer::GetFPGATimestamp();
	TimeStampedValue angleToSet = TimeStampedValue(isTargetSeen, angleToGoal, distanceToGoal);
	angleToSet.SetTimeStamp(currentTime - timeOfGoal - timeFromPi);
	return angleToSet;
}

void Turret::SetDesiredAngle(double desiredAngle) {
	const int TURRET_NOGO_LO = -145;
	const int TURRET_NOGO_HI = 145;
	double currentAngle = GetAngle() + desiredAngle;
	printf("desiredAngle: %f, currentTurretAngle: %f, newTurretAngle: %f\n", desiredAngle, GetAngle(), currentAngle);
	if(currentAngle > TURRET_NOGO_LO && currentAngle < TURRET_NOGO_HI) {
		m_desiredAngle = desiredAngle;
	}
}

void Turret::SetDesiredAngle(double desiredAngle, double timeStamp) {
	const int TURRET_NOGO_LO = -145;
	const int TURRET_NOGO_HI = 145;
	TimeStampedValue snapshot = GetHistory(timeStamp);
	double oldAngle = snapshot.GetValue1();
	if(oldAngle == 0.0) {
		return;
	}
	double currentAngle = oldAngle + desiredAngle;
	if(currentAngle > TURRET_NOGO_LO && currentAngle < TURRET_NOGO_HI) {
		m_desiredAngle = desiredAngle;
	}
}

double Turret::GetDesiredAngle() {
	return m_desiredAngle;
}

double Turret::GetOutputVoltage() {
	return motor->GetOutputVoltage();
}

bool Turret::isStill() {
	std::vector<TimeStampedValue> histories = m_history.GetHistories();
	int historySize = histories.size();

	double currentAngle = 0.0;
	double prevAngle = 0.0;

	for (int i = historySize - 3; i < historySize; i++) {
		currentAngle = histories[i].GetValue1();
		if ((currentAngle + 1) >= prevAngle && prevAngle >= (currentAngle - 1)) {
			printf("Not the same");
			return false;
		}
		prevAngle = currentAngle;

	}

	return true;
}
