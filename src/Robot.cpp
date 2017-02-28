#include "Robot.h"
#include <Timer.h>

std::shared_ptr<Collector> Robot::collector;
std::shared_ptr<DriveTrain> Robot::driveTrain;
std::shared_ptr<GearManipulator> Robot::gearManipulator;
std::shared_ptr<Shooter> Robot::shooter;
std::shared_ptr<Turret> Robot::turret;
std::unique_ptr<OI> Robot::oi;

void Robot::RobotInit() {
	RobotMap::init();
	collector.reset(new Collector());
    driveTrain.reset(new DriveTrain());
    gearManipulator.reset(new GearManipulator());
    shooter.reset(new Shooter());
    turret.reset(new Turret());
	oi.reset(new OI());
}

void Robot::DisabledInit() {
}

void Robot::DisabledPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	if (autonomousCommand.get() != nullptr) {
		driveTrain.get()->SetBrake();
		autonomousCommand->Start();
	}
}

void Robot::AutonomousPeriodic() {
//	frc::Scheduler::GetInstance()->Run();
	double initialSpeed = 0;
	double finalSpeed = 0;
	double radius = 36;
	double angle = 45;

	double m_robotWidth = 25.25;

	double m_radius = radius;
	double m_angle = (3.14/180)*(angle);
	double m_currentSpeed = 0;
	double m_currentAngle = 0;
	double m_isDec = false;
	double m_initialSpeed = initialSpeed;
	double m_finalSpeed = finalSpeed;
	double m_initialAngle = 0;
	double m_desiredAngle = angle;
	double m_isClockwise = false;



	m_initialSpeed = .75;

	double m_leftRadius = radius - (m_robotWidth/2);
	double m_rightRadius = radius + (m_robotWidth/2);

	double m_leftDistance = m_leftRadius * m_angle;
	double m_rightDistance = m_rightRadius * m_angle;

	double m_distance = (m_leftDistance + m_rightDistance) / 2;

	m_currentSpeed = m_initialSpeed;
	Robot::driveTrain.get()->ZeroEncoders();
//	Robot::driveTrain.get()->ZeroAngle();
	m_initialAngle = Robot::driveTrain->GetAngle();
	if(m_desiredAngle - m_initialAngle > 0) {
		m_isClockwise = m_desiredAngle - m_initialAngle < 180;
	} else {
		m_isClockwise = m_initialAngle - m_desiredAngle > 180;
	}
	Robot::driveTrain.get()->SetAutoSpeed(m_currentSpeed);
	Robot::driveTrain.get()->SetSetpoint(m_currentAngle);
	Robot::driveTrain.get()->Enable();

	while(1) {
		double deltaSpeed = m_currentSpeed - m_finalSpeed;
			double currentAverageDistance = (Robot::driveTrain.get()->GetLeftEncoderDistance() + Robot::driveTrain.get()->GetRightEncoderDistance()) / 2;
			double deltaDistance = m_distance - currentAverageDistance;
		//	double currentRatio = deltaSpeed / deltaDistance;

			double percentDriven = currentAverageDistance / m_distance;

			printf("Percent Driven: %f\n", percentDriven);
			m_currentAngle = percentDriven * (m_angle * (180 / 3.14));



//			printf("Current Target Angle: %f Current Angle: %f Percent Driven: %f\n", m_currentAngle, Robot::driveTrain.get()->GetAngle(), percentDriven);
			printf("Timestamp %f\n", Timer::GetFPGATimestamp());

			Robot::driveTrain.get()->SetAutoSpeed(m_currentSpeed);
			Robot::driveTrain.get()->SetSetpoint(m_currentAngle);

			if (angle <= Robot::driveTrain.get()->GetAngle()) {
				break;
			}

			Wait(0.05);


	}
	Robot::driveTrain.get()->Disable();
	Robot::driveTrain.get()->AutoDrive(m_finalSpeed, 0);
}

void Robot::TeleopInit() {
	if (autonomousCommand.get() != nullptr) {
		autonomousCommand->Cancel();
	}
	driveTrain.get()->SetBrake();
	driveTrain.get()->ZeroAngle();
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot)
