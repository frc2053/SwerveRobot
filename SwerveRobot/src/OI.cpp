#include "OI.h"

OI::OI() {
	driverJoystick.reset(new TigerJoystick(0));
}

std::shared_ptr<TigerJoystick> OI::GetDriverJoystick() {
	return driverJoystick;
}

