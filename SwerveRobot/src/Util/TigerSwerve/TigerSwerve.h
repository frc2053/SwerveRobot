#ifndef SRC_UTIL_TIGERSWERVE_TIGERSWERVE_H_
#define SRC_UTIL_TIGERSWERVE_TIGERSWERVE_H_

#include "math.h"
#include "ctrlib/CANTalon.h"
#include "../Math/Vector.h"
#include "SwerveModule.h"
#include <vector>

class TigerSwerve {
private:
	const double BASE_LENGTH = 20;
	const double BASE_WIDTH = 20;

	double xAxis = 0, yAxis = 0, rotAxis = 0, currentYaw = 0;

	std::shared_ptr<Vector> centerOfRotation;
	std::vector<SwerveModule> modules;

	std::shared_ptr<CANTalon> frontRightDrive;
	std::shared_ptr<CANTalon> frontLeftDrive;
	std::shared_ptr<CANTalon> backRightDrive;
	std::shared_ptr<CANTalon> backLeftDrive;

	std::shared_ptr<CANTalon> frontRightRot;
	std::shared_ptr<CANTalon> frontLeftRot;
	std::shared_ptr<CANTalon> backRightRot;
	std::shared_ptr<CANTalon> backLeftRot;

	void Drive(double xSpeed, double ySpeed, double rotSpeed, double headingOffset);
	double deg2rad(double deg);
public:
	TigerSwerve(std::vector<std::shared_ptr<CANTalon>>& talons);
	virtual ~TigerSwerve();
	void SetCenterOfRotation(double x, double y);
	void SetBrakeMode();
	void DriveRobotOriented(double x, double y, double rotation);
	void DriveFieldOriented(double x, double y, double rotation, double gyro);
};

#endif
