#include "Robot.h"
#include <Timer.h>

#include "Commands/PlaceGearAndHopperAuto.h"

std::shared_ptr<Collector> Robot::collector;
std::shared_ptr<DriveTrain> Robot::driveTrain;
std::shared_ptr<GearManipulator> Robot::gearManipulator;
std::shared_ptr<Shooter> Robot::shooter;
std::shared_ptr<Turret> Robot::turret;
std::shared_ptr<Vision> Robot::vision;
std::unique_ptr<OI> Robot::oi;

void Robot::RobotInit() {
	RobotMap::init();
	collector.reset(new Collector());
    driveTrain.reset(new DriveTrain());
    gearManipulator.reset(new GearManipulator());
    shooter.reset(new Shooter());
    turret.reset(new Turret());
    vision.reset(new Vision());
	oi.reset(new OI());

	autoChooser.AddDefault("Boiler Peg Red", new PlaceGearAndHopperAuto());
	autoChooser.AddObject("Middle Peg Red", new MiddlePegRed());
	autoChooser.AddObject("Boiler Peg Blue", new BoilerSidePegBlue());


	autoChooser.AddObject("Middle Peg Blue", new MiddlePegBlue());
	autoChooser.AddObject("Hopper Red", new HopperRed());
	autoChooser.AddObject("Hopper Blue", new HopperBlue());

	frc::SmartDashboard::PutData("Auto Modes!!", &autoChooser);
}

void Robot::DisabledInit() {
	RobotMap::Log.DumpEntries();
}

void Robot::DisabledPeriodic() {
	frc::SmartDashboard::PutString("Mode Selected", autoChooser.GetSelected()->GetName().c_str());
	frc::Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	if (autonomousCommand.get() != nullptr) {
		autonomousCommand->Cancel();
	}

	driveTrain.get()->SetBrake();
	turret.get()->ZeroPosition();
	driveTrain.get()->SetPTO(false);
	autonomousCommand.reset(autoChooser.GetSelected());
	printf("AutoSelected: %s \n", autoChooser.GetSelected()->GetName().c_str());
	if (autonomousCommand.get() != nullptr) {
		printf("Running autonomous chooser\n");
		autonomousCommand->Start();
	} else {
		printf("Autonomous chooser is null!\n");
	}
}

void Robot::AutonomousPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	if (autonomousCommand.get() != nullptr) {
		autonomousCommand->Cancel();
	}
	driveTrain.get()->SetBrake();
	driveTrain.get()->ZeroAngle();
	new StopShoot();
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot)
