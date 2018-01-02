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
std::shared_ptr<frc::PowerDistributionPanel> RobotMap::pdp;
std::shared_ptr<TigerDrive> RobotMap::tigerDrive;
std::shared_ptr<TigerSwerve> RobotMap::tigerSwerve;

void RobotMap::init() {
	
	swerveSubsystemFrontLeftDriveTalon.reset(new CANTalon(2));
	swerveSubsystemFrontRightDriveTalon.reset(new CANTalon(3));
	swerveSubsystemBackLeftDriveTalon.reset(new CANTalon(4));
	swerveSubsystemBackRightDriveTalon.reset(new CANTalon(5));

	swerveSubsystemFrontLeftRotationTalon.reset(new CANTalon(6));
	swerveSubsystemFrontRightRotationTalon.reset(new CANTalon(7));
	swerveSubsystemBackLeftRotationTalon.reset(new CANTalon(8));
	swerveSubsystemBackRightRotationTalon.reset(new CANTalon(9));

	swerveSubsystemFrontLeftRotationTalon->SetEncPosition(0);
	swerveSubsystemFrontRightRotationTalon->SetEncPosition(0);
	swerveSubsystemBackLeftRotationTalon->SetEncPosition(0);
	swerveSubsystemBackRightRotationTalon->SetEncPosition(0);

	int encoderAbsolutePositionFrontLeft = swerveSubsystemFrontLeftRotationTalon->GetPulseWidthPosition() & 0xFFF;
	swerveSubsystemFrontLeftRotationTalon->SetEncPosition(encoderAbsolutePositionFrontLeft);

	int encoderAbsolutePositionFrontRight = swerveSubsystemFrontRightRotationTalon->GetPulseWidthPosition() & 0xFFF;
	swerveSubsystemFrontRightRotationTalon->SetEncPosition(encoderAbsolutePositionFrontRight);

	std::cout << "encPos: " << swerveSubsystemFrontRightRotationTalon->GetEncPosition() << std::endl;
	std::cout << "pos: " << swerveSubsystemFrontRightRotationTalon->GetPosition() << std::endl;
	std::cout << "pulseWidth: " << swerveSubsystemFrontRightRotationTalon->GetPulseWidthPosition() << std::endl;

	int encoderAbsolutePositionBackLeft = swerveSubsystemBackLeftRotationTalon->GetPulseWidthPosition() & 0xFFF;
	swerveSubsystemBackLeftRotationTalon->SetEncPosition(encoderAbsolutePositionBackLeft);

	int encoderAbsolutePositionBackRight = swerveSubsystemBackRightRotationTalon->GetPulseWidthPosition() & 0xFFF;
	swerveSubsystemBackRightRotationTalon->SetEncPosition(encoderAbsolutePositionBackRight);

	swerveSubsystemFrontLeftRotationTalon->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	swerveSubsystemFrontRightRotationTalon->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	swerveSubsystemBackLeftRotationTalon->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	swerveSubsystemBackRightRotationTalon->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);

	swerveSubsystemFrontLeftRotationTalon->SetSensorDirection(true);
	swerveSubsystemFrontRightRotationTalon->SetSensorDirection(true);
	swerveSubsystemBackLeftRotationTalon->SetSensorDirection(true);
	swerveSubsystemBackRightRotationTalon->SetSensorDirection(true);

	swerveSubsystemFrontLeftRotationTalon->SetInverted(true);
	swerveSubsystemFrontRightRotationTalon->SetInverted(true);
	swerveSubsystemBackLeftRotationTalon->SetInverted(true);
	swerveSubsystemBackRightRotationTalon->SetInverted(true);

	swerveSubsystemFrontLeftRotationTalon->SetControlMode(CANTalon::ControlMode::kPosition);
	swerveSubsystemFrontRightRotationTalon->SetControlMode(CANTalon::ControlMode::kPosition);
	swerveSubsystemBackLeftRotationTalon->SetControlMode(CANTalon::ControlMode::kPosition);
	swerveSubsystemBackRightRotationTalon->SetControlMode(CANTalon::ControlMode::kPosition);

	swerveSubsystemFrontLeftRotationTalon->SetP(.5);
	swerveSubsystemFrontLeftRotationTalon->ConfigPeakOutputVoltage(3, -3);
	swerveSubsystemFrontLeftRotationTalon->SetAllowableClosedLoopErr(10);

	swerveSubsystemFrontRightRotationTalon->SetP(.5);
	swerveSubsystemFrontRightRotationTalon->ConfigPeakOutputVoltage(3, -3);
	swerveSubsystemFrontRightRotationTalon->SetAllowableClosedLoopErr(10);

	swerveSubsystemBackLeftRotationTalon->SetP(.5);
	swerveSubsystemBackLeftRotationTalon->ConfigPeakOutputVoltage(3, -3);
	swerveSubsystemBackLeftRotationTalon->SetAllowableClosedLoopErr(10);

	swerveSubsystemBackRightRotationTalon->SetP(.5);
	swerveSubsystemBackRightRotationTalon->ConfigPeakOutputVoltage(3, -3);
	swerveSubsystemBackRightRotationTalon->SetAllowableClosedLoopErr(10);

	swerveSubsystemFrontLeftDriveTalon->ConfigPeakOutputVoltage(3, -3);
	swerveSubsystemFrontRightDriveTalon->ConfigPeakOutputVoltage(3, -3);
	swerveSubsystemBackLeftDriveTalon->ConfigPeakOutputVoltage(3, -3);
	swerveSubsystemBackRightDriveTalon->ConfigPeakOutputVoltage(3, -3);


    std::vector<std::shared_ptr<CANTalon>> talons;
    talons.push_back(swerveSubsystemFrontLeftDriveTalon);
    talons.push_back(swerveSubsystemFrontRightDriveTalon);
    talons.push_back(swerveSubsystemBackLeftDriveTalon);
    talons.push_back(swerveSubsystemBackRightDriveTalon);

    talons.push_back(swerveSubsystemFrontLeftRotationTalon);
    talons.push_back(swerveSubsystemFrontRightRotationTalon);
    talons.push_back(swerveSubsystemBackLeftRotationTalon);
    talons.push_back(swerveSubsystemBackRightRotationTalon);

    tigerSwerve.reset(new TigerSwerve(talons));

    robotIMU.reset(new AHRS(frc::SPI::Port::kMXP));

    pdp.reset(new frc::PowerDistributionPanel());
    tigerDrive.reset(new TigerDrive(robotIMU.get()));
}
