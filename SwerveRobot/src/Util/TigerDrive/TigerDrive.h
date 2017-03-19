#ifndef SRC_TIGERDRIVE_TIGERDRIVE_H_
#define SRC_TIGERDRIVE_TIGERDRIVE_H_

#include "AHRS.h"
#include "WPILib.h"

class TigerDrive
{
private:
	const double K_P = 0.0;
	const double K_I = 0.0;
	const double K_D = 0.0;
	const double K_F = 0.0;

	std::shared_ptr<AHRS> imu;
	std::shared_ptr<frc::PIDController> rotateController;
public:
	TigerDrive(AHRS* imu);
	~TigerDrive();
	double CalculateRotationValue(double angleToRotateTo, double speedMultiplier);
	double CalculateSpinDirection(double targetAngle);
};
#endif
