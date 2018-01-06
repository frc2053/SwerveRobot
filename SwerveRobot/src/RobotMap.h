#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "AHRS.h"
#include "Util/TigerDrive/TigerDrive.h"
#include "Util/TigerSwerve/TigerSwerve.h"

class RobotMap {
public:
	static void init();

	static std::shared_ptr<WPI_TalonSRX> swerveSubsystemFrontLeftDriveTalon;
	static std::shared_ptr<WPI_TalonSRX> swerveSubsystemFrontRightDriveTalon;
	static std::shared_ptr<WPI_TalonSRX> swerveSubsystemBackLeftDriveTalon;
	static std::shared_ptr<WPI_TalonSRX> swerveSubsystemBackRightDriveTalon;

	static std::shared_ptr<WPI_TalonSRX> swerveSubsystemFrontLeftRotationTalon;
	static std::shared_ptr<WPI_TalonSRX> swerveSubsystemFrontRightRotationTalon;
	static std::shared_ptr<WPI_TalonSRX> swerveSubsystemBackLeftRotationTalon;
	static std::shared_ptr<WPI_TalonSRX> swerveSubsystemBackRightRotationTalon;

	static std::shared_ptr<AHRS> robotIMU;
	static std::shared_ptr<TigerDrive> tigerDrive;
	static std::shared_ptr<PowerDistributionPanel> pdp;
	static std::shared_ptr<TigerSwerve> tigerSwerve;
};
#endif
