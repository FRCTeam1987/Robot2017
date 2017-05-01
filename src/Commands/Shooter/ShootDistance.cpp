#include "ShootDistance.h"

ShootDistance::ShootDistance() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());


	m_distance = 0;
	m_tolerance = 20;
	m_shooterRpm = 0;

	m_distanceToRpm[103]=3000;
	m_distanceToRpm[107]=3050;
	m_distanceToRpm[111]=3050;
	m_distanceToRpm[115]=3050;
	m_distanceToRpm[119]=3085;
	m_distanceToRpm[123]=3100;
	m_distanceToRpm[127]=3125;
	m_distanceToRpm[131]=3135;
	m_distanceToRpm[135]=3165;
	m_distanceToRpm[139]=3210;
	m_distanceToRpm[143]=3260;
	m_distanceToRpm[147]=3340;
	m_distanceToRpm[151]=3420;
	m_distanceToRpm[155]=3465;
	m_distanceToRpm[159]=3500;
	m_distanceToRpm[163]=3550;
	m_distanceToRpm[167]=3590;
	m_distanceToRpm[171]=3680;
	m_distanceToRpm[175]=3700;
	m_distanceToRpm[179]=3750;
	m_distanceToRpm[183]=3770;//3770
	m_distanceToRpm[187]=3800;
	m_distanceToRpm[191]=3840;
	m_distanceToRpm[195]=3860;
	m_distanceToRpm[199]=3890;
	m_distanceToRpm[203]=3900;



}

// Called just before this Command runs the first time
void ShootDistance::Initialize() {
	Robot::shooter->SetPIDForSpeedUp();
	m_shooterRpm = 0;
	RobotMap::Log.AddEntry("ShootDistance::Initialize()");

	//find if the distance to the goal is in the map.
	TimeStampedValue target = Robot::vision->GetInfo();
	m_distance = target.GetValue3() * .92;

	int distance = m_distance + .5;
	if (distance > 203 ) {
		m_shooterRpm = m_distanceToRpm.find(203)->second;
	} else if (distance < 103) {
		m_shooterRpm = m_distanceToRpm.find(103)->second;
	} else {
		while(m_shooterRpm == 0) {
			//if the distance is in the map set the rpm equal to the key of the distance if not add 1 to the distance and repeat
			if (m_distanceToRpm.count(distance) == 1) {
				m_shooterRpm = m_distanceToRpm.find(distance)->second;

			} else {

				distance++;
			}
		}
	}
	Robot::shooter->SetCurrentRpm(m_shooterRpm);
	Robot::shooter.get()->SetShooterRpm(m_shooterRpm);


}

// Called repeatedly when this Command is scheduled to run
void ShootDistance::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ShootDistance::IsFinished() {
	return fabs(fabs(Robot::shooter.get()->GetWheelRPM()) - fabs(m_shooterRpm)) <= m_tolerance;
}

// Called once after isFinished returns true
void ShootDistance::End() {
	Robot::shooter->SetPIDForMaintain();

	RobotMap::Log.AddEntry("ShootDistance::End()");

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootDistance::Interrupted() {

}
