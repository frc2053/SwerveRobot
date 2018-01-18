#include "Commands/Autonomous/TestAuto.h"
#include "Robot.h"
#include "Pathfinder/TestFollower.h"

std::unique_ptr<OI> Robot::oi;
std::unique_ptr<SwerveSubsystem> Robot::swerveSubsystem;
TestFollower follower;

void Robot::RobotInit() {
	std::cout << "MADE IT TO ROBOTINIT" << std::endl;

	RobotMap::init();
	swerveSubsystem.reset(new SwerveSubsystem());
	oi.reset(new OI());

	autoChooser.AddDefault("Test Auto", new TestAuto());

	SmartDashboard::PutData("Auto mode chooser", &autoChooser);

	Robot::swerveSubsystem->ZeroYaw();
	Robot::swerveSubsystem->SetAdjYaw(0);
	follower.Generate();
}

void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	selectedMode.reset(autoChooser.GetSelected());
	if(selectedMode != nullptr) {
		//selectedMode->Start();
	}
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
	follower.FollowPath();
	SmartDashboard::PutNumber("flPos", RobotMap::swerveSubsystemFrontLeftDriveTalon->GetSelectedSensorPosition(0));
	SmartDashboard::PutNumber("frPos", RobotMap::swerveSubsystemFrontRightDriveTalon->GetSelectedSensorPosition(0));
	SmartDashboard::PutNumber("blPos", RobotMap::swerveSubsystemBackLeftDriveTalon->GetSelectedSensorPosition(0));
	SmartDashboard::PutNumber("brPos", RobotMap::swerveSubsystemBackRightDriveTalon->GetSelectedSensorPosition(0));
}

void Robot::TeleopInit() {
	if(selectedMode != nullptr) {
		selectedMode->Cancel();
	}

	//TODO: REMOVE FOR COMP
	/*int FL_CAL = 817;
	int BL_CAL = 911;
	int FR_CAL = 2685;
	int BR_CAL = 230;

	int currentPWMFL = RobotMap::swerveSubsystemFrontLeftRotationTalon->GetSensorCollection().GetPulseWidthPosition();
	int currentPWMFR = RobotMap::swerveSubsystemFrontRightRotationTalon->GetSensorCollection().GetPulseWidthPosition();
	int currentPWMBL = RobotMap::swerveSubsystemBackLeftRotationTalon->GetSensorCollection().GetPulseWidthPosition();
	int currentPWMBR = RobotMap::swerveSubsystemBackRightRotationTalon->GetSensorCollection().GetPulseWidthPosition();

	std::cout << "currentPWMFL: " << currentPWMFL << std::endl;
	std::cout << "currentPWMFR: " << currentPWMFR << std::endl;
	std::cout << "currentPWMBL: " << currentPWMBL << std::endl;
	std::cout << "currentPWMBR: " << currentPWMBR << std::endl;

	int setpointFL = -(currentPWMFL - FL_CAL);
	int setpointFR = -(currentPWMFR - FR_CAL);
	int setpointBL = -(currentPWMBL - BL_CAL);
	int setpointBR = -(currentPWMBR - BR_CAL);

	std::cout << "setpointFL: " << setpointFL << std::endl;
	std::cout << "setpointFR: " << setpointFR << std::endl;
	std::cout << "setpointBL: " << setpointBL << std::endl;
	std::cout << "setpointBR: " << setpointBR << std::endl;

	RobotMap::swerveSubsystemFrontLeftRotationTalon->Set(setpointFL);
	RobotMap::swerveSubsystemFrontRightRotationTalon->Set(setpointFR);
	RobotMap::swerveSubsystemBackLeftRotationTalon->Set(setpointBL);
	RobotMap::swerveSubsystemBackRightRotationTalon->Set(setpointBR);*/
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	//double velocitybl = (float)RobotMap::swerveSubsystemBackLeftDriveTalon->GetSelectedSensorVelocity(0) * 0.0732421875;
	SmartDashboard::PutNumber("flPos", RobotMap::swerveSubsystemFrontLeftDriveTalon->GetSelectedSensorPosition(0));
	SmartDashboard::PutNumber("frPos", RobotMap::swerveSubsystemFrontRightDriveTalon->GetSelectedSensorPosition(0));
	SmartDashboard::PutNumber("blPos", RobotMap::swerveSubsystemBackLeftDriveTalon->GetSelectedSensorPosition(0));
	SmartDashboard::PutNumber("brPos", RobotMap::swerveSubsystemBackRightDriveTalon->GetSelectedSensorPosition(0));
}

void Robot::TestPeriodic() {

}

START_ROBOT_CLASS(Robot);
