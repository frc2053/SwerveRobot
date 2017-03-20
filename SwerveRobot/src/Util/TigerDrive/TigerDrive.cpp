#include "TigerDrive.h"

TigerDrive::TigerDrive(AHRS* imuP)
{
	tooFarCW = false;
	tooFarCCW = false;
	isRotDone = false;
	timesThroughLoop = 0;
	imu.reset(imuP);
	rotateController.reset(new frc::PIDController(K_P, K_I, K_D, K_F, imu.get(), this));
	rotateToAngleRate = 0;
}

TigerDrive::~TigerDrive() {

}

double TigerDrive::CalculateRotationValue(double angleToRotateTo, double speedMultiplier) {
	int spinDir = CalculateSpinDirection(angleToRotateTo, imu->GetYaw());
	if(!controllerOverride) {
		double speed = CalculateSpeedAndOvershoot(spinDir, speedMultiplier);
	}
	else {
		speed = 0;
	}
	return speed;
}

double TigerDrive::CalculateSpinDirection(double targetAngle, double imuYaw) {
	double degreesToAngle = 0;
	int spinDirection = 0;
	if((fabs(imuYaw - targetAngle) > ANGLE_TOLERANCE) &&
	   (fabs(imuYaw + 360 - targetAngle) > ANGLE_TOLERANCE)) {
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
	if(degreesToAngle > 180)
	{
		degreesToAngle = 360 - degreesToAngle;
		spinDirection = spinDirection * -1;
	}
	return spinDirection;
}

double TigerDrive::CalculateSpeedAndOvershoot(int spinDir, double speedMulti) {
	double calculatedRotate = 0;
	if(tooFarCW || tooFarCCW)
	{
		rotateController->Enable();
		isRotDone = false;
		calculatedRotate = rotateToAngleRate * speedMulti;
		timesThroughLoop = 1;
	}
	else
	{
		if(timesThroughLoop == OVERSHOOT_TIMEOUT || timesThroughLoop == 0)
		{
			rotateController->Disable();
			isRotDone = true;
			timesThroughLoop = 0;
			calculatedRotate = 0;
		}
		timesThroughLoop = timesThroughLoop + 1;
	}
	return calculatedRotate;
}

void TigerDrive::SetAdjYaw(float offset)
{
	yawOffset = offset;
}

void TigerDrive::SetIsRotDone(bool isDone)
{
	isRotDone = isDone;
}

void TigerDrive::SetIsRotDoneOverride(bool isDone)
{
	isRotDoneOverride = isDone;
}

void TigerDrive::SetTimesThroughLoop(int timeLoop)
{
	timesThroughLoop = timeLoop;
}

float TigerDrive::GetImuYaw()
{
	return imuYaw;
}

bool TigerDrive::GetIsRotDone()
{
	return isRotDone;
}

bool TigerDrive::GetIsRotDoneOverride()
{
	return isRotDoneOverride;
}
