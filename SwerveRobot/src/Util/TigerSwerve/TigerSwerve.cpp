#include "TigerSwerve.h"

TigerSwerve::TigerSwerve(std::vector<std::shared_ptr<CANTalon>>& talons) {
	toNormalize = std::vector<double>();
	xAxis = 0;
	yAxis = 0;
	rotAxis = 0;
	currentYaw = 0;

	frontLeftDrive = talons.at(0);
	frontRightDrive = talons.at(1);
	backLeftDrive = talons.at(2);
	backRightDrive = talons.at(3);

	frontLeftRot = talons.at(4);
	frontRightRot = talons.at(5);
	backLeftRot = talons.at(6);
	backRightRot = talons.at(7);
}

TigerSwerve::~TigerSwerve() {
}

void TigerSwerve::CalculateSpeedAndAngleOfWheels(double _xAxis, double _yAxis, double _rotAxis, double _gyroAngle) {
	xAxis = _xAxis;
	yAxis = _yAxis;
	rotAxis = _rotAxis;
	currentYaw = _gyroAngle;

	speedAndAngle backLeft = TigerSwerve::CalculateMotorSpeed(false, false); //throws into struct because im lazy and dont
	speedAndAngle backRight = TigerSwerve::CalculateMotorSpeed(true, false); //want to seperate out functions
	speedAndAngle frontLeft = TigerSwerve::CalculateMotorSpeed(false, true); //i like it better anyway because each
	speedAndAngle frontRight = TigerSwerve::CalculateMotorSpeed(true, true); //swerve module is grouped anyway

	toNormalize.push_back(backLeft.speed);  //Can't figure out a way to easily get max and min of
	toNormalize.push_back(backRight.speed); //all speeds but this works i guess.
	toNormalize.push_back(frontLeft.speed);
	toNormalize.push_back(frontRight.speed);
	double maxSpeed = *std::max_element(toNormalize.begin(), toNormalize.end());

	backLeft.speed = Normalize(backLeft.speed, maxSpeed);   //Normalize because math might create values greater than 1
	backRight.speed = Normalize(backRight.speed, maxSpeed); //and you cant send a greater than 1 value to motor
	frontLeft.speed = Normalize(frontLeft.speed, maxSpeed); //scales between -1 and 1
	frontRight.speed = Normalize(frontRight.speed, maxSpeed);
	toNormalize.clear(); //clears because we run in big loop and need to make sure this is empty every time

	TigerSwerve::CalculateAngleAdjustments(backLeft);
	TigerSwerve::CalculateAngleAdjustments(backRight);
	TigerSwerve::CalculateAngleAdjustments(frontLeft);
	TigerSwerve::CalculateAngleAdjustments(frontRight);

	TigerSwerve::RunDriveMotors(backLeft.speed, backRight.speed, frontLeft.speed, frontRight.speed);
	TigerSwerve::RunRotationMotors(backLeft.angle, backRight.angle, frontLeft.angle, frontRight.angle);
}

TigerSwerve::speedAndAngle TigerSwerve::CalculateMotorSpeed(bool isRight, bool isFront) {
	double desiredDir = 0;
	double rotationVectorMag = rotAxis;        //Assigns val of rot joystick to rotation vector

	if(xAxis != 0 && yAxis != 0) {             //Gets angle of movement joystick
		double rad = atan2(xAxis, yAxis);      //is this what we want?
		double degrees = rad * (180 / M_PI);
		desiredDir = degrees;
	}

	double movementVectorXMag = xAxis * cos(desiredDir - currentYaw);
	double movementVectorYMag = yAxis * sin(desiredDir - currentYaw);

	double angleCenterToWheel = 0;
	if(!isRight && !isFront) {
		angleCenterToWheel = atan2(-LENGTH_TO_CENTER, -WIDTH_TO_CENTER);
	}
	if(!isRight && isFront) {
		angleCenterToWheel = atan2(LENGTH_TO_CENTER, -WIDTH_TO_CENTER);
	}
	if(isRight && !isFront) {
		angleCenterToWheel = atan2(-LENGTH_TO_CENTER, WIDTH_TO_CENTER);
	}
	if(isRight && isFront) {
		angleCenterToWheel = atan2(LENGTH_TO_CENTER, WIDTH_TO_CENTER);
	}

	double tangentVelocityXMag = rotationVectorMag * cos(angleCenterToWheel);
	double tangentVelocityYMag = -rotationVectorMag * sin(angleCenterToWheel);

	double velocityX = movementVectorXMag + tangentVelocityXMag;
	double velocityY = movementVectorYMag + tangentVelocityYMag;
	double finalMotorSpeed = sqrt(velocityX * velocityX + velocityY * velocityY);
	double finalAngle = atan(velocityY / velocityX);

	speedAndAngle retVal;
	retVal.angle = finalAngle;
	retVal.speed = finalMotorSpeed;
	return retVal;
}

double TigerSwerve::Normalize(double input, double max) {
	double normalized = 0;
	if(max > 1) {
		normalized = input / max;
	}
	else {
		normalized = input;
	}
	return normalized;
}

void TigerSwerve::RunDriveMotors(double bL, double bR, double fL, double fR) {
	frontLeftDrive->Set(fL);
	frontRightDrive->Set(fR);
	backLeftDrive->Set(bL);
	backRightDrive->Set(bR);
}

void TigerSwerve::RunRotationMotors(double bL, double bR, double fL, double fR) {
	frontLeftRot->Set(fL);
	frontRightRot->Set(fR);
	backLeftRot->Set(bL);
	backRightRot->Set(bR);
}

void TigerSwerve::CalculateAngleAdjustments(TigerSwerve::speedAndAngle &currentAngleAndSpeed) {
	double angleToTarget = fabs(frontLeftRot->GetPosition() - currentAngleAndSpeed.angle);
	double angleToOpposite = fabs(frontLeftRot->GetPosition() - (currentAngleAndSpeed.angle + 180));
	if(angleToOpposite > angleToTarget) {
		currentAngleAndSpeed.speed = currentAngleAndSpeed.speed * -1;
		currentAngleAndSpeed.angle = currentAngleAndSpeed.angle + 180;
	}
}
