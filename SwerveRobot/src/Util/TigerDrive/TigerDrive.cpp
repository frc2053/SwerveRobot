#include "TigerDrive.h"

TigerDrive::TigerDrive(AHRS* imuP)
{
	//printf("constructing TigerDrive!\n");
	imuPointer = imuP;
	imuYaw = 0;
	angleTolerance = 2; //change if you want.
	rotateLoopCheck = 5;
	originalAngle = 0;
	speedWhileRotating = 0;
	speedScaleFactor = 1;
	imuRaw = 0;
	imuScaled = 0;
	scaledAngle = 0;
	spinDirection = 0;
	calculatedRotate = 0;
	tooFarCW = false;
	tooFarCCW = false;
	degreesToAngle = 0;
	degreesToAngleAbs = 0;
	timesThroughLoop = 0;
	isRotDone = true;
	yawOffset = 0;
	calculatedOffset = 0;
	isRotDoneOverride = false;
	rotateToAngleRate = 0.0f;
    turnController = new frc::PIDController(kP, kI, kD, kF, imuPointer, this);
    turnController->SetInputRange(-180.0f,  180.0f);
    turnController->SetOutputRange(-1.0, 1.0);
    turnController->SetAbsoluteTolerance(kToleranceDegrees);
    turnController->SetContinuous(true);
}

TigerDrive::~TigerDrive() {

}

float TigerDrive::CalculateRotValue(float angle, float speed)
{
	//printf("I am in CalculateRotValue\n");
	originalAngle = angle;
	speedScaleFactor = speed;
	//printf("originalAngle%f\n", originalAngle);
	//printf("speedScaleFactor%f\n", speedScaleFactor);
	tooFarCW = false;
	tooFarCCW = false;
	calculatedRotate = 0;
	imuYaw = GetAdjYaw();

	if((fabs(imuYaw - originalAngle) > angleTolerance) &&
	   (fabs(imuYaw + 360 - originalAngle) > angleTolerance)) {
		if (imuYaw > originalAngle)  {
			tooFarCW = true;
			spinDirection = -1;
			degreesToAngle = imuYaw - originalAngle;
	   //printf("tooFarCW is true\n");
		}
		else {
			//sets spin direction and degrees to rotate to
			tooFarCCW = true;
			spinDirection = 1;
			degreesToAngle = originalAngle - imuYaw;
			//printf("tooFarCCW is true\n");
		}
	}
	//printf("after\n");
	//printf("imuScaled: %f3.2 scaledAngle: %f3.2 tolerance: %f3.2 degreesToAngle: %f3.2 \n", imuScaled, scaledAngle, angleTolerance, degreesToAngle);
	//makes sure when rotating to 180 robot does not turn wrong way
	if(degreesToAngle > 180)
	{
		degreesToAngle = 360 - degreesToAngle;
		spinDirection = spinDirection * -1;
	}

	//printf("tooFarCW: %d\n", tooFarCW);
	//printf("tooFarCCW: %d\n", tooFarCCW);
	//only start spinning if we need to
	if(tooFarCW || tooFarCCW)
	{
		degreesToAngleAbs = fabs(degreesToAngle);
		//std::cout << "degreesToAngleAbs" << degreesToAngleAbs << std::endl;
		turnController->Enable();
		speedWhileRotating = rotateToAngleRate;
		//std::cout << "speedWhileRotating: " << speedWhileRotating << std::endl;
		//std::cout << "error: " << turnController->GetError() << std::endl;
		isRotDone = false;
		//why not an exponential function? :(
		/*if(degreesToAngleAbs <= 180)
		{
			speedWhileRotating = 1;
		}
		if(degreesToAngleAbs <= 90)
		{
			speedWhileRotating = 0.4;
		}
		if(degreesToAngleAbs <= 60)
		{
			speedWhileRotating = 0.3;
		}
		if(degreesToAngleAbs <= 30)
		{
			speedWhileRotating = 0.2;
		}*/
		calculatedRotate = /*spinDirection **/ speedWhileRotating;
		calculatedRotate = calculatedRotate * speedScaleFactor;
		timesThroughLoop = 1;
		//printf("TimesThroughLoopIf: %d\n", timesThroughLoop);
	}
	else
	{
		//printf("rotateLoopCheck = %d\n", rotateLoopCheck);
		//printf("TimesThroughLoopElse: %d\n", timesThroughLoop);
		//printf("We do not need to rotate anymore at least i think");
		if(timesThroughLoop == rotateLoopCheck || timesThroughLoop == 0)
		{
			turnController->Disable();
			//printf("times through loop == loopcheck or timesthroughloop == 0");
			isRotDone = true;
			timesThroughLoop = 0;
			calculatedRotate = 0;
		}
		timesThroughLoop = timesThroughLoop + 1;
		//printf("TimesThroughLoop%d\n", timesThroughLoop);
	}

	//printf("isRotDoneOverride: %d\n", isRotDoneOverride);
	if(isRotDoneOverride)
	{
		calculatedRotate = 0;
	}
	return calculatedRotate;
}


float TigerDrive::GetAdjYaw()
{
	imuRaw = imuPointer->GetYaw();
	calculatedOffset = imuRaw + yawOffset;
	if(calculatedOffset >= 180)
	{
		calculatedOffset = calculatedOffset - 360;
	}
	return calculatedOffset;
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
