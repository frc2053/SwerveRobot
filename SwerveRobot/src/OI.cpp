#include "OI.h"

#include "Commands/Drive/ZeroYaw.h"
#include "Commands/Test/CCWTest.h"
#include "Commands/Test/CWTest.h"
#include "Commands/Test/FlipBoundsCheck.h"
#include "Commands/Test/NinetyTwoSeventy.h"
#include "Commands/Test/TwoSeventyDown.h"
#include "Commands/Test/TwoSeventyUp.h"
#include "Commands/Test/ZeroOneEighty.h"


OI::OI() {
	driverJoystick.reset(new TigerJoystick(0));

	SmartDashboard::PutData("Zero Yaw", new ZeroYaw());
	SmartDashboard::PutData("CCWTest", new CCWTest());
	SmartDashboard::PutData("CWTest", new CWTest());
	SmartDashboard::PutData("FlipBoundsTest", new FlipBoundsCheck());
	SmartDashboard::PutData("NinetyTwoSeventy", new NinetyTwoSeventy());
	SmartDashboard::PutData("TwoSeventyDown", new TwoSeventyDown());
	SmartDashboard::PutData("TwoSeventyUp", new TwoSeventyUp());
	SmartDashboard::PutData("ZeroOneEighty", new ZeroOneEighty());

}

std::shared_ptr<TigerJoystick> OI::GetDriverJoystick() {
	return driverJoystick;
}

double OI::deg2rad(double deg) {
	return deg * (M_PI / 180);
}
