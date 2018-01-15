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
}

void Robot::TeleopInit() {
	if(selectedMode != nullptr) {
		selectedMode->Cancel();
	}

	//TODO: REMOVE FOR COMP
	/*int FL_CAL = 668;
	int BL_CAL = 907;
	int FR_CAL = 3180;
	int BR_CAL = 558;

	int currentPWMFL = RobotMap::swerveSubsystemFrontLeftRotationTalon->GetSensorCollection().GetPulseWidthPosition();
	int currentQUADFL = RobotMap::swerveSubsystemFrontLeftRotationTalon->GetSensorCollection().GetQuadraturePosition();
	int calSetpointFL =  currentQUADFL + (((currentQUADFL % 4096) - ((currentPWMFL % 4096) - FL_CAL)) - (currentQUADFL % 4096));

	int currentPWMFR = RobotMap::swerveSubsystemFrontRightRotationTalon->GetSensorCollection().GetPulseWidthPosition();
	int currentQUADFR = RobotMap::swerveSubsystemFrontRightRotationTalon->GetSensorCollection().GetQuadraturePosition();
	int calSetpointFR =  currentQUADFR + (((currentQUADFR % 4096) - ((currentPWMFR % 4096) - FR_CAL)) - (currentQUADFR % 4096));

	int currentPWMBL = RobotMap::swerveSubsystemBackLeftRotationTalon->GetSensorCollection().GetPulseWidthPosition();
	int currentQUADBL = RobotMap::swerveSubsystemBackLeftRotationTalon->GetSensorCollection().GetQuadraturePosition();
	int calSetpointBL =  currentQUADBL + (((currentQUADBL % 4096) - ((currentPWMBL % 4096) - BL_CAL)) - (currentQUADBL % 4096));

	int currentPWMBR = RobotMap::swerveSubsystemBackRightRotationTalon->GetSensorCollection().GetPulseWidthPosition();
	int currentQUADBR = RobotMap::swerveSubsystemBackRightRotationTalon->GetSensorCollection().GetQuadraturePosition();
	int calSetpointBR =  currentQUADBR + (((currentQUADBR % 4096) - ((currentPWMBR % 4096) - BR_CAL)) - (currentQUADBR % 4096));

	RobotMap::swerveSubsystemFrontLeftRotationTalon->Set(ControlMode::Position, calSetpointFL);
	RobotMap::swerveSubsystemFrontRightRotationTalon->Set(ControlMode::Position, calSetpointFR);
	RobotMap::swerveSubsystemBackLeftRotationTalon->Set(ControlMode::Position, calSetpointBL);
	RobotMap::swerveSubsystemBackRightRotationTalon->Set(ControlMode::Position, calSetpointBR);

	//std::this_thread::sleep_for(std::chrono::seconds(3));

	RobotMap::swerveSubsystemFrontLeftRotationTalon->GetSensorCollection().SetQuadraturePosition(0, 10);
	RobotMap::swerveSubsystemFrontRightRotationTalon->GetSensorCollection().SetQuadraturePosition(0, 10);
	RobotMap::swerveSubsystemBackLeftRotationTalon->GetSensorCollection().SetQuadraturePosition(0, 10);
	RobotMap::swerveSubsystemBackRightRotationTalon->GetSensorCollection().SetQuadraturePosition(0, 10);

	RobotMap::swerveSubsystemFrontLeftRotationTalon->GetSensorCollection().SetPulseWidthPosition(0, 10);
	RobotMap::swerveSubsystemFrontRightRotationTalon->GetSensorCollection().SetPulseWidthPosition(0, 10);
	RobotMap::swerveSubsystemBackLeftRotationTalon->GetSensorCollection().SetPulseWidthPosition(0, 10);
	RobotMap::swerveSubsystemBackRightRotationTalon->GetSensorCollection().SetPulseWidthPosition(0, 10);*/
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
