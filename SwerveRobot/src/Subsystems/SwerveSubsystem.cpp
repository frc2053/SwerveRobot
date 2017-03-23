#include "SwerveSubsystem.h"

SwerveSubsystem::SwerveSubsystem() : Subsystem("SwerveSubsystem") {
	frontLeftDriveTalon = RobotMap::swerveSubsystemFrontLeftDriveTalon;
	frontRightDriveTalon = RobotMap::swerveSubsystemFrontRightDriveTalon;
	backLeftDriveTalon = RobotMap::swerveSubsystemBackLeftDriveTalon;
	backRightDriveTalon = RobotMap::swerveSubsystemBackRightDriveTalon;

	frontLeftRotationTalon = RobotMap::swerveSubsystemFrontLeftRotationTalon;
	frontRightRotationTalon = RobotMap::swerveSubsystemFrontRightRotationTalon;
	backLeftRotationTalon = RobotMap::swerveSubsystemBackLeftRotationTalon;
	backRightRotationTalon = RobotMap::swerveSubsystemFrontLeftRotationTalon;

	tigerDrive = RobotMap::tigerDrive;
	tigerSwerve = RobotMap::tigerSwerve;
}

void SwerveSubsystem::InitDefaultCommand() {

}

double SwerveSubsystem::CalculateRotValue(double setAngle, double setSpeed)
{
	return tigerDrive->CalculateRotationValue(setAngle, setSpeed);
}

bool SwerveSubsystem::GetIsRotDone()
{
	return tigerDrive->GetIsRotDone();
}

double SwerveSubsystem::GetAdjYaw() {
	return tigerDrive->GetAdjYaw();
}

void SwerveSubsystem::SetAdjYaw(double yaw) {
	tigerDrive->SetAdjYaw(yaw);
}

void SwerveSubsystem::SetIsRotDone(bool isDone)
{
	tigerDrive->SetIsRotDone(isDone);
}

void SwerveSubsystem::SetIsRotDoneOverride(bool isDone)
{
	tigerDrive->SetIsRotDoneOverride(isDone);
}

void SwerveSubsystem::SetTimesThroughLoop(int timeLoop)
{
	tigerDrive->SetTimesThroughLoop(timeLoop);
}

bool SwerveSubsystem::GetIsRotDoneOverride() {
	return tigerDrive->GetIsRotDoneOverride();
}

void SwerveSubsystem::ZeroYaw() {
	tigerDrive->imu->ZeroYaw();
}

void SwerveSubsystem::SwerveDrive(double xAxis, double yAxis, double rotAxis, double currentYaw) {
	tigerSwerve->CalculateSpeedAndAngleOfWheels(xAxis, yAxis, rotAxis, currentYaw);
}
