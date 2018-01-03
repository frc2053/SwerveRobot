#include "WheelModuleTest.h"

WheelModuleTest::WheelModuleTest(double setPoint) {
	Requires(Robot::swerveSubsystem.get());
	testsPassed = false;
	talonSetpoint = setPoint;
}

void WheelModuleTest::Initialize() {
	testsPassed = false;
}

void WheelModuleTest::Execute() {
	//test rotations
	for(int i = 0; i < 365; i = i + 45) {
		for(int j = 0; j < 4; j++) {
			Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(i));
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	std::cout << "Hi" << std::endl;
	//Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(0).Set(0, Rotation2D::fromDegrees(0));

	//test drive motors
	/*for(int i = 0; i < (signed) Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->size(); i++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(i).Set(0, .2);
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	for(int i = 0; i < (signed) Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->size(); i++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(i).Set(0, 0);
	}*/
	testsPassed = true;
}

bool WheelModuleTest::IsFinished() {
	return testsPassed;
}

void WheelModuleTest::End() {

}

void WheelModuleTest::Interrupted() {

}
