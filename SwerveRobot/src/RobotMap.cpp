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
	
	swerveSubsystemFrontLeftDriveTalon.reset(new WPI_TalonSRX(2));
	swerveSubsystemFrontRightDriveTalon.reset(new WPI_TalonSRX(3));
	swerveSubsystemBackLeftDriveTalon.reset(new WPI_TalonSRX(4));
	swerveSubsystemBackRightDriveTalon.reset(new WPI_TalonSRX(5));

	swerveSubsystemFrontLeftRotationTalon.reset(new WPI_TalonSRX(6));
	swerveSubsystemFrontRightRotationTalon.reset(new WPI_TalonSRX(7));
	swerveSubsystemBackLeftRotationTalon.reset(new WPI_TalonSRX(8));
	swerveSubsystemBackRightRotationTalon.reset(new WPI_TalonSRX(9));

	swerveSubsystemFrontLeftRotationTalon->GetSensorCollection().SetQuadraturePosition(0, 10);
	swerveSubsystemFrontRightRotationTalon->GetSensorCollection().SetQuadraturePosition(0, 10);
	swerveSubsystemBackLeftRotationTalon->GetSensorCollection().SetQuadraturePosition(0, 10);
	swerveSubsystemBackRightRotationTalon->GetSensorCollection().SetQuadraturePosition(0, 10);

	swerveSubsystemBackLeftDriveTalon->SetInverted(true);
	swerveSubsystemBackRightDriveTalon->SetInverted(true);
	swerveSubsystemFrontLeftDriveTalon->SetInverted(true);
	swerveSubsystemFrontRightDriveTalon->SetInverted(true);

	int encoderAbsolutePositionFrontLeft = swerveSubsystemFrontLeftRotationTalon->GetSensorCollection().GetPulseWidthPosition() & 0xFFF;
	swerveSubsystemFrontLeftRotationTalon->GetSensorCollection().SetPulseWidthPosition(encoderAbsolutePositionFrontLeft, 10);

	int encoderAbsolutePositionFrontRight = swerveSubsystemFrontRightRotationTalon->GetSensorCollection().GetPulseWidthPosition() & 0xFFF;
	swerveSubsystemFrontRightRotationTalon->GetSensorCollection().SetPulseWidthPosition(encoderAbsolutePositionFrontRight, 10);

	int encoderAbsolutePositionBackLeft = swerveSubsystemBackLeftRotationTalon->GetSensorCollection().GetPulseWidthPosition() & 0xFFF;
	swerveSubsystemBackLeftRotationTalon->GetSensorCollection().SetPulseWidthPosition(encoderAbsolutePositionBackLeft, 10);

	int encoderAbsolutePositionBackRight = swerveSubsystemBackRightRotationTalon->GetSensorCollection().GetPulseWidthPosition() & 0xFFF;
	swerveSubsystemBackRightRotationTalon->GetSensorCollection().SetPulseWidthPosition(encoderAbsolutePositionBackRight, 10);

	swerveSubsystemFrontLeftRotationTalon->ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);
	swerveSubsystemFrontRightRotationTalon->ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);
	swerveSubsystemBackLeftRotationTalon->ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);
	swerveSubsystemBackRightRotationTalon->ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);

	swerveSubsystemFrontLeftRotationTalon->SetSensorPhase(true);
	swerveSubsystemFrontRightRotationTalon->SetSensorPhase(true);
	swerveSubsystemBackLeftRotationTalon->SetSensorPhase(true);
	swerveSubsystemBackRightRotationTalon->SetSensorPhase(true);

	swerveSubsystemFrontLeftRotationTalon->SetInverted(false);
	swerveSubsystemFrontRightRotationTalon->SetInverted(false);
	swerveSubsystemBackLeftRotationTalon->SetInverted(false);
	swerveSubsystemBackRightRotationTalon->SetInverted(false);

	swerveSubsystemFrontLeftRotationTalon->Set(ctre::phoenix::motorcontrol::ControlMode::Position, 0);
	swerveSubsystemFrontRightRotationTalon->Set(ctre::phoenix::motorcontrol::ControlMode::Position, 0);
	swerveSubsystemBackLeftRotationTalon->Set(ctre::phoenix::motorcontrol::ControlMode::Position, 0);
	swerveSubsystemBackRightRotationTalon->Set(ctre::phoenix::motorcontrol::ControlMode::Position, 0);

	swerveSubsystemFrontLeftRotationTalon->Config_kP(0, 6, 10);
	swerveSubsystemFrontLeftRotationTalon->Config_kI(0, 0, 10);
	swerveSubsystemFrontLeftRotationTalon->Config_kD(0, 15, 10);
	swerveSubsystemFrontLeftRotationTalon->ConfigPeakOutputForward(1, 10);
	swerveSubsystemFrontLeftRotationTalon->ConfigPeakOutputReverse(-1, 10);
	swerveSubsystemFrontLeftRotationTalon->ConfigAllowableClosedloopError(0, 35, 10);


	swerveSubsystemFrontRightRotationTalon->Config_kP(0, 6, 10);
	swerveSubsystemFrontRightRotationTalon->Config_kI(0, 0, 10);
	swerveSubsystemFrontRightRotationTalon->Config_kD(0, 15, 10);
	swerveSubsystemFrontRightRotationTalon->ConfigPeakOutputForward(1, 10);
	swerveSubsystemFrontRightRotationTalon->ConfigPeakOutputReverse(-1, 10);
	swerveSubsystemFrontRightRotationTalon->ConfigAllowableClosedloopError(0, 35, 10);

	swerveSubsystemBackLeftRotationTalon->Config_kP(0, 6, 10);
	swerveSubsystemBackLeftRotationTalon->Config_kI(0, 0, 10);
	swerveSubsystemBackLeftRotationTalon->Config_kD(0, 15, 10);
	swerveSubsystemBackLeftRotationTalon->ConfigPeakOutputForward(1, 10);
	swerveSubsystemBackLeftRotationTalon->ConfigPeakOutputReverse(-1, 10);
	swerveSubsystemBackLeftRotationTalon->ConfigAllowableClosedloopError(0, 35, 10);

	swerveSubsystemBackRightRotationTalon->Config_kP(0, 6, 10);
	swerveSubsystemBackRightRotationTalon->Config_kI(0, 0, 10);
	swerveSubsystemBackRightRotationTalon->Config_kD(0, 15, 10);
	swerveSubsystemBackRightRotationTalon->ConfigPeakOutputForward(1, 10);
	swerveSubsystemBackRightRotationTalon->ConfigPeakOutputReverse(-1, 10);
	swerveSubsystemBackRightRotationTalon->ConfigAllowableClosedloopError(0, 35, 10);

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

    pdp.reset(new frc::PowerDistributionPanel());
    tigerDrive.reset(new TigerDrive(robotIMU.get()));
}
