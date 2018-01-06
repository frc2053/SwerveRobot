#ifndef SwerveSubsystem_H
#define SwerveSubsystem_H

#include "../RobotMap.h"
#include <Commands/Subsystem.h>

class SwerveSubsystem : public Subsystem {
public:
	SwerveSubsystem();
	void InitDefaultCommand();
	double CalculateRotValue(double setAngle, double speedMulti);
	bool GetIsRotDone();
	double GetAdjYaw();
	void SetAdjYaw(double yaw);
	void SwerveDrive(double xAxis, double yAxis, double rotAxis, double currentYaw);
	void SetIsRotDone(bool isDone);
	void SetIsRotDoneOverride(bool isDone);
	void SetTimesThroughLoop(int timeLoop);
	bool GetIsRotDoneOverride();
	void ZeroYaw();
	std::shared_ptr<TigerSwerve> GetSwerveStuff();
private:
	std::shared_ptr<WPI_TalonSRX> frontRightDriveTalon;
	std::shared_ptr<WPI_TalonSRX> frontLeftDriveTalon;
	std::shared_ptr<WPI_TalonSRX> backRightDriveTalon;
	std::shared_ptr<WPI_TalonSRX> backLeftDriveTalon;

	std::shared_ptr<WPI_TalonSRX> frontRightRotationTalon;
	std::shared_ptr<WPI_TalonSRX> frontLeftRotationTalon;
	std::shared_ptr<WPI_TalonSRX> backRightRotationTalon;
	std::shared_ptr<WPI_TalonSRX> backLeftRotationTalon;

	std::shared_ptr<TigerDrive> tigerDrive;
	std::shared_ptr<TigerSwerve> tigerSwerve;
};

#endif
