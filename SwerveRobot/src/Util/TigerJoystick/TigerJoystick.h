#ifndef SRC_UTIL_TIGERJOYSTICK_TIGERJOYSTICK_H_
#define SRC_UTIL_TIGERJOYSTICK_TIGERJOYSTICK_H_

#include <WPILib.h>
#include "TigerLeftTrigger.h"
#include "TigerRightTrigger.h"

class TigerJoystick {
public:
	TigerJoystick(int port);
	virtual ~TigerJoystick();

	double GetLeftXAxis();
	double GetLeftYAxis();
	double GetRightXAxis();
	double GetRightYAxis();
	double GetLeftTriggerValue();
	double GetRightTriggerValue();
	bool GetLeftTriggerPressed();
	bool GetRightTriggerPressed();
	TigerLeftTrigger GetLeftTrigger();
	TigerRightTrigger GetRightTrigger();
	frc::Joystick joystick;
	frc::JoystickButton aButton;
	frc::JoystickButton bButton;
	frc::JoystickButton xButton;
	frc::JoystickButton yButton;
	frc::JoystickButton leftShoulderButton;
	frc::JoystickButton rightShoulderButton;
	frc::JoystickButton startButton;
	frc::JoystickButton selectButton;
	frc::JoystickButton leftStickButton;
	frc::JoystickButton rightStickButton;
private:
	double DeadBandJoystick(double axis);
	TigerLeftTrigger leftTrigger;
	TigerRightTrigger rightTrigger;
};

#endif
