#include "Robot.h"

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
	if (autonomousCommand.get() != nullptr)
		driveTrain.get()->SetBrake();
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	if (autonomousCommand.get() != nullptr)
		driveTrain.get()->SetCoast();
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot)
