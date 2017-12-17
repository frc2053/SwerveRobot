#include "SwerveModule.h"
#include <iostream>
#include "../../Robot.h"
SwerveModule::SwerveModule(std::shared_ptr<CANTalon> driveController, std::shared_ptr<CANTalon> rotateController, double locationX, double locationY) {
	_location.reset(new Vector(locationX, locationY));
	_driveController.reset(driveController.get());
	_rotateController.reset(rotateController.get());
}

SwerveModule::~SwerveModule() {

}

void SwerveModule::Set(double angle, double speed) {
	angle = NormalizeAngle(angle);
	//double currentAngle = fmod(((_rotateController->GetPosition() / .5) * (M_PI)), (2*M_PI));
	//double currentAngle = ((_rotateController->GetEncPosition() & 0xfff) / 2048) * M_PI;
	double currentAngle = _rotateController->GetPulseWidthPosition() & 0xFFF;
	double diff = fabs(angle - currentAngle);

	if(diff > M_PI / 2 && diff < 3 * M_PI / 2) {
		angle = NormalizeAngle(angle + M_PI);
		speed = speed * -1;
	}

	double toMotor = (angle / M_PI) * 2048;
	_rotateController->Set(toMotor);
	_driveController->Set(speed);
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

