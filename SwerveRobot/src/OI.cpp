#include "OI.h"

#include "Commands/Drive/ZeroYaw.h"

OI::OI() {
	driverJoystick.reset(new TigerJoystick(0));

	SmartDashboard::PutData("Zero Yaw", new ZeroYaw());
}

std::shared_ptr<TigerJoystick> OI::GetDriverJoystick() {
	return driverJoystick;
}

