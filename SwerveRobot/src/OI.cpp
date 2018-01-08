#include "OI.h"

#include "Commands/Drive/ZeroYaw.h"

OI::OI() {
	driverJoystick.reset(new TigerJoystick(0));

	SmartDashboard::PutData("Zero Yaw", new ZeroYaw());

	driverJoystick->aButton->WhileHeld(new WheelModuleTest(0));
	driverJoystick->bButton->WhileHeld(new WheelModuleTest(45));
	driverJoystick->xButton->WhileHeld(new WheelModuleTest(90));
	driverJoystick->yButton->WhileHeld(new WheelModuleTest(135));
	driverJoystick->startButton->WhileHeld(new WheelModuleTest(180));
	driverJoystick->selectButton->WhileHeld(new WheelModuleTest(225));
	driverJoystick->leftShoulderButton->WhileHeld(new WheelModuleTest(270));
	driverJoystick->rightShoulderButton->WhileHeld(new WheelModuleTest(315));
	driverJoystick->leftStickButton->WhileHeld(new WheelModuleTest(360));


}

std::shared_ptr<TigerJoystick> OI::GetDriverJoystick() {
	return driverJoystick;
}

double OI::deg2rad(double deg) {
	return deg * (M_PI / 180);
}
