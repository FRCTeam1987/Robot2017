#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include <SmartDashboard/SendableChooser.h>
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "OI.h"
#include "Subsystems/Collector.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/GearManipulator.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Turret.h"
#include "Subsystems/Vision.h"
#include "Commands/MiddlePeg.h"
#include "Commands/MiddlePegRed.h"
#include "Commands/MiddlePegBlue.h"


class Robot : public IterativeRobot {
public:
	std::unique_ptr<Command> autonomousCommand;
	static std::unique_ptr<OI> oi;
	LiveWindow *lw = LiveWindow::GetInstance();
	static std::shared_ptr<Collector> collector;
    static std::shared_ptr<DriveTrain> driveTrain;
    static std::shared_ptr<GearManipulator> gearManipulator;
    static std::shared_ptr<Shooter> shooter;
    static std::shared_ptr<Turret> turret;
    static std::shared_ptr<Vision> vision;

    frc::SendableChooser<frc::Command *> autoChooser;

	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};
#endif
