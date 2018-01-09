#include <Commands/Test/FlipBoundsCheck.h>

FlipBoundsCheck::FlipBoundsCheck() {
	Requires(Robot::swerveSubsystem.get());
	testsPassed = false;
}

void FlipBoundsCheck::Initialize() {
	testsPassed = false;
}

void FlipBoundsCheck::Execute() {
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(0));
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(45));
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(315));
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(45));
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(315));
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(45));
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(135));
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(45));
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(135));
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(45));
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(135));
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(225));
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(135));
	}	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(225));
	}	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(135));
	}	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(225));
	}
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(315));
	}
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(225));
	}
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(315));
	}
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(225));
	}
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(315));
	}
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(0));
	}
	testsPassed = true;
}

bool FlipBoundsCheck::IsFinished() {
	return testsPassed;
}

void FlipBoundsCheck::End() {
}

void FlipBoundsCheck::Interrupted() {

}
