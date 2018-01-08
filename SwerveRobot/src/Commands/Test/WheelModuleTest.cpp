#include "WheelModuleTest.h"

WheelModuleTest::WheelModuleTest(double setPoint) {
	Requires(Robot::swerveSubsystem.get());
	testsPassed = false;
	talonSetpoint = setPoint;

}

void WheelModuleTest::Initialize() {
	testsPassed = false;
}

void WheelModuleTest::Execute() {
	//test rotations
	for(int i = 0; i < 365; i = i + 45) {
		for(int j = 0; j < 4; j++) {
			Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(i));
		}
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}
	//Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(0).Set(0, Rotation2D::fromDegrees(talonSetpoint));
	//Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(1).Set(0, Rotation2D::fromDegrees(talonSetpoint));
	//Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(2).Set(0, Rotation2D::fromDegrees(talonSetpoint));
	//Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(3).Set(0, Rotation2D::fromDegrees(talonSetpoint));

	//RobotMap::swerveSubsystemBackLeftDriveTalon->Set(ControlMode::PercentOutput, .35);
	//RobotMap::swerveSubsystemBackRightDriveTalon->Set(ControlMode::PercentOutput, .35);
	//RobotMap::swerveSubsystemFrontLeftDriveTalon->Set(ControlMode::PercentOutput, .35);
	//RobotMap::swerveSubsystemFrontRightDriveTalon->Set(ControlMode::PercentOutput, .35);

	testsPassed = true;
}

bool WheelModuleTest::IsFinished() {
	return testsPassed;
}

void WheelModuleTest::End() {
	SmartDashboard::PutBoolean("Executing", false);
	RobotMap::swerveSubsystemBackLeftDriveTalon->Set(ControlMode::PercentOutput, 0);
	RobotMap::swerveSubsystemBackRightDriveTalon->Set(ControlMode::PercentOutput, 0);
	RobotMap::swerveSubsystemFrontLeftDriveTalon->Set(ControlMode::PercentOutput, 0);
	RobotMap::swerveSubsystemFrontRightDriveTalon->Set(ControlMode::PercentOutput, 0);

}

void WheelModuleTest::Interrupted() {

}
