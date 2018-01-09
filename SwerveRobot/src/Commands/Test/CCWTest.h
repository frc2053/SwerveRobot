#ifndef CCWTest_H
#define CCWTest_H

#include "../../Robot.h"
#include <chrono>
#include <thread>

class CCWTest : public frc::Command {
public:
	CCWTest();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool testsPassed;
};

#endif
