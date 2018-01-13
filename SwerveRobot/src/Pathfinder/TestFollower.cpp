#include <Pathfinder/TestFollower.h>

TestFollower::TestFollower() {
	WHEELBASE_WIDTH = RobotMap::WHEELBASE_WIDTH;
	WHEELBASE_LENGTH = RobotMap::WHEELBASE_LENTH;
	frontLeft = NULL;
	frontRight = NULL;
	backLeft = NULL;
	backRight = NULL;
	trajectory = NULL;
	length = 0;
}

void TestFollower::Generate() {
	Waypoint points[POINT_LENGTH];
	Waypoint p1 = {-4, -1, d2r(45)};
	Waypoint p2 = {-1, 2, d2r(0)};
	Waypoint p3 = {2, 4, d2r(0)};
	points[0] = p1;
	points[1] = p2;
	points[2] = p3;

	pathfinder_prepare(points, POINT_LENGTH, FIT_HERMITE_CUBIC, PATHFINDER_SAMPLES_HIGH, TIMESTEP, MAX_VEL, MAX_ACCEL, MAX_JERK, &candidate);
	length = candidate.length;
	trajectory = (Segment*)malloc(length * sizeof(Segment));
	pathfinder_generate(&candidate, trajectory);

	//Modify for swerve
	frontLeft = (Segment*)malloc(length * sizeof(Segment));
	frontRight = (Segment*)malloc(length * sizeof(Segment));
	backLeft = (Segment*)malloc(length * sizeof(Segment));
	backRight = (Segment*)malloc(length * sizeof(Segment));

	SWERVE_MODE mode = SWERVE_DEFAULT;

	pathfinder_modify_swerve(trajectory, length, frontLeft, frontRight, backLeft, backRight, WHEELBASE_WIDTH, WHEELBASE_LENGTH, mode);
}

void TestFollower::FollowPath() {
	EncoderFollower* flFollower = (EncoderFollower*)malloc(sizeof(EncoderFollower));
	flFollower->last_error = 0;
	flFollower->segment = 0;
	flFollower->finished = 0;

	EncoderFollower* frFollower = (EncoderFollower*)malloc(sizeof(EncoderFollower));
	frFollower->last_error = 0;
	frFollower->segment = 0;
	frFollower->finished = 0;

	EncoderFollower* blFollower = (EncoderFollower*)malloc(sizeof(EncoderFollower));
	blFollower->last_error = 0;
	blFollower->segment = 0;
	blFollower->finished = 0;

	EncoderFollower* brFollower =(EncoderFollower*)malloc(sizeof(EncoderFollower));
	brFollower->last_error = 0;
	brFollower->segment = 0;
	brFollower->finished = 0;

	EncoderConfig flconfig = {0, 2048, .0635, K_P, K_I, K_D, K_V, K_A};
	EncoderConfig frconfig = {0, 2048, .0635, K_P, K_I, K_D, K_V, K_A};
	EncoderConfig blconfig = {0, 2048, .0635, K_P, K_I, K_D, K_V, K_A};
	EncoderConfig brconfig = {0, 2048, .0635, K_P, K_I, K_D, K_V, K_A};


	double fl = pathfinder_follow_encoder(flconfig, flFollower, frontLeft, length, RobotMap::swerveSubsystemFrontLeftDriveTalon->GetSelectedSensorPosition(0));
	double fr = pathfinder_follow_encoder(frconfig, frFollower, frontRight, length, RobotMap::swerveSubsystemFrontRightDriveTalon->GetSelectedSensorPosition(0));
	double bl = pathfinder_follow_encoder(blconfig, blFollower, backLeft, length, RobotMap::swerveSubsystemBackLeftDriveTalon->GetSelectedSensorPosition(0));
	double br = pathfinder_follow_encoder(brconfig, brFollower, backRight, length, RobotMap::swerveSubsystemBackRightDriveTalon->GetSelectedSensorPosition(0));

	double desired_headingfl = r2d(flFollower->heading);
	double desired_headingfr = r2d(frFollower->heading);
	double desired_headingbl = r2d(blFollower->heading);
	double desired_headingbr = r2d(brFollower->heading);

	std::shared_ptr<std::vector<SwerveModule>> modules = RobotMap::tigerSwerve->GetModules();
	modules->at(0).Set(fl, Rotation2D::fromDegrees(desired_headingfl));
	modules->at(1).Set(fr, Rotation2D::fromDegrees(desired_headingfr));
	modules->at(2).Set(bl, Rotation2D::fromDegrees(desired_headingbl));
	modules->at(3).Set(br, Rotation2D::fromDegrees(desired_headingbr));
}

TestFollower::~TestFollower() {
	free(trajectory);
	free(frontLeft);
	free(frontRight);
	free(backLeft);
	free(backRight);
}

