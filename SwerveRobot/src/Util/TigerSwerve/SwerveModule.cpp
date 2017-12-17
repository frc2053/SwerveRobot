#include "SwerveModule.h"
<<<<<<< HEAD
#include <iostream>
=======
#include "../../Robot.h"
>>>>>>> 60dec8a23cc7b803e0792b5403be1dc9ce9c6b5a

SwerveModule::SwerveModule(std::shared_ptr<CANTalon> driveController, std::shared_ptr<CANTalon> rotateController, double locationX, double locationY) {
	std::cout << "MADE IT TO SWERVE MODULE" << std::endl;

	_location.reset(new Vector(locationX, locationY));
	std::cout << "FINISHED VECTOR" << std::endl;

	_driveController.reset(driveController.get());
	std::cout << "FINISHED DRIVE CONTROLLER" << std::endl;

	_rotateController.reset(rotateController.get());
	std::cout << "END OF SWERVE MODULE" << std::endl;

}

SwerveModule::~SwerveModule() {

}

void SwerveModule::Set(double angle, double speed) {
	std::cout << "MADE IT TO SWERVE MODULE SET" << std::endl;

	angle = NormalizeAngle(angle);
<<<<<<< HEAD
	//double currentAngle = fmod(((_rotateController->GetPosition() / .5) * (M_PI)), (2*M_PI));
	//double currentAngle = ((_rotateController->GetEncPosition() & 0xfff) / 2048) * M_PI;
	double currentAngle = _rotateController->GetPulseWidthPosition() & 0xFFF;
	std::cout << "currentAngle: " << currentAngle << std::endl;
	double diff = fabs(angle - currentAngle);
	std::cout << "diff: " << diff << std::endl;
=======
	std::cout << "SET ANGLE" << std::endl;

	double diff = abs(angle - _rotateController->GetPosition());
	std::cout << "SET DIFF" << std::endl;


>>>>>>> 60dec8a23cc7b803e0792b5403be1dc9ce9c6b5a
	if(diff > M_PI / 2 && diff < 3 * M_PI / 2) {
		angle = NormalizeAngle(angle + M_PI);
		speed = speed * -1;
	}
	std::cout << "FINISHED MATH" << std::endl;


	std::cout << "angle to rotate to: " << angle << std::endl;
	double toMotor = (angle / M_PI) * 2048;;
	std::cout << "setPoint of motor: " << toMotor << std::endl;
	_rotateController->Set(toMotor);
	_driveController->Set(speed);
	std::cout << "END OF SWERVE MODULE SET" << std::endl;

}

void SwerveModule::Stop() {
	_driveController->Set(0);
}

double SwerveModule::NormalizeAngle(double angle) {
	angle = fmod(angle, 2 * M_PI);
	if(angle < 0) {
		angle = angle + 2 * M_PI;
	}
	return angle;
}

Vector& SwerveModule::GetLocation() {
	return *_location.get();
}

