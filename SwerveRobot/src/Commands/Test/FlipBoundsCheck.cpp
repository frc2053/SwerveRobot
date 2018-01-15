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
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(0), true);
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(45), true);
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(315), true);
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(45), true);
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(315), true);
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(45), true);
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(135), true);
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(45), true);
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(135), true);
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(45), true);
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(135), true);
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(225), true);
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(135), true);
	}	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(225), true);
	}	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(135), true);
	}	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(225), true);
	}
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(315), true);
	}
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(225), true);
	}
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(315), true);
	}
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(225), true);
	}
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(315), true);
	}
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(0), true);
	}
	testsPassed = true;
}

bool FlipBoundsCheck::IsFinished() {
	return testsPassed;
}

void FlipBoundsCheck::End() {
	std::cout << "ended" << std::endl;
}

void FlipBoundsCheck::Interrupted() {

}
