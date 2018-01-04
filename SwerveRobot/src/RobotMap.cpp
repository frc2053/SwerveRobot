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

	swerveSubsystemBackLeftDriveTalon->SetInverted(true);
	swerveSubsystemBackRightDriveTalon->SetInverted(true);
	swerveSubsystemFrontLeftDriveTalon->SetInverted(true);
	swerveSubsystemFrontRightDriveTalon->SetInverted(true);

	int encoderAbsolutePositionFrontLeft = swerveSubsystemFrontLeftRotationTalon->GetPulseWidthPosition() & 0xFFF;
	swerveSubsystemFrontLeftRotationTalon->SetPulseWidthPosition(encoderAbsolutePositionFrontLeft);

	int encoderAbsolutePositionFrontRight = swerveSubsystemFrontRightRotationTalon->GetPulseWidthPosition() & 0xFFF;
	swerveSubsystemFrontRightRotationTalon->SetPulseWidthPosition(encoderAbsolutePositionFrontRight);

	int encoderAbsolutePositionBackLeft = swerveSubsystemBackLeftRotationTalon->GetPulseWidthPosition() & 0xFFF;
	swerveSubsystemBackLeftRotationTalon->SetPulseWidthPosition(encoderAbsolutePositionBackLeft);

	int encoderAbsolutePositionBackRight = swerveSubsystemBackRightRotationTalon->GetPulseWidthPosition() & 0xFFF;
	swerveSubsystemBackRightRotationTalon->SetPulseWidthPosition(encoderAbsolutePositionBackRight);

	swerveSubsystemFrontLeftRotationTalon->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	swerveSubsystemFrontRightRotationTalon->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	swerveSubsystemBackLeftRotationTalon->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	swerveSubsystemBackRightRotationTalon->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);

	swerveSubsystemFrontLeftRotationTalon->SetSensorDirection(true);
	swerveSubsystemFrontRightRotationTalon->SetSensorDirection(true);
	swerveSubsystemBackLeftRotationTalon->SetSensorDirection(true);
	swerveSubsystemBackRightRotationTalon->SetSensorDirection(true);

	swerveSubsystemFrontLeftRotationTalon->SetInverted(false);
	swerveSubsystemFrontRightRotationTalon->SetInverted(false);
	swerveSubsystemBackLeftRotationTalon->SetInverted(false);
	swerveSubsystemBackRightRotationTalon->SetInverted(false);

	swerveSubsystemFrontLeftRotationTalon->SetControlMode(CANTalon::ControlMode::kPosition);
	swerveSubsystemFrontRightRotationTalon->SetControlMode(CANTalon::ControlMode::kPosition);
	swerveSubsystemBackLeftRotationTalon->SetControlMode(CANTalon::ControlMode::kPosition);
	swerveSubsystemBackRightRotationTalon->SetControlMode(CANTalon::ControlMode::kPosition);

	swerveSubsystemFrontLeftRotationTalon->SetP(3);
	swerveSubsystemFrontLeftRotationTalon->SetI(0);
	swerveSubsystemFrontLeftRotationTalon->SetD(40);
	//swerveSubsystemFrontLeftRotationTalon->ConfigPeakOutputVoltage(3, -3);
	swerveSubsystemFrontLeftRotationTalon->SetAllowableClosedLoopErr(10);

	swerveSubsystemFrontRightRotationTalon->SetP(3);
	swerveSubsystemFrontRightRotationTalon->SetI(0);
	swerveSubsystemFrontRightRotationTalon->SetD(40);
	//swerveSubsystemFrontRightRotationTalon->ConfigPeakOutputVoltage(3, -3);
	swerveSubsystemFrontRightRotationTalon->SetAllowableClosedLoopErr(10);

	swerveSubsystemBackLeftRotationTalon->SetP(3);
	swerveSubsystemBackLeftRotationTalon->SetI(0);
	swerveSubsystemBackLeftRotationTalon->SetD(40);

	//swerveSubsystemBackLeftRotationTalon->ConfigPeakOutputVoltage(3, -3);
	swerveSubsystemBackLeftRotationTalon->SetAllowableClosedLoopErr(10);

	swerveSubsystemBackRightRotationTalon->SetP(3);
	swerveSubsystemBackRightRotationTalon->SetI(0);
	swerveSubsystemBackRightRotationTalon->SetD(40);

	//swerveSubsystemBackRightRotationTalon->ConfigPeakOutputVoltage(3, -3);
	swerveSubsystemBackRightRotationTalon->SetAllowableClosedLoopErr(10);


	CANTalon::FeedbackDeviceStatus isBRPresent = swerveSubsystemBackRightRotationTalon->IsSensorPresent(CANTalon::CtreMagEncoder_Relative);
	CANTalon::FeedbackDeviceStatus isFRPresent = swerveSubsystemFrontRightRotationTalon->IsSensorPresent(CANTalon::CtreMagEncoder_Relative);

	std::cout << "isBRPresent: " << isBRPresent << std::endl;
	std::cout << "isFRPresent: " << isFRPresent << std::endl;

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
