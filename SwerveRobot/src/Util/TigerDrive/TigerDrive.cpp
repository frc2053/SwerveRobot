#include "TigerDrive.h"

TigerDrive::TigerDrive(AHRS* imu)
{

}

TigerDrive::~TigerDrive() {

}

double TigerDrive::CalculateRotationValue(double angleToRotateTo, double speedMultiplier) {

}

double TigerDrive::CalculateSpinDirection(double targetAngle) {
	double imuYaw = imu->GetYaw();
	double degreesToAngle = 0;
	if((fabs(imuYaw - targetAngle) > angleTolerance) &&
	   (fabs(imuYaw + 360 - targetAngle) > angleTolerance)) {
		if (imuYaw > targetAngle)  {
			tooFarCW = true;
			spinDirection = -1;
			degreesToAngle = imuYaw - targetAngle;
		}
		else {
			tooFarCCW = true;
			spinDirection = 1;
			degreesToAngle = targetAngle - imuYaw;
		}
	}
	return degreesToAngle;
}
