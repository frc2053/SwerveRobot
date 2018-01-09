#ifndef NinetyTwoSeventy_H
#define NinetyTwoSeventy_H

#include "WPILib.h"
#include "../../Robot.h"
#include <chrono>
#include <thread>

class NinetyTwoSeventy : public frc::Command {
public:
	NinetyTwoSeventy();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool testsPassed;
};

#endif
