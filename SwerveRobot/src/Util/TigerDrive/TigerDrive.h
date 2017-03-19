#ifndef SRC_TIGERDRIVE_TIGERDRIVE_H_
#define SRC_TIGERDRIVE_TIGERDRIVE_H_

#include "AHRS.h"

class TigerDrive : public frc::PIDOutput
{
private:
	double kP = 0.0228f;
	double kI = 0.00f;
	double kD = 0.075f;
	double kF = 0.00f;
	AHRS* imuPointer;
	float angleTolerance; // Tolerance in degrees on either side of set angle
	int rotateLoopCheck; //checks for iterations through loop. Change later depending on robot
	float originalAngle; // angle to rotate to
	float speedWhileRotating; // Current spin speed for piece wise linear angle from set point distance
	float speedScaleFactor; //scales speed for slower rotation
	float imuRaw; //Raw imu reading
	float imuYaw; //holds adjusted imu angle depending on auto mode and starting orientation
	float imuScaled; //translated imu reading to a non-wrapping scale (-180 to 180 -> 820 to 1180)
	float scaledAngle; //converts originalAngle to linear scale
	int spinDirection;  //Sets spin direction: 1=Clockwise from robot top, -1=CCW
	float calculatedRotate; //Calculated rotation speed to mecDrive
	bool tooFarCW; // Robot is further CW than set point: needs to spin CCW
	bool tooFarCCW; //Robot is further CCW than set point: needs to spin CW
	float degreesToAngle; //Number of degrees from current angle to intended angle
	float degreesToAngleAbs; //absolute value of DegreesToAngle used for comparing angles
	int timesThroughLoop; //counter variable for overshooting
	bool isRotDone; //is the robot done rotating
	float calculatedOffset; //used for auto modes
	float yawOffset; //passed in for auto modes
	bool isRotDoneOverride; //TESTING
    double rotateToAngleRate; //Current rotation rate
    double kToleranceDegrees = 2.0f;
public:
	TigerDrive(AHRS* imuYaw);
	virtual ~TigerDrive();
	float CalculateRotValue(float angle, float speed);
	float GetAdjYaw();
	void SetAdjYaw(float offset);
	float GetImuYaw();
	bool GetIsRotDone();
	void SetIsRotDone(bool isDone);
	void SetIsRotDoneOverride(bool isDone);
	void SetTimesThroughLoop(int timeLoop);
	bool GetIsRotDoneOverride();

    frc::PIDController* turnController; //PID Controller

    void PIDWrite(double output) {
        this->rotateToAngleRate = output;
    }
};
#endif
