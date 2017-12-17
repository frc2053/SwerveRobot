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

	double motorOutput = RobotMap::swerveSubsystemFrontLeftRotationTalon->GetOutputVoltage() / RobotMap::swerveSubsystemFrontLeftRotationTalon->GetBusVoltage();
	std::cout << "Talon Output: " << motorOutput << std::endl;
	std::cout << "Talon Setpoint: " << RobotMap::swerveSubsystemFrontLeftRotationTalon->GetSetpoint() << std::endl;
	std::cout << "Talon Position: " << RobotMap::swerveSubsystemFrontLeftRotationTalon->GetPosition() << std::endl;
	std::cout << "Talon Error: " << RobotMap::swerveSubsystemFrontLeftRotationTalon->GetClosedLoopError() << std::endl;

	angle = NormalizeAngle(angle);
	std::cout << "goalAngle: " << angle << std::endl;
	double currentAngle = fmod(_rotateController->GetPosition(), 1) * (2*M_PI);
	std::cout << "currentAngle: " << currentAngle << std::endl;

	double diff = fabs(angle - currentAngle);
	std::cout << "diff: " << diff << std::endl;

	/*if(diff > M_PI / 2 && diff < 3 * M_PI / 2) {
		std::cout << "IN IF STATEMENT!" << std::endl;
		angle = NormalizeAngle(angle + M_PI);
		std::cout << "IFgoalAngle: " << angle << std::endl;
		speed = speed * -1;
	}*/

	double toMotor = angle / (2*M_PI);
	std::cout << "toMotor: " << toMotor << std::endl;
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

