#ifndef _ROBOT_H
#define _ROBOT_H

#include "RobotMap.h"
#include "OI.h"
#include "Subsystems/SwerveSubsystem.h"

class Robot : public IterativeRobot {
public:
	static std::unique_ptr<OI> oi;
	static std::shared_ptr<SwerveSubsystem> swerveSubsystem;
	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};
#endif