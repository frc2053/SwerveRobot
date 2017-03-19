#include "DriveCommand.h"

DriveCommand::DriveCommand() {
	Requires(Robot::swerveSubsystem.get());

	xAxis = 0;
	yAxis = 0;
	rotAxis = 0;
	isAPressed = 0;
	isBPressed = 0;
	isXPressed = 0;
	isYPressed = 0;
}

void DriveCommand::Initialize() {
	xAxis = 0;
	yAxis = 0;
	rotAxis = 0;
	isAPressed = 0;
	isBPressed = 0;
	isXPressed = 0;
	isYPressed = 0;
}

void DriveCommand::Execute() {
	GetInputs();
}

bool DriveCommand::IsFinished() {
	return false;
}

void DriveCommand::End() {

}

void DriveCommand::Interrupted() {

}

void DriveCommand::GetInputs() {
	xAxis = Robot::oi->GetDriverJoystick()->GetLeftXAxis();
	yAxis = Robot::oi->GetDriverJoystick()->GetLeftYAxis();
	rotAxis = Robot::oi->GetDriverJoystick()->GetRightXAxis();

	isAPressed = Robot::oi->GetDriverJoystick()->aButton->Get();
	isBPressed = Robot::oi->GetDriverJoystick()->bButton->Get();
	isXPressed = Robot::oi->GetDriverJoystick()->xButton->Get();
	isYPressed = Robot::oi->GetDriverJoystick()->yButton->Get();
}
