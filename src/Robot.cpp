#include "Robot.h"

std::shared_ptr<DriveTrain> Robot::driveTrain;
std::unique_ptr<OI> Robot::oi;

void Robot::RobotInit() {
	RobotMap::init();
    driveTrain.reset(new DriveTrain());
	oi.reset(new OI());
	autonomousCommand.reset(new TestMotors());
}

void Robot::DisabledInit() {
}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot)
