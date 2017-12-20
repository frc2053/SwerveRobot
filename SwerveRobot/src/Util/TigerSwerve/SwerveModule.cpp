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
	std::cout << "goalAngle: " << angle * (180/M_PI) << std::endl;
	double currentAngle = fmod(_rotateController->GetPosition(), 1) * (2*M_PI);
	std::cout << "currentAngle: " << currentAngle * (180/M_PI) << std::endl;

	double diff = fabs(angle - currentAngle);
	std::cout << "diff: " << diff * (180/M_PI) << std::endl;

	if(diff < M_PI) {
		std::cout << "IN IF STATEMENT!" << std::endl;
        angle = currentAngle + diff;
		//angle = NormalizeAngle(angle + M_PI);
		//std::cout << "IFgoalAngle: " << angle * (180/M_PI) << std::endl;
		//speed = speed * -1;
	}
	else {
		speed = speed * -1;
		angle = currentAngle + (M_PI - diff);
	}

	std::cout << "final angle: " << angle << std::endl;

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

