#include "Robot.h"

std::unique_ptr<OI> Robot::oi;
std::unique_ptr<SwerveSubsystem> Robot::swerveSubsystem;

void Robot::RobotInit() {
	std::cout << "MADE IT TO ROBOTINIT" << std::endl;

	RobotMap::init();
	swerveSubsystem.reset(new SwerveSubsystem());
	oi.reset(new OI());

	Robot::swerveSubsystem->ZeroYaw();
	Robot::swerveSubsystem->SetAdjYaw(0);

	SmartDashboard::PutData("Wheel Module Test", new WheelModuleTest());
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
