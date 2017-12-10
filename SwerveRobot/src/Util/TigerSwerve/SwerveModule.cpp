#include "SwerveModule.h"
#include "../../Robot.h"

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
	std::cout << "SET ANGLE" << std::endl;

	double diff = abs(angle - _rotateController->GetPosition());
	std::cout << "SET DIFF" << std::endl;


	if(diff > M_PI / 2 && diff < 3 * M_PI / 2) {
		angle = NormalizeAngle(angle + M_PI);
		speed = speed * -1;
	}
	std::cout << "FINISHED MATH" << std::endl;


	_rotateController->Set(angle);
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

