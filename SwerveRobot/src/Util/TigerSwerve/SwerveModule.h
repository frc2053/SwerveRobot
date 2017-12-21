#ifndef SRC_UTIL_TIGERSWERVE_SWERVEMODULE_H_
#define SRC_UTIL_TIGERSWERVE_SWERVEMODULE_H_

#include <math.h>
#include <Util/Math/Rotation2D.h>
#include "ctrlib/CANTalon.h"
#include "CTREMagEncoder.h"

class SwerveModule {
public:
	SwerveModule(std::shared_ptr<CANTalon> driveController, std::shared_ptr<CANTalon> rotateController);
	virtual ~SwerveModule();

	Rotation2D GetAngle() const;
	void SetAngle(Rotation2D angle);
	void Set(double speed, Rotation2D angle);
	void Stop();
private:
	std::shared_ptr<CANTalon> _driveController;
	std::shared_ptr<CANTalon> _rotateController;
	std::shared_ptr<CTREMagEncoder> _angleEncoder;
	bool isOptimizedAngle;
};

#endif
