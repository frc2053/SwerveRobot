#ifndef SRC_UTIL_TIGERTRIGGER_TIGERRIGHTTRIGGER_H_
#define SRC_UTIL_TIGERTRIGGER_TIGERRIGHTTRIGGER_H_

#include "WPILib.h"

class TigerRightTrigger : public Trigger {
public:
	TigerRightTrigger(frc::Joystick* joy, int axis);
	bool Get();
	float GetTriggerValue();
private:
	float Deadband(float axis);

	int joystickAxis;
	float joystickValue;
	Joystick* joystick;
};

#endif
