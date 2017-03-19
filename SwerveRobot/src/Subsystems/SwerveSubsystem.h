#ifndef SwerveSubsystem_H
#define SwerveSubsystem_H

#include <Commands/Subsystem.h>
#include "../RobotMap.h"

class SwerveSubsystem : public Subsystem {
public:
	SwerveSubsystem();
	void InitDefaultCommand();
private:
	std::shared_ptr<CANTalon> frontRightDriveTalon;
	std::shared_ptr<CANTalon> frontLeftDriveTalon;
	std::shared_ptr<CANTalon> backRightDriveTalon;
	std::shared_ptr<CANTalon> backLeftDriveTalon;

	std::shared_ptr<CANTalon> frontRightRotationTalon;
	std::shared_ptr<CANTalon> frontLeftRotationTalon;
	std::shared_ptr<CANTalon> backRightRotationTalon;
	std::shared_ptr<CANTalon> backLeftRotationTalon;
};

#endif
