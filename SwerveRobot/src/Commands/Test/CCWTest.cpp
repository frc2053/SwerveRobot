#include "CCWTest.h"

CCWTest::CCWTest() {
	Requires(Robot::swerveSubsystem.get());
	testsPassed = false;
}

void CCWTest::Initialize() {
	testsPassed = false;
}

void CCWTest::Execute() {
	for(int i = 315; i <= 0; i = i - 45) {
		for(int j = 0; j < 4; j++) {
			Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(i));
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	testsPassed = true;
}

bool CCWTest::IsFinished() {
	return testsPassed;
}

void CCWTest::End() {

}

void CCWTest::Interrupted() {

}
