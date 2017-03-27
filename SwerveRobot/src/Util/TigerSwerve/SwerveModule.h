#ifndef SRC_UTIL_TIGERSWERVE_SWERVEMODULE_H_
#define SRC_UTIL_TIGERSWERVE_SWERVEMODULE_H_

#include "../Math/Vector.h"

class SwerveModule {
public:
	SwerveModule();
	virtual ~SwerveModule();
	void Set(double angle, double speed);
	void Stop();
	double NormalizeAngle(double angle);
	Vector GetLocation();
private:
	std::shared_ptr<CANTalon> driveController;
	std::shared_ptr<CANTalon> rotateController;
	Vector location;
};

#endif
