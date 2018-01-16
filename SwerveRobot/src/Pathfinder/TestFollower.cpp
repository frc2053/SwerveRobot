#include <Pathfinder/TestFollower.h>

TestFollower::TestFollower() {
	WHEELBASE_WIDTH = RobotMap::WHEELBASE_WIDTH;
	WHEELBASE_LENGTH = RobotMap::WHEELBASE_LENGTH;
	frontLeft = NULL;
	frontRight = NULL;
	backLeft = NULL;
	backRight = NULL;
	trajectory = NULL;
	length = 0;
}

void TestFollower::Generate() {
	modules = RobotMap::tigerSwerve->GetModules();
	Waypoint points[POINT_LENGTH];
	Waypoint p1 = {0, 0, d2r(0)};
	Waypoint p2 = {8, 2, d2r(0)};
	points[0] = p1;
	points[1] = p2;
	//points[2] = p3;

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

	FILE* fp = fopen("/home/lvuser/myfile.csv", "w");
	pathfinder_serialize_csv(fp, trajectory, length);
	fclose(fp);

	flFollower->last_error = 0;
	flFollower->segment = 0;
	flFollower->finished = 0;

	frFollower->last_error = 0;
	frFollower->segment = 0;
	frFollower->finished = 0;

	blFollower->last_error = 0;
	blFollower->segment = 0;
	blFollower->finished = 0;

	brFollower->last_error = 0;
	brFollower->segment = 0;
	brFollower->finished = 0;
}

void TestFollower::FollowPath() {

	double fl = pathfinder_follow_encoder(flconfig, flFollower, frontLeft, length, RobotMap::swerveSubsystemFrontLeftDriveTalon->GetSelectedSensorPosition(0));
	double fr = pathfinder_follow_encoder(frconfig, frFollower, frontRight, length, RobotMap::swerveSubsystemFrontRightDriveTalon->GetSelectedSensorPosition(0));
	double bl = pathfinder_follow_encoder(blconfig, blFollower, backLeft, length, RobotMap::swerveSubsystemBackLeftDriveTalon->GetSelectedSensorPosition(0));
	double br = pathfinder_follow_encoder(brconfig, brFollower, backRight, length, RobotMap::swerveSubsystemBackRightDriveTalon->GetSelectedSensorPosition(0));

	double desired_headingfl = r2d(flFollower->heading);
	double desired_headingfr = r2d(frFollower->heading);
	double desired_headingbl = r2d(blFollower->heading);
	double desired_headingbr = r2d(brFollower->heading);

	std::cout << "flhead: " << desired_headingfl << std::endl;
	//std::cout << "frhead: " << desired_headingfr << std::endl;
	//std::cout << "blhead: " << desired_headingbl << std::endl;
	//std::cout << "brhead: " << desired_headingbr << std::endl;
	std::cout << "fl: " << fl << std::endl;
	//std::cout << "fr: " << fr << std::endl;
	//std::cout << "bl: " << bl << std::endl;
	//std::cout << "br: " << br << std::endl;

	modules->at(0).Set(fl, Rotation2D::fromDegrees(desired_headingfl), false);
	modules->at(1).Set(fr, Rotation2D::fromDegrees(desired_headingfr), false);
	modules->at(2).Set(bl, Rotation2D::fromDegrees(desired_headingbl), false);
	modules->at(3).Set(br, Rotation2D::fromDegrees(desired_headingbr), false);
}

TestFollower::~TestFollower() {
	free(trajectory);
	free(frontLeft);
	free(frontRight);
	free(backLeft);
	free(backRight);
	free(flFollower);
	free(frFollower);
	free(blFollower);
	free(brFollower);
}

