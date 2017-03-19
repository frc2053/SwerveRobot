#include "TigerJoystick.h"

TigerJoystick::TigerJoystick(int port) {
	joystick.reset(new frc::Joystick(port));
	aButton.reset(new frc::JoystickButton(joystick.get(), 1));
	bButton.reset(new frc::JoystickButton(joystick.get(), 2));
	xButton.reset(new frc::JoystickButton(joystick.get(), 3));
	yButton.reset(new frc::JoystickButton(joystick.get(), 4));
	leftShoulderButton.reset(new frc::JoystickButton(joystick.get(), 5));
	rightShoulderButton.reset(new frc::JoystickButton(joystick.get(), 6));
	selectButton.reset(new frc::JoystickButton(joystick.get(), 7));
	startButton.reset(new frc::JoystickButton(joystick.get(), 8));
	leftStickButton.reset(new frc::JoystickButton(joystick.get(), 9));
	rightStickButton.reset(new frc::JoystickButton(joystick.get(), 10));
	leftTrigger.reset(new TigerLeftTrigger(joystick.get(), 2));
	rightTrigger.reset(new TigerRightTrigger(joystick.get(), 3));
}

TigerJoystick::~TigerJoystick() {
}

double TigerJoystick::GetLeftXAxis() {
	return DeadBandJoystick(joystick->GetRawAxis(0));
}

double TigerJoystick::GetLeftYAxis() {
	return DeadBandJoystick(joystick->GetRawAxis(1));
}

double TigerJoystick::GetRightXAxis() {
	return DeadBandJoystick(joystick->GetRawAxis(4));
}

double TigerJoystick::GetRightYAxis() {
	return DeadBandJoystick(joystick->GetRawAxis(5));
}

double TigerJoystick::GetLeftTriggerValue() {
	return leftTrigger->GetTriggerValue();
}

double TigerJoystick::GetRightTriggerValue() {
	return rightTrigger->GetTriggerValue();
}

bool TigerJoystick::GetLeftTriggerPressed() {
	return leftTrigger->Get();
}

bool TigerJoystick::GetRightTriggerPressed() {
	return rightTrigger->Get();
}

bool TigerJoystick::GetAButton() {
	return joystick->GetRawButton(1);
}

bool TigerJoystick::GetBButton() {
	return joystick->GetRawButton(2);
}

bool TigerJoystick::GetXButton() {
	return joystick->GetRawButton(3);
}

bool TigerJoystick::GetYButton() {
	return joystick->GetRawButton(4);
}

bool TigerJoystick::GetLeftBumper() {
	return joystick->GetRawButton(5);
}

bool TigerJoystick::GetRightBumper() {
	return joystick->GetRawButton(6);
}

bool TigerJoystick::GetBackButton() {
	return joystick->GetRawButton(7);
}

bool TigerJoystick::GetStartButton() {
	return joystick->GetRawButton(8);
}

bool TigerJoystick::GetLeftStickButton() {
	return joystick->GetRawButton(9);
}

bool TigerJoystick::GetRightStickButton() {
	return joystick->GetRawButton(10);
}

TigerLeftTrigger* TigerJoystick::GetLeftTrigger() {
	return leftTrigger.get();
}

TigerRightTrigger* TigerJoystick::GetRightTrigger() {
	return rightTrigger.get();
}

double TigerJoystick::DeadBandJoystick(double axis) {
	if(axis > -0.20 && axis < 0.20) {
		axis = 0;
	}
	else {
		axis = axis * fabs(axis);
	}
	return axis;
}
