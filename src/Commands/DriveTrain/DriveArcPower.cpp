#include "DriveArcPower.h"

DriveArcPower::DriveArcPower(bool isCw) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::driveTrain.get());
	m_isCw = isCw;
}

// Called just before this Command runs the first time
void DriveArcPower::Initialize() {
	if(m_isCw){
		Robot::driveTrain.get()->DriveTank(.9, -.45);
	} else {
		Robot::driveTrain.get()->DriveTank(0.4, -0.9);
	}
	Robot::driveTrain.get()->ZeroEncoders();
}

// Called repeatedly when this Command is scheduled to run
void DriveArcPower::Execute() {


}

// Make this return true when this Command no longer needs to run execute()
bool DriveArcPower::IsFinished() {
	printf("Left Encoder %f , Right Encoder: %f \n", Robot::driveTrain.get()->GetLeftEncoderDistance(), Robot::driveTrain.get()->GetRightEncoderDistance());
	bool leftDone = fabs(Robot::driveTrain.get()->GetLeftEncoderDistance()) >= fabs(30);
	//bool rightDone = fabs(Robot::driveTrain.get()->GetRightEncoderDistance()) >= fabs(38);

	return leftDone;
	/*
	double angle = 90;

	if(m_isCw) {
		return 90 <= Robot::driveTrain.get()->GetAngle();
	} else {
		return -90 >= Robot::driveTrain.get()->GetAngle();
	}
	*/

}

// Called once after isFinished returns true
void DriveArcPower::End() {
	Robot::driveTrain.get()->DriveTank(0, 0);

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveArcPower::Interrupted() {

}
