#ifndef SRC_UTIL_TIGERSWERVE_TIGERSWERVE_H_
#define SRC_UTIL_TIGERSWERVE_TIGERSWERVE_H_

#include "math.h"
#include "CANTalon.h"

class TigerSwerve {
private:
	const double LENGTH_TO_CENTER = 20;
	const double WIDTH_TO_CENTER = 20;
	std::vector<double> toNormalize;
	double xAxis = 0, yAxis = 0, rotAxis = 0, currentYaw = 0;
	std::shared_ptr<CANTalon> frontRightDrive;
	std::shared_ptr<CANTalon> frontLeftDrive;
	std::shared_ptr<CANTalon> backRightDrive;
	std::shared_ptr<CANTalon> backLeftDrive;

	std::shared_ptr<CANTalon> frontRightRot;
	std::shared_ptr<CANTalon> frontLeftRot;
	std::shared_ptr<CANTalon> backRightRot;
	std::shared_ptr<CANTalon> backLeftRot;

	struct speedAndAngle {
		double speed = 0;
		double angle = 0;
	};
public:
	TigerSwerve(std::vector<std::shared_ptr<CANTalon>>& talons);
	virtual ~TigerSwerve();
	void CalculateSpeedAndAngleOfWheels(double _xAxis, double _yAxis, double _rotAxis, double _gyroAngle);
	TigerSwerve::speedAndAngle CalculateMotorSpeed(bool isRight, bool isFront);
	double Normalize(double input, double max);
	void RunDriveMotors(double bL, double bR, double fL, double fR);
	void RunRotationMotors(double bL, double bR, double fL, double fR);
	TigerSwerve::speedAndAngle CalculateAngleAdjustments(TigerSwerve::speedAndAngle currentAngleAndSpeed);
};

#endif
