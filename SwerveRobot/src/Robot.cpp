#include "Robot.h"

std::unique_ptr<OI> Robot::oi;
std::shared_ptr<SwerveSubsystem> Robot::swerveSubsystem;

void Robot::RobotInit() {
	std::cout << "MADE IT TO ROBOTINIT" << std::endl;

	RobotMap::init();
	oi.reset(new OI());
	std::cout << "MADE IT TO OI" << std::endl;

	swerveSubsystem.reset(new SwerveSubsystem());
	std::cout << "FINISHED INIT SWERVE SUBSYSTEM" << std::endl;


	Robot::swerveSubsystem->ZeroYaw();
	Robot::swerveSubsystem->SetAdjYaw(0);
	std::cout << "END OF ROBOTINIT" << std::endl;

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
