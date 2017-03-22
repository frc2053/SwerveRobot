#include "Robot.h"

std::unique_ptr<OI> Robot::oi;
std::shared_ptr<SwerveSubsystem> Robot::swerveSubsystem;

void Robot::RobotInit() {
	RobotMap::init();
	oi.reset(new OI());
	swerveSubsystem.reset(new SwerveSubsystem());

	Robot::swerveSubsystem->ZeroYaw();
	Robot::swerveSubsystem->SetAdjYaw(0);
}

void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
}

START_ROBOT_CLASS(Robot);
