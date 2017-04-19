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
#include "Commands/Shooter/ChangeRPMBasedOnCurrent.h"
#include "Commands/Collector/ToggleDefaultCommand.h"
#include "Commands/Collector/SetCollectorDefaultCommand.h"


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
	frc::JoystickButton *increaseRpmCo = new frc::JoystickButton(RobotMap::co.get(), RobotMap::BUTTON_ADD_RPM_CO);
	frc::JoystickButton *decreaseRpmCo = new frc::JoystickButton(RobotMap::co.get(), RobotMap::BUTTON_SUB_RPM_CO);
	frc::JoystickButton *toggleCollectorCo = new frc::JoystickButton(RobotMap::co.get(), RobotMap::BUTTON_TOGGLE_COLLECT_CO);


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
	increaseRpmCo->WhenPressed(new ChangeRPMBasedOnCurrent(10));
	decreaseRpmCo->WhenPressed(new ChangeRPMBasedOnCurrent(-10));
	toggleCollectorCo->WhenPressed(new ToggleDefaultCommand());


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
