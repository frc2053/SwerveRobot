#include "TigerSwerve.h"
#include "../../Robot.h"

TigerSwerve::TigerSwerve(std::vector<std::shared_ptr<CANTalon>>& talons) {
	xAxis = 0;
	yAxis = 0;
	rotAxis = 0;
	currentYaw = 0;
	modules.reset(new std::vector<SwerveModule>());

	frontLeftDrive = talons.at(0);
	//frontRightDrive = talons.at(1);
	//backLeftDrive = talons.at(2);
	//backRightDrive = talons.at(3);

	frontLeftRot = talons.at(1); //.at(4);
	//frontRightRot = talons.at(5);
	//backLeftRot = talons.at(6);
	//backRightRot = talons.at(7);

	centerOfRotation.reset(new Vector(0, 0));

	modules->push_back(SwerveModule(frontLeftDrive, frontLeftRot, -BASE_WIDTH / 2, BASE_LENGTH / 2));
	//modules->push_back(SwerveModule(frontRightDrive, frontRightRot, BASE_WIDTH / 2, BASE_LENGTH / 2));
	//modules->push_back(SwerveModule(backLeftDrive, backLeftRot, -BASE_WIDTH / 2, -BASE_LENGTH / 2));
	//modules->push_back(SwerveModule(backRightDrive, backRightRot, BASE_WIDTH / 2, -BASE_LENGTH / 2));
}

TigerSwerve::~TigerSwerve() {

}

void TigerSwerve::SetCenterOfRotation(double x, double y) {
	centerOfRotation->SetX(x);
	centerOfRotation->SetY(y);
}

void TigerSwerve::Drive(double xSpeed, double ySpeed, double rotSpeed, double headingOffset) {

}

void TigerSwerve::SetBrakeMode() {
	for(int i = 0; i < (signed) modules->size(); i++) {
		modules->at(i).Set(modules->at(i).GetLocation().GetAngle(), 0);
	}
}

double TigerSwerve::deg2rad(double deg) {
	return deg * M_PI / 180.0;
}

void TigerSwerve::DriveRobotOriented(double x, double y, double rotation) {
	Drive(x, y, rotation, 0);
}

void TigerSwerve::DriveFieldOriented(double x, double y, double rotation, double gyro) {
	Drive(x, y, rotation, gyro);
}

std::shared_ptr<std::vector<SwerveModule>> TigerSwerve::GetModules() {
	return modules;
}
