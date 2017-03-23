#ifndef SRC_UTIL_TIGERSWERVE_TIGERSWERVE_H_
#define SRC_UTIL_TIGERSWERVE_TIGERSWERVE_H_

class TigerSwerve {
private:
	const double LENGTH_TO_CENTER = 20;
	const double WIDTH_TO_CENTER = 20;
	std::vector<double> toNormalize;
	struct speedAndAngle {
		double speed = 0;
		double angle = 0;
	};
public:
	TigerSwerve();
	virtual ~TigerSwerve();
	void CalculateSpeedAndAngleOfWheels(double xAxis, double yAxis, double rotAxis, double gyroAngle);
	TigerSwerve::speedAndAngle TigerSwerve::CalculateMotorSpeed(bool isRight, bool isFront, double gyroAngle);
	double Normalize(double input, double max, double min);
};

#endif
