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
	//follower.FollowPath();
}

void Robot::TeleopInit() {
	if(selectedMode != nullptr) {
		selectedMode->Cancel();
	}

	//TODO: REMOVE FOR COMP
	int FL_CAL = 524;
	int BL_CAL = 904;
	int FR_CAL = 2786;
	int BR_CAL = 1161;

	int currentPWMFL = RobotMap::swerveSubsystemFrontLeftRotationTalon->GetSensorCollection().GetPulseWidthPosition() % 4096;
	int calSetpointFL = (FL_CAL - currentPWMFL) - (RobotMap::swerveSubsystemFrontLeftRotationTalon->GetSensorCollection().GetQuadraturePosition() % 4096) - (FL_CAL - currentPWMFL);

	int currentPWMBL = RobotMap::swerveSubsystemBackLeftRotationTalon->GetSensorCollection().GetPulseWidthPosition() % 4096;
	int calSetpointBL = (BL_CAL - currentPWMBL) - (RobotMap::swerveSubsystemBackLeftRotationTalon->GetSensorCollection().GetQuadraturePosition() % 4096) - (BL_CAL - currentPWMBL);

	std::cout << "BR_CAL: " << BR_CAL << std::endl;
	int currentPWMBR = RobotMap::swerveSubsystemBackRightRotationTalon->GetSensorCollection().GetPulseWidthPosition() % 4096;
	std::cout << "currentPWBR: " << currentPWMBR << std::endl;
	int calSetpointBR = (BR_CAL - currentPWMBR) - (RobotMap::swerveSubsystemBackRightRotationTalon->GetSensorCollection().GetQuadraturePosition() % 4096) - (BR_CAL - currentPWMBR);
	std::cout << "calSetpointBR: " << calSetpointBR << std::endl;

	int currentPWMFR = RobotMap::swerveSubsystemFrontRightRotationTalon->GetSensorCollection().GetPulseWidthPosition() % 4096;
	int calSetpointFR = (FR_CAL - currentPWMFR) - (RobotMap::swerveSubsystemFrontRightRotationTalon->GetSensorCollection().GetQuadraturePosition() % 4096) - (FR_CAL - currentPWMFR);

	RobotMap::swerveSubsystemFrontLeftRotationTalon->Set(ControlMode::Position, calSetpointFL);
	RobotMap::swerveSubsystemFrontRightRotationTalon->Set(ControlMode::Position, calSetpointFR);
	RobotMap::swerveSubsystemBackLeftRotationTalon->Set(ControlMode::Position, calSetpointBL);
	RobotMap::swerveSubsystemBackRightRotationTalon->Set(ControlMode::Position, calSetpointBR);
	//RobotMap::swerveSubsystemFrontLeftRotationTalon->SetSelectedSensorPosition(0, 0, 10);
	//RobotMap::swerveSubsystemFrontRightRotationTalon->SetSelectedSensorPosition(0, 0, 10);
	//RobotMap::swerveSubsystemBackLeftRotationTalon->SetSelectedSensorPosition(0, 0, 10);
	//RobotMap::swerveSubsystemBackRightRotationTalon->SetSelectedSensorPosition(0, 0, 10);
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	double velocity = (float)RobotMap::swerveSubsystemBackLeftDriveTalon->GetSelectedSensorVelocity(0) * 0.0732421875;
	SmartDashboard::PutNumber("Back Left Sensor Pos: ", RobotMap::swerveSubsystemBackLeftDriveTalon->GetSelectedSensorPosition(0));
	SmartDashboard::PutNumber("Back Left Sensor Vel: ", velocity);
	SmartDashboard::PutNumber("flPos", RobotMap::swerveSubsystemFrontLeftDriveTalon->GetSensorCollection().GetQuadraturePosition());
	SmartDashboard::PutNumber("frPos", RobotMap::swerveSubsystemFrontRightDriveTalon->GetSensorCollection().GetQuadraturePosition());
	SmartDashboard::PutNumber("blPos", RobotMap::swerveSubsystemBackLeftDriveTalon->GetSensorCollection().GetQuadraturePosition());
	SmartDashboard::PutNumber("brPos", RobotMap::swerveSubsystemBackRightDriveTalon->GetSensorCollection().GetQuadraturePosition());

	//SmartDashboard::PutNumber("flSet", RobotMap::swerveSubsystemFrontLeftRotationTalon->GetClosedLoopTarget(0));
	//SmartDashboard::PutNumber("frSet", RobotMap::swerveSubsystemFrontRightRotationTalon->GetClosedLoopTarget(0));
	//SmartDashboard::PutNumber("blSet", RobotMap::swerveSubsystemBackLeftRotationTalon->GetClosedLoopTarget(0));
	//SmartDashboard::PutNumber("brSet", RobotMap::swerveSubsystemBackRightRotationTalon->GetClosedLoopTarget(0));
}

void Robot::TestPeriodic() {

}

START_ROBOT_CLASS(Robot);
