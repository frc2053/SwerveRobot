#include "TigerJoystick.h"

TigerJoystick::TigerJoystick(int port) {
	joystick = frc::Joystick(port);
	aButton = frc::JoystickButton(joystick, 1);
	bButton = frc::JoystickButton(joystick, 2);
	xButton = frc::JoystickButton(joystick, 3);
	yButton = frc::JoystickButton(joystick, 4);
	leftShoulderButton = frc::JoystickButton(joystick, 5);
	rightShoulderButton = frc::JoystickButton(joystick, 6);
	selectButton = frc::JoystickButton(joystick, 7);
	startButton = frc::JoystickButton(joystick, 8);
	leftStickButton = frc::JoystickButton(joystick, 9);
	rightStickButton = frc::JoystickButton(joystick, 10);
	leftTrigger = TigerLeftTrigger(joystick, 3);
	rightTrigger = TigerRightTrigger(joystick, 3);
}

TigerJoystick::~TigerJoystick() {
}

double TigerJoystick::GetLeftXAxis() {
	return DeadBandJoystick(joystick.GetRawAxis(0));
}

double TigerJoystick::GetLeftYAxis() {
	return DeadBandJoystick(joystick.GetRawAxis(1));
}

double TigerJoystick::GetRightXAxis() {
	return DeadBandJoystick(joystick.GetRawAxis(4));
}

double TigerJoystick::GetRightYAxis() {
	return DeadBandJoystick(joystick.GetRawAxis(5));
}

double TigerJoystick::GetLeftTriggerValue() {
	return leftTrigger.GetTriggerValue();
}

double TigerJoystick::GetRightTriggerValue() {
	return rightTrigger.GetTriggerValue();
}

bool TigerJoystick::GetLeftTriggerPressed() {
	return leftTrigger.Get();
}

bool TigerJoystick::GetRightTriggerPressed() {
	return rightTrigger.Get();
}

TigerLeftTrigger TigerJoystick::GetLeftTrigger() {
	return leftTrigger;
}

TigerRightTrigger TigerJoystick::GetRightTrigger() {
	return rightTrigger;
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
