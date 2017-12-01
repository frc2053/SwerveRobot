#include "WheelModuleTest.h"

WheelModuleTest::WheelModuleTest() {
	Requires(Robot::swerveSubsystem.get());
	testsPassed = false;
}

void WheelModuleTest::Initialize() {
	testsPassed = false;
}

void WheelModuleTest::Execute() {
	//test rotations
	for(int i = 0; i < 360; i = i + 45) {
		for(int j = 0; j < 4; j++) {
			Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(i, 0);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	//test drive motors
	for(int i = 0; i < 4; i++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(i).Set(0, 1);
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	for(int i = 0; i < 4; i++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(i).Set(0, 0);
	}
	testsPassed = true;
}

bool WheelModuleTest::IsFinished() {
	return testsPassed;
}

void WheelModuleTest::End() {

}

void WheelModuleTest::Interrupted() {

}
