#ifndef SRC_PATHFINDER_TESTFOLLOWER_H_
#define SRC_PATHFINDER_TESTFOLLOWER_H_

#include "../RobotMap.h"

class TestFollower {
public:
	TestFollower();
	virtual ~TestFollower();
	void Generate();
	void FollowPath();
private:
	int POINT_LENGTH = 3;
	const double TIMESTEP = 0.01;
	const double MAX_VEL = 15;
	const double MAX_ACCEL = 10;
	const double MAX_JERK = 60;
	const int TICKS_PER_REV = 2048;
	const double WHEEL_CIRCUMFERENCE = 0.0635;
	const double K_P = 1.0;
	const double K_I = 0.0;
	const double K_D = 0.0;
	const double K_V = 1 / MAX_VEL;
	const double K_A = 0.0;
	double WHEELBASE_WIDTH;
	double WHEELBASE_LENGTH;
	TrajectoryCandidate candidate;
	Segment* trajectory;
	Segment* frontLeft;
	Segment* frontRight;
	Segment* backLeft;
	Segment* backRight;
	int length;
};

#endif
