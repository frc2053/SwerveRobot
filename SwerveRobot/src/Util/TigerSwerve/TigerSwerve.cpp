#include "TigerSwerve.h"

TigerSwerve::TigerSwerve() {
	toNormalize = std::vector<double>();
}

TigerSwerve::~TigerSwerve() {
}

void TigerSwerve::CalculateSpeedAndAngleOfWheels(double xAxis, double yAxis, double rotAxis, double gyroAngle) {
	speedAndAngle backLeft = CalculateMotorSpeed(false, false, gyroAngle); //throws into struct because im lazy and dont
	speedAndAngle backRight = CalculateMotorSpeed(true, false, gyroAngle); //want to seperate out functions
	speedAndAngle frontLeft = CalculateMotorSpeed(false, true, gyroAngle); //i like it better anyway because each
	speedAndAngle frontRight = CalculateMotorSpeed(true, true, gyroAngle); //swerve module is grouped anyway

	toNormalize.push_back(backLeft.speed);  //Can't figure out a way to easily get max and min of
	toNormalize.push_back(backRight.speed); //all speeds but this works i guess.
	toNormalize.push_back(frontLeft.speed);
	toNormalize.push_back(frontRight.speed);
	double maxSpeed = std::max_element(toNormalize.begin(), toNormalize.end());
	double minSpeed = std::min_element(toNormalize.begin(), toNormalize.end());

	double speedBackLeft = Normalize(backLeft.speed, maxSpeed, minSpeed);   //Normalize because math might create values greater than 1
	double speedBackRight = Normalize(backRight.speed, maxSpeed, minSpeed); //and you cant send a greater than 1 value to motor
	double speedFrontLeft = Normalize(frontLeft.speed, maxSpeed, minSpeed); //scales between -1 and 1
	double speedFrontRight = Normalize(frontRight.speed, maxSpeed, minSpeed);
	toNormalize.clear(); //clears because we run in big loop and need to make sure this is empty every time

	//NOW WE NEED TO MAKE WHEELS ACTUALLY TURN TOWARDS TARGET ANGLE
	//ALSO MAKE SURE TO SET MOTOR SPEED
	//DONT FORGET WE NEVER HAVE TO GO MORE THAN 90 DEGREES BECAUSE WE CAN SWITCH DIR OF MOTOR
}

TigerSwerve::speedAndAngle TigerSwerve::CalculateMotorSpeed(bool isRight, bool isFront, double gyroAngle) {
	double movementVectorMag = 0; //Still have to calculate these
	double desiredDir = 0;        //based on joystick input
	double rotationVectorMag = 0; //not sure how to yet

	double movementVectorXMag = movementVectorMag * cos(desiredDir - gyroAngle);
	double movementVectorYMag = movementVectorMag * sin(desiredDir - gyroAngle);

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

double TigerSwerve::Normalize(double input, double max, double min) {
	double avg = (min + max) / 2;
	double range = (max - min) / 2;
	double normalized = (input - avg) / range;
	return normalized;
}

