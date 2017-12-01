#include "SwerveModule.h"

SwerveModule::SwerveModule(std::shared_ptr<CANTalon> driveController, std::shared_ptr<CANTalon> rotateController, double locationX, double locationY) {
	_location.reset(new Vector(locationX, locationY));
	_driveController.reset(driveController.get());
	_rotateController.reset(rotateController.get());
}

SwerveModule::~SwerveModule() {

}

void SwerveModule::Set(double angle, double speed) {
	angle = NormalizeAngle(angle);
	double diff = abs(angle - _rotateController->GetPosition());

	if(diff > M_PI / 2 && diff < 3 * M_PI / 2) {
		angle = NormalizeAngle(angle + M_PI);
		speed = speed * -1;
	}

	_rotateController->Set(angle);
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

