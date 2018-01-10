#include "GoToVelocity.h"

GoToVelocity::GoToVelocity(int velocity) {
	Requires(Robot::swerveSubsystem.get());
	velSetpoint = velocity;
	isDone = false;
}

void GoToVelocity::Initialize() {
	isDone = false;
}

void GoToVelocity::Execute() {
	RobotMap::swerveSubsystemBackLeftDriveTalon->Set(ControlMode::Velocity, velSetpoint);
	isDone = true;
}

bool GoToVelocity::IsFinished() {
	return isDone;
}

void GoToVelocity::End() {

}

void GoToVelocity::Interrupted() {

}
