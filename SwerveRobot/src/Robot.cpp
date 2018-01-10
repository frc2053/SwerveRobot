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
}

void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	/*RobotMap::swerveSubsystemFrontLeftRotationTalon->Set(ControlMode::Position, 2562);
	RobotMap::swerveSubsystemFrontRightRotationTalon->Set(ControlMode::Position, 4038);
	RobotMap::swerveSubsystemBackLeftRotationTalon->Set(ControlMode::Position, 965);
	RobotMap::swerveSubsystemBackRightRotationTalon->Set(ControlMode::Position, 648);

	RobotMap::swerveSubsystemFrontLeftRotationTalon->SetSelectedSensorPosition(0, 0, 10);
	RobotMap::swerveSubsystemFrontRightRotationTalon->SetSelectedSensorPosition(0, 0, 10);
	RobotMap::swerveSubsystemBackLeftRotationTalon->SetSelectedSensorPosition(0, 0, 10);
	RobotMap::swerveSubsystemBackRightRotationTalon->SetSelectedSensorPosition(0, 0, 10);*/
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	//TODO: REMOVE FOR COMP
	/*int FL_CAL = 2549;
	int BL_CAL = 977;

	int currentPWMFL = RobotMap::swerveSubsystemFrontLeftRotationTalon->GetSensorCollection().GetPulseWidthPosition();
	int calSetpointFL = (FL_CAL - currentPWMFL) + RobotMap::swerveSubsystemFrontLeftRotationTalon->GetSensorCollection().GetQuadraturePosition();

	int currentPWMBL = RobotMap::swerveSubsystemBackLeftRotationTalon->GetSensorCollection().GetPulseWidthPosition();
	int calSetpointBL = (BL_CAL - currentPWMBL) + RobotMap::swerveSubsystemBackLeftRotationTalon->GetSensorCollection().GetQuadraturePosition();

	RobotMap::swerveSubsystemFrontLeftRotationTalon->Set(ControlMode::Position, calSetpointFL);
	RobotMap::swerveSubsystemFrontRightRotationTalon->Set(ControlMode::Position, 3588);
	RobotMap::swerveSubsystemBackLeftRotationTalon->Set(ControlMode::Position, calSetpointBL);
	RobotMap::swerveSubsystemBackRightRotationTalon->Set(ControlMode::Position, 645);
	//RobotMap::swerveSubsystemFrontLeftRotationTalon->SetSelectedSensorPosition(0, 0, 10);
	//RobotMap::swerveSubsystemFrontRightRotationTalon->SetSelectedSensorPosition(0, 0, 10);
	//RobotMap::swerveSubsystemBackLeftRotationTalon->SetSelectedSensorPosition(0, 0, 10);
	//RobotMap::swerveSubsystemBackRightRotationTalon->SetSelectedSensorPosition(0, 0, 10);*/
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	double velocity = (float)RobotMap::swerveSubsystemBackLeftDriveTalon->GetSelectedSensorVelocity(0) * 0.0732421875;
	SmartDashboard::PutNumber("Back Left Sensor Pos: ", RobotMap::swerveSubsystemBackLeftDriveTalon->GetSelectedSensorPosition(0));
	SmartDashboard::PutNumber("Back Left Sensor Vel: ", velocity);
	//SmartDashboard::PutNumber("flPos", RobotMap::swerveSubsystemFrontLeftRotationTalon->GetSensorCollection().GetQuadraturePosition());
	//SmartDashboard::PutNumber("frPos", RobotMap::swerveSubsystemFrontRightRotationTalon->GetSensorCollection().GetQuadraturePosition());
	//SmartDashboard::PutNumber("blPos", RobotMap::swerveSubsystemBackLeftRotationTalon->GetSensorCollection().GetQuadraturePosition());
	//SmartDashboard::PutNumber("brPos", RobotMap::swerveSubsystemBackRightRotationTalon->GetSensorCollection().GetQuadraturePosition());

	//SmartDashboard::PutNumber("flSet", RobotMap::swerveSubsystemFrontLeftRotationTalon->GetClosedLoopTarget(0));
	//SmartDashboard::PutNumber("frSet", RobotMap::swerveSubsystemFrontRightRotationTalon->GetClosedLoopTarget(0));
	//SmartDashboard::PutNumber("blSet", RobotMap::swerveSubsystemBackLeftRotationTalon->GetClosedLoopTarget(0));
	//SmartDashboard::PutNumber("brSet", RobotMap::swerveSubsystemBackRightRotationTalon->GetClosedLoopTarget(0));
}

void Robot::TestPeriodic() {

}

START_ROBOT_CLASS(Robot);
