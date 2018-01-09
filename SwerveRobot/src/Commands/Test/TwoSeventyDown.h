#ifndef TwoSeventyDown_H
#define TwoSeventyDown_H

#include "WPILib.h"
#include "../../Robot.h"
#include <chrono>
#include <thread>

class TwoSeventyDown : public frc::Command {
public:
	TwoSeventyDown();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool testsPassed;
};

#endif
