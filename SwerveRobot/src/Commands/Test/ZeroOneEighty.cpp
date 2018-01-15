#include <Commands/Test/ZeroOneEighty.h>

ZeroOneEighty::ZeroOneEighty() {
	Requires(Robot::swerveSubsystem.get());
	testsPassed = false;
}

void ZeroOneEighty::Initialize() {
	testsPassed = false;
}

void ZeroOneEighty::Execute() {
	std::cout << "START!!!" << std::endl;
	//test rotations
	for(int i = 0; i < 3; i++) {
		std::cout << "index of module: " << i << std::endl;
		for(int j = 0; j < 4; j++) {
			Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(0), true);
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
		for(int j = 0; j < 4; j++) {
			Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(180), true);
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(0), true);
	}
	testsPassed = true;
}

bool ZeroOneEighty::IsFinished() {
	return testsPassed;
}

void ZeroOneEighty::End() {
	std::cout << "ended" << std::endl;
}

void ZeroOneEighty::Interrupted() {

}
