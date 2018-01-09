#ifndef FlipBoundsCheck_H
#define FlipBoundsCheck_H

#include "WPILib.h"
#include "../../Robot.h"
#include <chrono>
#include <thread>

class FlipBoundsCheck : public frc::Command {
public:
	FlipBoundsCheck();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool testsPassed;
};

#endif
