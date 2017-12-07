#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include "ctrlib/CANTalon.h"
#include "AHRS.h"
#include "Util/TigerDrive/TigerDrive.h"
#include "Util/TigerSwerve/TigerSwerve.h"

class RobotMap {
public:
	static void init();

	static std::shared_ptr<CANTalon> swerveSubsystemFrontLeftDriveTalon;
	//static std::shared_ptr<CANTalon> swerveSubsystemFrontRightDriveTalon;
	//static std::shared_ptr<CANTalon> swerveSubsystemBackLeftDriveTalon;
	//static std::shared_ptr<CANTalon> swerveSubsystemBackRightDriveTalon;

	static std::shared_ptr<CANTalon> swerveSubsystemFrontLeftRotationTalon;
	//static std::shared_ptr<CANTalon> swerveSubsystemFrontRightRotationTalon;
	//static std::shared_ptr<CANTalon> swerveSubsystemBackLeftRotationTalon;
	//static std::shared_ptr<CANTalon> swerveSubsystemBackRightRotationTalon;

	static std::shared_ptr<AHRS> robotIMU;
	static std::shared_ptr<TigerDrive> tigerDrive;
	static std::shared_ptr<PowerDistributionPanel> pdp;
	static std::shared_ptr<TigerSwerve> tigerSwerve;
};
#endif
