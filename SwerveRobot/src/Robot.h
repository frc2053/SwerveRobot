#ifndef _ROBOT_H
#define _ROBOT_H

#include <Commands/Test/CWTest.h>
#include "RobotMap.h"
#include "OI.h"
#include "Subsystems/SwerveSubsystem.h"

class Robot : public IterativeRobot {
public:
	static std::unique_ptr<SwerveSubsystem> swerveSubsystem;
	static std::unique_ptr<OI> oi;
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
