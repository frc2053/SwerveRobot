#ifndef ZeroOneEighty_H
#define ZeroOneEighty_H

#include "WPILib.h"
#include "../../Robot.h"
#include <chrono>
#include <thread>

class ZeroOneEighty : public frc::Command {
public:
	ZeroOneEighty();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool testsPassed;
};

#endif
