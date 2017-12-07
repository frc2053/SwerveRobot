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
	//std::shared_ptr<CANTalon> frontRightDriveTalon;
	std::shared_ptr<CANTalon> frontLeftDriveTalon;
	//std::shared_ptr<CANTalon> backRightDriveTalon;
	//std::shared_ptr<CANTalon> backLeftDriveTalon;

	//std::shared_ptr<CANTalon> frontRightRotationTalon;
	std::shared_ptr<CANTalon> frontLeftRotationTalon;
	//std::shared_ptr<CANTalon> backRightRotationTalon;
	//std::shared_ptr<CANTalon> backLeftRotationTalon;

	std::shared_ptr<TigerDrive> tigerDrive;
	std::shared_ptr<TigerSwerve> tigerSwerve;
};

#endif
