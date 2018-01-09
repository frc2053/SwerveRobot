#include <Commands/Test/ZeroOneEighty.h>

ZeroOneEighty::ZeroOneEighty() {
	Requires(Robot::swerveSubsystem.get());
	testsPassed = false;
}

void ZeroOneEighty::Initialize() {
	testsPassed = false;
}

void ZeroOneEighty::Execute() {
	//test rotations
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 4; j++) {
			Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(0));
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
		for(int j = 0; j < 4; j++) {
			Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(180));
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(0));
	}
	testsPassed = true;
}

bool ZeroOneEighty::IsFinished() {
	return testsPassed;
}

void ZeroOneEighty::End() {
}

void ZeroOneEighty::Interrupted() {

}
