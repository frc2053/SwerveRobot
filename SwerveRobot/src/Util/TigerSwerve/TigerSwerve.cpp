#include "TigerSwerve.h"
#include "../../Robot.h"

TigerSwerve::TigerSwerve(std::vector<std::shared_ptr<CANTalon>>& talons) {
	xAxis = 0;
	yAxis = 0;
	rotAxis = 0;
	currentYaw = 0;
	modules.reset(new std::vector<SwerveModule>());

	frontLeftDrive = talons.at(0);
	frontRightDrive = talons.at(1);
	backLeftDrive = talons.at(2);
	backRightDrive = talons.at(3);

	frontLeftRot = talons.at(4);
	frontRightRot = talons.at(5);
	backLeftRot = talons.at(6);
	backRightRot = talons.at(7);

	//centerOfRotation.reset(new Vector(0, 0));

	modules->push_back(SwerveModule(frontLeftDrive, frontLeftRot));
	modules->push_back(SwerveModule(frontRightDrive, frontRightRot));
	modules->push_back(SwerveModule(backLeftDrive, backLeftRot));
	modules->push_back(SwerveModule(backRightDrive, backRightRot));
}

TigerSwerve::~TigerSwerve() {

}

void TigerSwerve::SetCenterOfRotation(double x, double y) {
	//centerOfRotation->SetX(x);
	//centerOfRotation->SetY(y);
}

void TigerSwerve::Drive(double xSpeed, double ySpeed, double rotSpeed, double headingOffset) {
	Translation2D trans(ySpeed, xSpeed);
	std::cout << "trans: (" << trans.getX() << "," << trans.getY() << ")" << std::endl;
	Rotation2D rot = Rotation2D::fromDegrees(rotSpeed);
	std::cout << "rotSpeed: " << rotSpeed << std::endl;
	std::cout << "rot: " << rot.getDegrees() << std::endl;

	Rotation2D gyroAngle = Rotation2D::fromDegrees(headingOffset);
	std::cout << "gyroAngleRot: " << gyroAngle.getDegrees() << std::endl;

	currentYaw = headingOffset;
	std::cout << "currentYaw: " << currentYaw << std::endl;
	trans.rotateBy(gyroAngle);
	std::cout << "rotated trans" << std::endl;
	std::cout << "trans: (" << trans.getX() << "," << trans.getY() << ")" << std::endl;

	double flWheelSpeed;
	double frWheelSpeed;
	double blWheelSpeed;
	double brWheelSpeed;
	Rotation2D flWheelAngle;
	Rotation2D frWheelAngle;
	Rotation2D blWheelAngle;
	Rotation2D brWheelAngle;
	SwerveInverseKinematics(trans, rotSpeed, frWheelSpeed, flWheelSpeed, brWheelSpeed, blWheelSpeed, flWheelAngle, frWheelAngle, blWheelAngle, brWheelAngle);
	modules->at(0).Set(flWheelSpeed, flWheelAngle);
	modules->at(1).Set(frWheelSpeed, frWheelAngle);
	modules->at(2).Set(blWheelSpeed, blWheelAngle);
	modules->at(3).Set(brWheelSpeed, brWheelAngle);
}

void TigerSwerve::SetBrakeMode() {
	for(int i = 0; i < (signed) modules->size(); i++) {
		//modules->at(i).Set(modules->at(i).GetLocation().GetAngle(), 0);
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

void TigerSwerve::SwerveInverseKinematics(Translation2D &translation,
		double rotation, double &wheelSpeedFR, double &wheelSpeedFL, double &wheelSpeedBR, double &wheelSpeedBL,
		Rotation2D &wheelAngleFL, Rotation2D &wheelAngleFR, Rotation2D &wheelAngleBL, Rotation2D &wheelAngleBR) {

	double A = translation.getX() - rotation * (BASE_LENGTH / 2.0);
	double B = translation.getX() + rotation * (BASE_LENGTH / 2.0);
	double C = translation.getY() - rotation * (BASE_WIDTH / 2.0);
	double D = translation.getY() + rotation * (BASE_WIDTH / 2.0);
	wheelSpeedFL = sqrt(pow(B, 2) + pow(D, 2));
	wheelSpeedFR = sqrt(pow(B, 2) + pow(C, 2));
	wheelSpeedBR = sqrt(pow(A, 2) + pow(D, 2));
	wheelSpeedBL = sqrt(pow(A, 2) + pow(C, 2));
	wheelAngleFL = Rotation2D(B,D,true);
	wheelAngleFR = Rotation2D(B,C,true);
	wheelAngleBL = Rotation2D(A,D,true);
	wheelAngleBR = Rotation2D(A,C,true);

	double maxWheelSpeed = std::max(wheelSpeedFL,std::max(wheelSpeedFR,std::max(wheelSpeedBL,wheelSpeedBR)));
	if (maxWheelSpeed > 1) {
		wheelSpeedFR /= maxWheelSpeed;
		wheelSpeedFL /= maxWheelSpeed;
		wheelSpeedBR /= maxWheelSpeed;
		wheelSpeedBL /= maxWheelSpeed;
	}
}
