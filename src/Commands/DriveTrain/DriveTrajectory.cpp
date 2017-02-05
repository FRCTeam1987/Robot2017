#include "DriveTrajectory.h"


DriveTrajectory::DriveTrajectory(vector<Trajectory> path) {
	Requires(Robot::driveTrain.get());

	m_runner.setPath(path);
	m_initialAngle = 0;
}

void DriveTrajectory::Initialize() {
	m_initialAngle = Robot::driveTrain.get()->GetAngle();
	Robot::driveTrain.get()->ZeroEncoders();

}

void DriveTrajectory::Execute() {
	 frc::SmartDashboard::PutNumber("Left Encoder Distance", Robot::driveTrain.get()->GetLeftEncoderDistance());
	 frc::SmartDashboard::PutNumber("Right Encoder Distance", Robot::driveTrain.get()->GetRightEncoderDistance());
	 printf("Angle: %f, LeftEncoder: %f, RightEncoder: %f\n", Robot::driveTrain.get()->GetAngle(), Robot::driveTrain.get()->GetLeftEncoderDistance(), Robot::driveTrain.get()->GetRightEncoderDistance());

	 double speedLeft, speedRight, turn;

	 m_runner.Step(Robot::driveTrain.get()->GetLeftEncoderDistance(),
				   Robot::driveTrain.get()->GetRightEncoderDistance(),
				   (m_initialAngle - Robot::driveTrain.get()->GetAngle()),
				   speedLeft, speedRight, turn);

	Robot::driveTrain.get()->SetAutoSpeed(speedLeft);
	Robot::driveTrain.get()->SetSetpoint(turn);
//	 Robot::driveTrain.get()->DriveTank(speedLeft + turn, speedRight - turn);


}

bool DriveTrajectory::IsFinished() {
	return m_runner.IsDone();
}

void DriveTrajectory::End() {
	Robot::driveTrain.get()->DriveTank(0, 0);
}

void DriveTrajectory::Interrupted() {
	Robot::driveTrain.get()->DriveTank(0, 0);
}
