#include "RobotMap.h"

std::shared_ptr<CANTalon> RobotMap::swerveSubsystemFrontLeftDriveTalon;
//std::shared_ptr<CANTalon> RobotMap::swerveSubsystemFrontRightDriveTalon;
//std::shared_ptr<CANTalon> RobotMap::swerveSubsystemBackLeftDriveTalon;
//std::shared_ptr<CANTalon> RobotMap::swerveSubsystemBackRightDriveTalon;

std::shared_ptr<CANTalon> RobotMap::swerveSubsystemFrontLeftRotationTalon;
//std::shared_ptr<CANTalon> RobotMap::swerveSubsystemFrontRightRotationTalon;
//std::shared_ptr<CANTalon> RobotMap::swerveSubsystemBackLeftRotationTalon;
//std::shared_ptr<CANTalon> RobotMap::swerveSubsystemBackRightRotationTalon;

std::shared_ptr<AHRS> RobotMap::robotIMU;
std::shared_ptr<frc::PowerDistributionPanel> RobotMap::pdp;
std::shared_ptr<TigerDrive> RobotMap::tigerDrive;
std::shared_ptr<TigerSwerve> RobotMap::tigerSwerve;

void RobotMap::init() {
	
	swerveSubsystemFrontLeftDriveTalon.reset(new CANTalon(1));
	//swerveSubsystemFrontRightDriveTalon.reset(new CANTalon(2));
	//swerveSubsystemBackLeftDriveTalon.reset(new CANTalon(3));
	//swerveSubsystemBackRightDriveTalon.reset(new CANTalon(4));

	swerveSubsystemFrontLeftRotationTalon.reset(new CANTalon(5));
	//swerveSubsystemFrontRightRotationTalon.reset(new CANTalon(6));
	//swerveSubsystemBackLeftRotationTalon.reset(new CANTalon(7));
	//swerveSubsystemBackRightRotationTalon.reset(new CANTalon(8));

	int encoderAbsolutePositionFrontLeft = swerveSubsystemFrontLeftRotationTalon->GetPulseWidthPosition() & 0xFFF;
	swerveSubsystemFrontLeftRotationTalon->SetEncPosition(encoderAbsolutePositionFrontLeft);

	//int encoderAbsolutePositionFrontRight = swerveSubsystemFrontRightRotationTalon->GetPulseWidthPosition() & 0xFFF;
	//swerveSubsystemFrontRightRotationTalon->SetEncPosition(encoderAbsolutePositionFrontRight);

	//int encoderAbsolutePositionBackLeft = swerveSubsystemBackLeftRotationTalon->GetPulseWidthPosition() & 0xFFF;
	//swerveSubsystemBackLeftRotationTalon->SetEncPosition(encoderAbsolutePositionBackLeft);

	//int encoderAbsolutePositionBackRight = swerveSubsystemBackRightRotationTalon->GetPulseWidthPosition() & 0xFFF;
	//swerveSubsystemBackRightRotationTalon->SetEncPosition(encoderAbsolutePositionBackRight);

	swerveSubsystemFrontLeftRotationTalon->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	//swerveSubsystemFrontRightRotationTalon->SetControlMode(CANTalon::ControlMode::kPosition);
	//swerveSubsystemBackLeftRotationTalon->SetControlMode(CANTalon::ControlMode::kPosition);
	//swerveSubsystemBackRightRotationTalon->SetControlMode(CANTalon::ControlMode::kPosition);

	swerveSubsystemFrontLeftRotationTalon->SetFeedbackDevice(CANTalon::CtreMagEncoder_Absolute);
	//swerveSubsystemFrontRightRotationTalon->SetFeedbackDevice(CANTalon::CtreMagEncoder_Absolute);
	//swerveSubsystemBackLeftRotationTalon->SetFeedbackDevice(CANTalon::CtreMagEncoder_Absolute);
	//swerveSubsystemBackRightRotationTalon->SetFeedbackDevice(CANTalon::CtreMagEncoder_Absolute);

	swerveSubsystemFrontLeftRotationTalon->SetSensorDirection(true);
	//swerveSubsystemFrontRightRotationTalon->SetSensorDirection(true);
	//swerveSubsystemBackLeftRotationTalon->SetSensorDirection(true);
	//swerveSubsystemBackRightRotationTalon->SetSensorDirection(true);

	swerveSubsystemFrontLeftRotationTalon->SetInverted(true);
	//swerveSubsystemFrontRightRotationTalon->SetInverted(true);
	//swerveSubsystemBackLeftRotationTalon->SetInverted(true);
	//swerveSubsystemBackRightRotationTalon->SetInverted(true);

	swerveSubsystemFrontLeftRotationTalon->SetControlMode(CANTalon::ControlMode::kPosition);
	//swerveSubsystemFrontRightRotationTalon->SetControlMode(CANTalon::ControlMode::kPosition);
	//swerveSubsystemBackLeftRotationTalon->SetControlMode(CANTalon::ControlMode::kPosition);
	//swerveSubsystemBackRightRotationTalon->SetControlMode(CANTalon::ControlMode::kPosition);

	swerveSubsystemFrontLeftRotationTalon->SetP(.2);
	swerveSubsystemFrontLeftRotationTalon->ConfigPeakOutputVoltage(1.5, -1.5);
	swerveSubsystemFrontLeftRotationTalon->SetAllowableClosedLoopErr(0);

    std::vector<std::shared_ptr<CANTalon>> talons;
    talons.push_back(swerveSubsystemFrontLeftDriveTalon);
    //talons.push_back(swerveSubsystemFrontRightDriveTalon);
    //talons.push_back(swerveSubsystemBackLeftDriveTalon);
    //talons.push_back(swerveSubsystemBackRightDriveTalon);

    talons.push_back(swerveSubsystemFrontLeftRotationTalon);
    //talons.push_back(swerveSubsystemFrontRightRotationTalon);
    //talons.push_back(swerveSubsystemBackLeftRotationTalon);
    //talons.push_back(swerveSubsystemBackRightRotationTalon);

    tigerSwerve.reset(new TigerSwerve(talons));

    robotIMU.reset(new AHRS(frc::SPI::Port::kMXP));

    pdp.reset(new frc::PowerDistributionPanel());
    tigerDrive.reset(new TigerDrive(robotIMU.get()));
}
