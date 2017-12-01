#ifndef WheelModuleTest_H
#define WheelModuleTest_H

#include "../../Robot.h"
#include <chrono>
#include <thread>

class WheelModuleTest : public Command {
public:
	WheelModuleTest();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool testsPassed;
};

#endif
