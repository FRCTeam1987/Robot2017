#include "OI.h"

#include <WPILib.h>
#include "SmartDashboard/SmartDashboard.h"
#include "Buttons/JoystickButton.h"
#include "Commands/Collector/SetCollector.h"
#include "Commands/Collector/ShowHasBall.h"
#include "Commands/GearManipulator/SetGearManipulator.h"
#include "Commands/GearManipulator/SetGearManipulatorRoller.h"
#include "Commands/GearManipulator/SetGearPosition.h"
#include "Commands/GearManipulator/CollectGear.h"
#include "Commands/GearManipulator/PlaceGear.h"
#include "Commands/Shooter/SetShooter.h"
#include "Commands/Shooter/SetElevator.h"
#include "Commands/Shooter/SetRoller.h"
#include "Commands/Shooter/Shoot.h"
#include "Commands/Shooter/StopShoot.h"
#include "Commands/Shooter/SetShooterPercent.h"
#include "Commands/Turret/ZeroTurret.h"
#include "Commands/Turret/SetTurretPercent.h"
#include "Commands/Turret/SetDesiredAngle.h"
#include "Commands/PrintStuff.h"
#include "Commands/Turret/SetPosition.h"
#include "Commands/DriveTrain/Shift.h"
#include "Commands/DriveTrain/Climb.h"
#include "Commands/DriveTrain/UpdateSmartDashboard.h"
#include "Commands/DriveTrain/ZeroDriveTrain.h"
#include "Commands/DriveTrain/DriveStraight.h"
#include "Commands/DriveTrain/DriveArc.h"
#include "Commands/DriveTrain/DrivePivot.h"
#include "Commands/DriveTrain/DriveRotate.h"
#include "Commands/DriveTrain/BlueEdgeDriveStationToHopper.h"
#include "Commands/DriveTrain/PlaceGearFromDriveStation.h"
#include "Commands/DriveTrain/DriveArcPower.h"
#include "Commands/DriveTrain/TestDriveStuff.h"
#include "Commands/Shooter/StopShoot.h"
#include "Commands/SetDefaultState.h"
#include "Commands/Turret/ZeroAndMove.h"
#include "Commands/Turret/ZeroTurretEncoder.h"
#include "Commands/Turret/AddToCurrentAngle.h"
#include "Commands/Turret/AutoTarget.h"
#include "Commands/Turret/AnchorTurret.h"
#include "Commands/DriveTrain/ToggleShift.h"
#include "Commands/PlaceGearAndHopperAuto.h"
#include "Commands/MiddlePegRed.h"
#include "Commands/MiddlePegBlue.h"
#include "Commands/Vision/VisionUpdateTurret.h"
#include "Commands/Turret/WaitForOnTarget.h"
#include "Commands/Shooter/ShootDistance.h"
#include "Commands/DriveTrain/SetPTO.h"
#include "Commands/HopperRed.h"
#include "Commands/RoboLogCommand.h"
#include "Commands/DriveTrain/TogglePTO.h"

OI::OI() {
	//Driver
	frc::JoystickButton *placeGearXbox = new frc::JoystickButton(RobotMap::xbox.get(), RobotMap::BUTTON_PLACE_GEAR_XBOX);
	frc::JoystickButton *shootXbox = new frc::JoystickButton(RobotMap::xbox.get(), RobotMap::BUTTON_SHOOT_XBOX);
	frc::JoystickButton *stopShootXbox = new frc::JoystickButton(RobotMap::xbox.get(), RobotMap::BUTTON_STOP_SHOOT_XBOX);
	frc::JoystickButton *collectGearXbox = new frc::JoystickButton(RobotMap::xbox.get(), RobotMap::BUTTON_COLLECT_GEAR_XBOX);
	frc::JoystickButton *collectGearFromHopperXbox = new frc::JoystickButton(RobotMap::xbox.get(), RobotMap::BUTTON_COLLECT_GEAR_HOPPER);
	frc::JoystickButton *shiftButton = new frc::JoystickButton(RobotMap::xbox.get(), RobotMap::BUTTON_SHIFT_XBOX);
	frc::JoystickButton *ptoButton = new frc::JoystickButton(RobotMap::xbox.get(), RobotMap::BUTTON_PTO_XBOX);

	//CoDriver
	frc::JoystickButton *gearRollerCo = new frc::JoystickButton(RobotMap::co.get(), RobotMap::BUTTON_GEAR_ROLLER_CO);
	frc::JoystickButton *reverseBallCo = new frc::JoystickButton(RobotMap::co.get(), RobotMap::BUTTON_REVERSE_BALL_CO);
	frc::JoystickButton *reverseElevatorCo = new frc::JoystickButton(RobotMap::co.get(), RobotMap::BUTTON_REVERSE_ELEVATOR_CO);
	frc::JoystickButton *stopAllCo = new frc::JoystickButton(RobotMap::co.get(), RobotMap::BUTTON_STOP_ALL_CO);
	frc::JoystickButton *turretRightCo = new frc::JoystickButton(RobotMap::co.get(), RobotMap::BUTTON_TURRET_RIGHT_CO);
	frc::JoystickButton *turretLeftCo = new frc::JoystickButton(RobotMap::co.get(), RobotMap::BUTTON_TURRET_LEFT_CO);
	frc::JoystickButton *shootCo = new frc::JoystickButton(RobotMap::co.get(), RobotMap::BUTTON_SHOOT_CO);

	//Driver
	placeGearXbox->WhenPressed(new PlaceGear());
	shootXbox->WhenPressed(new Shoot());
	stopShootXbox->WhenPressed(new StopShoot());
	collectGearXbox->WhenPressed(new CollectGear());
	collectGearFromHopperXbox->WhenPressed(new SetGearManipulator(.75));
	shiftButton->WhenPressed(new ToggleShift());
	ptoButton->WhenPressed(new TogglePTO());

//	CoDriver
	gearRollerCo->WhenPressed(new SetGearManipulatorRoller(.5));
	gearRollerCo->WhenReleased(new SetGearManipulatorRoller(0));
	reverseBallCo->WhenPressed(new SetCollector(-.95));
	reverseBallCo->WhenReleased(new SetCollector(0));
	reverseElevatorCo->WhenPressed(new SetElevator(-.5));
	reverseElevatorCo->WhenReleased(new SetElevator(0));
	stopAllCo->WhenPressed(new SetDefaultState());
	turretRightCo->WhenPressed(new AddToCurrentAngle(30));
	turretLeftCo->WhenPressed(new AddToCurrentAngle(-30));
	shootCo->WhenPressed(new Shoot());

#if 0
	//Auto
	frc::SmartDashboard::PutData("Auto", new PlaceGearAndHopperAuto());

//	//Collector
	frc::SmartDashboard::PutData("Start Collector", new SetCollector(0.95));
//	frc::SmartDashboard::PutData("Reverse Collector", new SetCollector(-0.95));
	frc::SmartDashboard::PutData("Stop Collector", new SetCollector(0));
//	frc::SmartDashboard::PutData("Show Has Ball Sensor", new ShowHasBall());

	//Drive Train
	frc::SmartDashboard::PutData("Shift High", new Shift(true));
	frc::SmartDashboard::PutData("Shift Low", new Shift(false));
	frc::SmartDashboard::PutData("Climb", new Climb());
	frc::SmartDashboard::PutData("Update Smart Dash Board", new UpdateSmartDashboard());
	frc::SmartDashboard::PutData("Zero Sensors", new ZeroDriveTrain());
	frc::SmartDashboard::PutData("Drive 4 feet", new DriveStraight(-48, 0, 0));
	frc::SmartDashboard::PutData("Drive 8 feet", new DriveStraight(96, 0, 0));
	frc::SmartDashboard::PutData("Drive Arc 45", new DriveArc(0, 0, 36, 45));
	frc::SmartDashboard::PutData("Drive Arc 90", new DriveArc(0, 0, 36, 90));
	frc::SmartDashboard::PutData("Drive Arc 360", new DriveArc(0, 0, 36, 360));
	frc::SmartDashboard::PutData("Drive Pivot 90 reset", new DrivePivot(90));
	frc::SmartDashboard::PutData("Drive Pivot 90 no reset", new DrivePivot(90, false));
	frc::SmartDashboard::PutData("Drive Pivot -90 reset", new DrivePivot(-90));
	frc::SmartDashboard::PutData("Drive Pivot -90 no reset", new DrivePivot(-90, false));
	frc::SmartDashboard::PutData("Drive Rotate 0", new DriveRotate(0));
	frc::SmartDashboard::PutData("Drive Rotate 45", new DriveRotate(45));
	frc::SmartDashboard::PutData("Drive Rotate 90", new DriveRotate(90));
	frc::SmartDashboard::PutData("Drive Rotate 180", new DriveRotate(180));
	frc::SmartDashboard::PutData("Drive Rotate 270", new DriveRotate(270));
	frc::SmartDashboard::PutData("Drive Rotate 358.5", new DriveRotate(358.5));
	frc::SmartDashboard::PutData("Drive Rotate 360", new DriveRotate(360));
	frc::SmartDashboard::PutData("Drive Rotate -90", new DriveRotate(-90));
	frc::SmartDashboard::PutData("Drive Rotate -45", new DriveRotate(-45));
	frc::SmartDashboard::PutData("Drive Rotate -15", new DriveRotate(-15));
	frc::SmartDashboard::PutData("DriveArc Power", new DriveArcPower(true, 30));
	frc::SmartDashboard::PutData("Drive chaining stuff", new TestDriveStuff());

	frc::SmartDashboard::PutData("Drive From Blue Driver Station Edge to Hopper", new BlueEdgeDriveStationToHopper());
	frc::SmartDashboard::PutData("Place Gear From Drive Station", new PlaceGearFromDriveStation());
	frc::SmartDashboard::PutData("Middle Peg Red", new MiddlePegRed());
	frc::SmartDashboard::PutData("Middle Peg Blue", new MiddlePegBlue());

//	//Gear Manipulator
//	frc::SmartDashboard::PutData("Start Gear Manipulator", new SetGearManipulator(0.75));
//	frc::SmartDashboard::PutData("Stop Gear Manipulator", new SetGearManipulator(0));
//	frc::SmartDashboard::PutData("Raise Gear", new SetGearPosition(true));
//	frc::SmartDashboard::PutData("Lower Gear", new SetGearPosition(false));
//	frc::SmartDashboard::PutData("Collect Gear", new CollectGear());
//	frc::SmartDashboard::PutData("Place Gear", new PlaceGear());
//
//	//Shooter
//	frc::SmartDashboard::PutData("Stop Shooter", new SetShooter(0));
	frc::SmartDashboard::PutData("Shooter RPM 2500", new SetShooter(2500));
	frc::SmartDashboard::PutData("Shooter RPM 3000", new SetShooter(3000));
//	frc::SmartDashboard::PutData("Shooter RPM 1000", new SetShooter(1000));
//	frc::SmartDashboard::PutData("Shooter RPM 0", new SetShooter(0));
	frc::SmartDashboard::PutData("Start Elevator", new SetElevator(.75));
	frc::SmartDashboard::PutData("Start Elevator negative", new SetElevator(-.75));

	frc::SmartDashboard::PutData("Stop Elevator", new SetElevator(0));
	frc::SmartDashboard::PutData("Start Roller", new SetRoller(.5));
	frc::SmartDashboard::PutData("Start Roller negative", new SetRoller(-.5));

	frc::SmartDashboard::PutData("Stop Roller", new SetRoller(0));
	frc::SmartDashboard::PutData("Shoot", new Shoot());
	frc::SmartDashboard::PutData("Stop Shooter Sequence", new StopShoot());
//	frc::SmartDashboard::PutData("Set Shooter Percent (Hard Coded)", new SetShooterPercent());
	frc::SmartDashboard::PutData("Zero Turret Encoder", new ZeroTurretEncoder());

//	//Turret
//	frc::SmartDashboard::PutData("ZeroTurret", new ZeroTurret(.2));
//	frc::SmartDashboard::PutData("Set Turret 180", new SetPosition(180));
//	frc::SmartDashboard::PutData("Set Turret -180", new SetPosition(-180));
//	frc::SmartDashboard::PutData("Set Turret 100", new SetPosition(100));
	frc::SmartDashboard::PutData("Set Turret 50", new SetPosition(50));
	frc::SmartDashboard::PutData("Set Turret 20", new SetPosition(20));
	frc::SmartDashboard::PutData("Set Turret -90", new SetPosition(-90));
	frc::SmartDashboard::PutData("Set Turret 90", new SetPosition(90));
//	frc::SmartDashboard::PutData("Set Turret -10", new SetPosition(-10));
//	frc::SmartDashboard::PutData("Set Turret -50 (Real)", new SetPosition(-50));
//	frc::SmartDashboard::PutData("Set Turret 270", new SetPosition(270));
	frc::SmartDashboard::PutData("AnchorTurret 90", new AnchorTurret(90, false));
	frc::SmartDashboard::PutData("AnchorTurret 270", new AnchorTurret(270, false));
	frc::SmartDashboard::PutData("AnchorTurret 10", new AnchorTurret(10, false));
	frc::SmartDashboard::PutData("AnchorTurret 359", new AnchorTurret(359, false));
	frc::SmartDashboard::PutData("AnchorTurret 350", new AnchorTurret(350, false));
	frc::SmartDashboard::PutData("AnchorTurret 5", new AnchorTurret(5, false));
	frc::SmartDashboard::PutData("AnchorTurret 1", new AnchorTurret(1, false));

	frc::SmartDashboard::PutData("Turret Angle +5", new SetPosition(5));
	frc::SmartDashboard::PutData("Turret Angle -5", new SetPosition(-5));

	frc::SmartDashboard::PutData("Turret Angle +1", new SetPosition(1));
	frc::SmartDashboard::PutData("Turret Angle -1", new SetPosition(-1));

	frc::SmartDashboard::PutData("Turret Angle +2", new SetPosition(2));
	frc::SmartDashboard::PutData("Turret Angle -2", new SetPosition(-2));

	frc::SmartDashboard::PutData("Set Turret Angle 10", new SetPosition(10));
	frc::SmartDashboard::PutData("Set Turret Angle -10", new SetPosition(-10));

//
	frc::SmartDashboard::PutData("Set Turret 0", new SetPosition(0));

	frc::SmartDashboard::PutData("Auto Target", new AutoTarget());

//
//	frc::SmartDashboard::PutData("Zero Turret And Move", new ZeroAndMove());
//
//	frc::SmartDashboard::PutData("Set Turret Speed To 0.5", new SetTurretPercent(0.5));
//	frc::SmartDashboard::PutData("Set Turret Speed To -0.5", new SetTurretPercent(-0.5));
//
	//PrintStuff
	frc::SmartDashboard::PutData("Print Stuff", new PrintStuff());
//
//	//All
//	frc::SmartDashboard::PutData("Set Default State", new SetDefaultState());
#endif
	frc::SmartDashboard::PutData("Vision Update Anchor", new VisionUpdateTurret());
	frc::SmartDashboard::PutData("SetDesiredAngle(90)", new SetDesiredAngle(90));

	frc::SmartDashboard::PutData("Turret +30", new AddToCurrentAngle(30));
	frc::SmartDashboard::PutData("Turret -30", new AddToCurrentAngle(-30));

	frc::SmartDashboard::PutData("Wait for On target", new WaitForOnTarget());

	frc::SmartDashboard::PutNumber("Testing RPM", 0);

	frc::SmartDashboard::PutData("Shoot", new Shoot());
	frc::SmartDashboard::PutData("ShootForDistance", new ShootDistance());
	frc::SmartDashboard::PutData("Stop Shooter", new SetShooter(0));
	frc::SmartDashboard::PutData("Engage pto", new SetPTO(true));
	frc::SmartDashboard::PutData("Disengage pto", new SetPTO(false));

	frc::SmartDashboard::PutData("ROBOLog", new RoboLogCommand());
	frc::SmartDashboard::PutData("set default state", new SetDefaultState());
}
