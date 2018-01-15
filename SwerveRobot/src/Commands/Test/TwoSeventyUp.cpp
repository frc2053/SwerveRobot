#include <Commands/Test/TwoSeventyUp.h>

TwoSeventyUp::TwoSeventyUp() {
	Requires(Robot::swerveSubsystem.get());
	testsPassed = false;
}

void TwoSeventyUp::Initialize() {
	testsPassed = false;
}

void TwoSeventyUp::Execute() {
	//test rotations
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(0), true);
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(90), true);
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(180), true);
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(270), true);
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(0), true);
	}
	testsPassed = true;
}

bool TwoSeventyUp::IsFinished() {
	return testsPassed;
}

void TwoSeventyUp::End() {
	std::cout << "ended" << std::endl;
}

void TwoSeventyUp::Interrupted() {

}
