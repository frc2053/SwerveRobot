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
}

void SwerveSubsystem::InitDefaultCommand() {

}
