#include "RobotMap.h"

std::shared_ptr<WPI_TalonSRX> RobotMap::swerveSubsystemFrontLeftDriveTalon;
std::shared_ptr<WPI_TalonSRX> RobotMap::swerveSubsystemFrontRightDriveTalon;
std::shared_ptr<WPI_TalonSRX> RobotMap::swerveSubsystemBackLeftDriveTalon;
std::shared_ptr<WPI_TalonSRX> RobotMap::swerveSubsystemBackRightDriveTalon;

std::shared_ptr<WPI_TalonSRX> RobotMap::swerveSubsystemFrontLeftRotationTalon;
std::shared_ptr<WPI_TalonSRX> RobotMap::swerveSubsystemFrontRightRotationTalon;
std::shared_ptr<WPI_TalonSRX> RobotMap::swerveSubsystemBackLeftRotationTalon;
std::shared_ptr<WPI_TalonSRX> RobotMap::swerveSubsystemBackRightRotationTalon;

std::shared_ptr<AHRS> RobotMap::robotIMU;
std::shared_ptr<frc::PowerDistributionPanel> RobotMap::pdp;
std::shared_ptr<TigerDrive> RobotMap::tigerDrive;
std::shared_ptr<TigerSwerve> RobotMap::tigerSwerve;

void RobotMap::init() {
	
    pdp.reset(new frc::PowerDistributionPanel());
    SmartDashboard::PutData(pdp.get());

	swerveSubsystemFrontLeftDriveTalon.reset(new WPI_TalonSRX(2));
	swerveSubsystemFrontRightDriveTalon.reset(new WPI_TalonSRX(3));
	swerveSubsystemBackLeftDriveTalon.reset(new WPI_TalonSRX(4));
	swerveSubsystemBackRightDriveTalon.reset(new WPI_TalonSRX(5));

	swerveSubsystemFrontLeftRotationTalon.reset(new WPI_TalonSRX(6));
	swerveSubsystemFrontRightRotationTalon.reset(new WPI_TalonSRX(7));
	swerveSubsystemBackLeftRotationTalon.reset(new WPI_TalonSRX(8));
	swerveSubsystemBackRightRotationTalon.reset(new WPI_TalonSRX(9));

	swerveSubsystemBackLeftDriveTalon->SetInverted(true);
	swerveSubsystemBackRightDriveTalon->SetInverted(true);
	swerveSubsystemFrontLeftDriveTalon->SetInverted(true);
	swerveSubsystemFrontRightDriveTalon->SetInverted(true);

	swerveSubsystemFrontLeftRotationTalon->ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);
	swerveSubsystemFrontRightRotationTalon->ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);
	swerveSubsystemBackLeftRotationTalon->ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);
	swerveSubsystemBackRightRotationTalon->ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);


	int encoderAbsolutePositionFrontLeft = swerveSubsystemFrontLeftRotationTalon->GetSensorCollection().GetPulseWidthPosition() & 0xFFF;
	swerveSubsystemFrontLeftRotationTalon->SetSelectedSensorPosition(encoderAbsolutePositionFrontLeft, 0, 10);

	int encoderAbsolutePositionFrontRight = swerveSubsystemFrontRightRotationTalon->GetSensorCollection().GetPulseWidthPosition() & 0xFFF;
	swerveSubsystemFrontRightRotationTalon->SetSelectedSensorPosition(encoderAbsolutePositionFrontRight, 0, 10);

	int encoderAbsolutePositionBackLeft = swerveSubsystemBackLeftRotationTalon->GetSensorCollection().GetPulseWidthPosition() & 0xFFF;
	swerveSubsystemBackLeftRotationTalon->SetSelectedSensorPosition(encoderAbsolutePositionBackLeft, 0, 10);

	int encoderAbsolutePositionBackRight = swerveSubsystemBackRightRotationTalon->GetSensorCollection().GetPulseWidthPosition() & 0xFFF;
	swerveSubsystemBackRightRotationTalon->SetSelectedSensorPosition(encoderAbsolutePositionBackRight, 0, 10);

    std::cout << "fl quad1: " << swerveSubsystemFrontLeftRotationTalon->GetSensorCollection().GetQuadraturePosition() << std::endl;
    std::cout << "fr quad1: " << swerveSubsystemFrontRightRotationTalon->GetSensorCollection().GetQuadraturePosition() << std::endl;
    std::cout << "bl quad1: " << swerveSubsystemBackLeftRotationTalon->GetSensorCollection().GetQuadraturePosition() << std::endl;
    std::cout << "br quad1: " << swerveSubsystemBackRightRotationTalon->GetSensorCollection().GetQuadraturePosition() << std::endl;

    std::cout << "fl abs2: " << swerveSubsystemFrontLeftRotationTalon->GetSensorCollection().GetPulseWidthPosition() << std::endl;
    std::cout << "fr abs2: " << swerveSubsystemFrontRightRotationTalon->GetSensorCollection().GetPulseWidthPosition() << std::endl;
    std::cout << "bl abs2: " << swerveSubsystemBackLeftRotationTalon->GetSensorCollection().GetPulseWidthPosition() << std::endl;
    std::cout << "br abs2: " << swerveSubsystemBackRightRotationTalon->GetSensorCollection().GetPulseWidthPosition() << std::endl;

    swerveSubsystemFrontLeftRotationTalon->SetSelectedSensorPosition(0, 0, 10);
    swerveSubsystemFrontRightRotationTalon->SetSelectedSensorPosition(0, 0, 10);
    swerveSubsystemBackLeftRotationTalon->SetSelectedSensorPosition(0, 0, 10);
    swerveSubsystemBackRightRotationTalon->SetSelectedSensorPosition(0, 0, 10);

    std::cout << "fl quad3: " << swerveSubsystemFrontLeftRotationTalon->GetSensorCollection().GetQuadraturePosition() << std::endl;
    std::cout << "fr quad3: " << swerveSubsystemFrontRightRotationTalon->GetSensorCollection().GetQuadraturePosition() << std::endl;
    std::cout << "bl quad3: " << swerveSubsystemBackLeftRotationTalon->GetSensorCollection().GetQuadraturePosition() << std::endl;
    std::cout << "br quad3: " << swerveSubsystemBackRightRotationTalon->GetSensorCollection().GetQuadraturePosition() << std::endl;

	swerveSubsystemFrontLeftRotationTalon->SetSensorPhase(false);
	swerveSubsystemFrontRightRotationTalon->SetSensorPhase(false);
	swerveSubsystemBackLeftRotationTalon->SetSensorPhase(false);
	swerveSubsystemBackRightRotationTalon->SetSensorPhase(false);

	swerveSubsystemFrontLeftRotationTalon->SetInverted(true);
	swerveSubsystemFrontRightRotationTalon->SetInverted(true);
	swerveSubsystemBackLeftRotationTalon->SetInverted(true);
	swerveSubsystemBackRightRotationTalon->SetInverted(true);

	swerveSubsystemFrontLeftRotationTalon->Set(ctre::phoenix::motorcontrol::ControlMode::Position, 0);
	swerveSubsystemFrontRightRotationTalon->Set(ctre::phoenix::motorcontrol::ControlMode::Position, 0);
	swerveSubsystemBackLeftRotationTalon->Set(ctre::phoenix::motorcontrol::ControlMode::Position, 0);
	swerveSubsystemBackRightRotationTalon->Set(ctre::phoenix::motorcontrol::ControlMode::Position, 0);

	swerveSubsystemFrontLeftRotationTalon->Config_kP(0, 2, 10);
	swerveSubsystemFrontLeftRotationTalon->Config_kI(0, 0, 10);
	swerveSubsystemFrontLeftRotationTalon->Config_kD(0, .2, 10);
	swerveSubsystemFrontLeftRotationTalon->ConfigPeakOutputForward(.416, 10);
	swerveSubsystemFrontLeftRotationTalon->ConfigPeakOutputReverse(-.416, 10);
	swerveSubsystemFrontLeftRotationTalon->ConfigAllowableClosedloopError(0, 35, 10);
	swerveSubsystemFrontLeftRotationTalon->ConfigContinuousCurrentLimit(10, 10);
	swerveSubsystemFrontLeftRotationTalon->ConfigPeakCurrentLimit(0, 10);


	swerveSubsystemFrontRightRotationTalon->Config_kP(0, 2, 10);
	swerveSubsystemFrontRightRotationTalon->Config_kI(0, 0, 10);
	swerveSubsystemFrontRightRotationTalon->Config_kD(0, .2, 10);
	swerveSubsystemFrontRightRotationTalon->ConfigPeakOutputForward(.416, 10);
	swerveSubsystemFrontRightRotationTalon->ConfigPeakOutputReverse(-.416, 10);
	swerveSubsystemFrontRightRotationTalon->ConfigAllowableClosedloopError(0, 10, 10);
	swerveSubsystemFrontRightRotationTalon->ConfigContinuousCurrentLimit(10, 10);
	swerveSubsystemFrontRightRotationTalon->ConfigPeakCurrentLimit(0, 10);


	swerveSubsystemBackLeftRotationTalon->Config_kP(0, 2, 10);
	swerveSubsystemBackLeftRotationTalon->Config_kI(0, 0, 10);
	swerveSubsystemBackLeftRotationTalon->Config_kD(0, .2, 10);
	swerveSubsystemBackLeftRotationTalon->ConfigPeakOutputForward(.416, 10);
	swerveSubsystemBackLeftRotationTalon->ConfigPeakOutputReverse(-.416, 10);
	swerveSubsystemBackLeftRotationTalon->ConfigAllowableClosedloopError(0, 10, 10);
	swerveSubsystemBackLeftRotationTalon->ConfigContinuousCurrentLimit(10, 10);
	swerveSubsystemBackLeftRotationTalon->ConfigPeakCurrentLimit(0, 10);


	swerveSubsystemBackRightRotationTalon->Config_kP(0, 1.7, 10);
	swerveSubsystemBackRightRotationTalon->Config_kI(0, 0, 10);
	swerveSubsystemBackRightRotationTalon->Config_kD(0, 0, 10);
	swerveSubsystemBackRightRotationTalon->ConfigPeakOutputForward(.416, 10);
	swerveSubsystemBackRightRotationTalon->ConfigPeakOutputReverse(-.416, 10);
	swerveSubsystemBackRightRotationTalon->ConfigAllowableClosedloopError(0, 35, 10);
	swerveSubsystemBackRightRotationTalon->ConfigContinuousCurrentLimit(10, 10);
	swerveSubsystemBackRightRotationTalon->ConfigPeakCurrentLimit(0, 10);



    std::vector<std::shared_ptr<WPI_TalonSRX>> talons;
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
    tigerDrive.reset(new TigerDrive(robotIMU.get()));

}
