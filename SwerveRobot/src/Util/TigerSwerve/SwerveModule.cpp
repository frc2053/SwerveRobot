#include "SwerveModule.h"
#include <iostream>
#include "../../Robot.h"
SwerveModule::SwerveModule(std::shared_ptr<WPI_TalonSRX> driveController, std::shared_ptr<WPI_TalonSRX> rotateController) {
	_driveController.reset(driveController.get());
	_rotateController.reset(rotateController.get());
	_angleEncoder.reset(new CTREMagEncoder(_rotateController.get()));
	isOptimizedAngle = false;
}

SwerveModule::~SwerveModule() {

}

Rotation2D SwerveModule::GetAngle() const {
	return _angleEncoder->GetAngle();
}

void SwerveModule::SetAngle(Rotation2D angle) {
	Rotation2D currentAngle = _angleEncoder->GetAngle();
	std::cout << "currentAngle: " << currentAngle.getDegrees() << std::endl;
	Rotation2D deltaAngle = currentAngle.rotateBy(angle.inverse());
	std::cout << "deltaAngle: " << deltaAngle.getDegrees() << std::endl;
	if(deltaAngle.getRadians() >= M_PI_2 && deltaAngle.getRadians() <= 3 * M_PI_2) {
		std::cout << "between pi and 3/2pi" << std::endl;
		angle = angle.rotateBy(Rotation2D::fromRadians(M_PI));
		std::cout << "angle: " << angle.getDegrees() << std::endl;
		isOptimizedAngle = true;
	}
	else {
		std::cout << "not optimized path" << std::endl;
		std::cout << "angle: " << angle.getDegrees() << std::endl;
		isOptimizedAngle = false;
	}
	int setpoint = _angleEncoder->ConvertAngleToSetpoint(angle);
	_rotateController->Set(ControlMode::Position, setpoint);
	std::cout << "setPoint: " << setpoint << std::endl;
	std::cout << "roateController: " << _rotateController->GetClosedLoopError(0) << std::endl;
	std::cout << "END" << std::endl;

}

void SwerveModule::Stop() {
	_driveController->Set(0);
}

void SwerveModule::Set(double speed, Rotation2D angle) {
	SetAngle(angle);
	if(isOptimizedAngle) {
		_driveController->Set(speed*-1);
	}
	else {
		_driveController->Set(speed);
	}
}
