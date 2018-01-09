#include <Commands/Test/NinetyTwoSeventy.h>

NinetyTwoSeventy::NinetyTwoSeventy() {
	Requires(Robot::swerveSubsystem.get());
	testsPassed = false;
}

void NinetyTwoSeventy::Initialize() {
	testsPassed = false;
}

void NinetyTwoSeventy::Execute() {
	//test rotations
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(0));
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 4; j++) {
			Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(90));
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
		for(int j = 0; j < 4; j++) {
			Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(270));
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(90));
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));

	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(0));
	}
	testsPassed = true;
}

bool NinetyTwoSeventy::IsFinished() {
	return testsPassed;
}

void NinetyTwoSeventy::End() {
}

void NinetyTwoSeventy::Interrupted() {

}
