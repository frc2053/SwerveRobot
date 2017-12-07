#include "TigerSwerve.h"

TigerSwerve::TigerSwerve(std::vector<std::shared_ptr<CANTalon>>& talons) {
	xAxis = 0;
	yAxis = 0;
	rotAxis = 0;
	currentYaw = 0;

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
	std::vector<Vector> vects(modules->size(), Vector(0,0));
	Vector transVector = Vector(xSpeed, ySpeed);

	transVector.Rotate(deg2rad(headingOffset));

	double farthestDist = 0;
	for(int i = 0; i < (signed) modules->size(); i++) {
		//Calculates modules pos relative to pivot point
		vects.at(i) = modules->at(i).GetLocation().Subtract(*centerOfRotation.get());
		//find farthest distance from pivot
		farthestDist = std::max(farthestDist, vects.at(i).GetMagnitude());
	}

	double maxPower = 1.0;
	for(int i = 0; i < (signed) modules->size(); i++) {
		//rotation motion created by driving each module perpendicular to
		//the vector from the pivot point
		vects.at(i).Rotate(-M_PI / 2);
		//scale by the relative rate and normalize to the farthest module
		vects.at(i).Multiply(rotSpeed / farthestDist);
		vects.at(i).Add(transVector);
		//calculate max power scale down if over 100%
		maxPower = std::max(maxPower, vects.at(i).GetMagnitude());
	}

	for(int i = 0; i < (signed) modules->size(); i++) {
		double power = vects.at(i).GetMagnitude() / maxPower;
		if(power > 0.05) {
			modules->at(i).Set(vects.at(i).GetAngle() - M_PI / 2, power);
		}
		else {
			modules->at(i).Stop();
		}
	}
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
