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

	SmartDashboard::PutData("Wheel Module Test", new WheelModuleTest(0));
}

void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	RobotMap::swerveSubsystemFrontLeftRotationTalon->Set(ControlMode::Position, 2562);
	RobotMap::swerveSubsystemFrontRightRotationTalon->Set(ControlMode::Position, 4038);
	RobotMap::swerveSubsystemBackLeftRotationTalon->Set(ControlMode::Position, 965);
	RobotMap::swerveSubsystemBackRightRotationTalon->Set(ControlMode::Position, 648);

	RobotMap::swerveSubsystemFrontLeftRotationTalon->SetSelectedSensorPosition(0, 0, 10);
	RobotMap::swerveSubsystemFrontRightRotationTalon->SetSelectedSensorPosition(0, 0, 10);
	RobotMap::swerveSubsystemBackLeftRotationTalon->SetSelectedSensorPosition(0, 0, 10);
	RobotMap::swerveSubsystemBackRightRotationTalon->SetSelectedSensorPosition(0, 0, 10);
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	//TODO: REMOVE FOR COMP
	RobotMap::swerveSubsystemFrontLeftRotationTalon->Set(ControlMode::Position, 2562);
	RobotMap::swerveSubsystemFrontRightRotationTalon->Set(ControlMode::Position, 4038);
	RobotMap::swerveSubsystemBackLeftRotationTalon->Set(ControlMode::Position, 965);
	RobotMap::swerveSubsystemBackRightRotationTalon->Set(ControlMode::Position, 648);

	RobotMap::swerveSubsystemFrontLeftRotationTalon->SetSelectedSensorPosition(0, 0, 10);
	RobotMap::swerveSubsystemFrontRightRotationTalon->SetSelectedSensorPosition(0, 0, 10);
	RobotMap::swerveSubsystemBackLeftRotationTalon->SetSelectedSensorPosition(0, 0, 10);
	RobotMap::swerveSubsystemBackRightRotationTalon->SetSelectedSensorPosition(0, 0, 10);
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	SmartDashboard::PutNumber("flError", RobotMap::swerveSubsystemFrontLeftRotationTalon->GetClosedLoopError(0));
	SmartDashboard::PutNumber("frError", RobotMap::swerveSubsystemFrontRightRotationTalon->GetClosedLoopError(0));
	SmartDashboard::PutNumber("blError", RobotMap::swerveSubsystemBackLeftRotationTalon->GetClosedLoopError(0));
	SmartDashboard::PutNumber("brError", RobotMap::swerveSubsystemBackRightRotationTalon->GetClosedLoopError(0));
	SmartDashboard::PutNumber("flSetpoint", RobotMap::swerveSubsystemFrontLeftRotationTalon->GetClosedLoopTarget(0));
	SmartDashboard::PutNumber("frSetpoint", RobotMap::swerveSubsystemFrontRightRotationTalon->GetClosedLoopTarget(0));
	SmartDashboard::PutNumber("blSetpoint", RobotMap::swerveSubsystemBackLeftRotationTalon->GetClosedLoopTarget(0));
	SmartDashboard::PutNumber("brSetpoint", RobotMap::swerveSubsystemBackRightRotationTalon->GetClosedLoopTarget(0));
	SmartDashboard::PutNumber("flCurrent", RobotMap::swerveSubsystemFrontLeftRotationTalon->GetSelectedSensorPosition(0));
	SmartDashboard::PutNumber("frCurrent", RobotMap::swerveSubsystemFrontRightRotationTalon->GetSelectedSensorPosition(0));
	SmartDashboard::PutNumber("blCurrent", RobotMap::swerveSubsystemBackLeftRotationTalon->GetSelectedSensorPosition(0));
	SmartDashboard::PutNumber("brCurrent", RobotMap::swerveSubsystemBackRightRotationTalon->GetSelectedSensorPosition(0));

}

void Robot::TestPeriodic() {

}

START_ROBOT_CLASS(Robot);
