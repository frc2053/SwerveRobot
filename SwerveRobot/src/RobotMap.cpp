#include "RobotMap.h"

std::shared_ptr<CANTalon> RobotMap::swerveSubsystemFrontLeftDriveTalon;
std::shared_ptr<CANTalon> RobotMap::swerveSubsystemFrontRightDriveTalon;
std::shared_ptr<CANTalon> RobotMap::swerveSubsystemBackLeftDriveTalon;
std::shared_ptr<CANTalon> RobotMap::swerveSubsystemBackRightDriveTalon;

std::shared_ptr<CANTalon> RobotMap::swerveSubsystemFrontLeftRotationTalon;
std::shared_ptr<CANTalon> RobotMap::swerveSubsystemFrontRightRotationTalon;
std::shared_ptr<CANTalon> RobotMap::swerveSubsystemBackLeftRotationTalon;
std::shared_ptr<CANTalon> RobotMap::swerveSubsystemBackRightRotationTalon;

std::shared_ptr<AHRS> RobotMap::robotIMU;
std::shared_ptr<PowerDistributionPanel> RobotMap::pdp;

void RobotMap::init() {
	swerveSubsystemFrontLeftDriveTalon.reset(new CANTalon(1));
	swerveSubsystemFrontRightDriveTalon.reset(new CANTalon(2));
	swerveSubsystemBackLeftDriveTalon.reset(new CANTalon(3));
	swerveSubsystemBackRightDriveTalon.reset(new CANTalon(4));

	swerveSubsystemFrontLeftRotationTalon.reset(new CANTalon(5));
	swerveSubsystemFrontRightRotationTalon.reset(new CANTalon(6));
	swerveSubsystemBackLeftRotationTalon.reset(new CANTalon(7));
	swerveSubsystemBackRightRotationTalon.reset(new CANTalon(8));

    robotIMU.reset(new AHRS(frc::SPI::Port::kMXP));

    pdp.reset(new frc::PowerDistributionPanel());
}
