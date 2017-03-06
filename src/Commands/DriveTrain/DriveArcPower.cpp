#include "DriveArcPower.h"

DriveArcPower::DriveArcPower(bool isCw, double distance) {
	Requires(Robot::driveTrain.get());
	m_isCw = isCw;
	m_distance = distance;
}

void DriveArcPower::Initialize() {
	if(m_isCw){
		Robot::driveTrain.get()->DriveTank(.9, -.45);
	} else {
		Robot::driveTrain.get()->DriveTank(0.4, -0.9);
	}
	Robot::driveTrain.get()->ZeroEncoders();
}

void DriveArcPower::Execute() {


}

bool DriveArcPower::IsFinished() {
	printf("Left Encoder %f , Right Encoder: %f \n", Robot::driveTrain.get()->GetLeftEncoderDistance(), Robot::driveTrain.get()->GetRightEncoderDistance());
	bool leftDone = fabs(Robot::driveTrain.get()->GetLeftEncoderDistance()) >= fabs(m_distance);
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

void DriveArcPower::End() {
	Robot::driveTrain.get()->DriveTank(0, 0);

}

void DriveArcPower::Interrupted() {

}
