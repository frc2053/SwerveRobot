#ifndef SRC_UTIL_TIGERSWERVE_SWERVEMODULE_H_
#define SRC_UTIL_TIGERSWERVE_SWERVEMODULE_H_

#include "../Math/Vector.h"
#include <math.h>
#include "ctrlib/CANTalon.h"

class SwerveModule {
public:
	SwerveModule(std::shared_ptr<CANTalon> driveController, std::shared_ptr<CANTalon> rotateController, double locationX, double locationY);
	virtual ~SwerveModule();
	void Set(double angle, double speed);
	void Stop();
	double NormalizeAngle(double angle);
	Vector GetLocation();
private:
	std::shared_ptr<CANTalon> _driveController;
	std::shared_ptr<CANTalon> _rotateController;
	std::shared_ptr<Vector> _location;
};

#endif
