#ifndef TwoSeventyUp_H
#define TwoSeventyUp_H

#include "WPILib.h"
#include "../../Robot.h"
#include <chrono>
#include <thread>

class TwoSeventyUp : public frc::Command {
public:
	TwoSeventyUp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool testsPassed;
};

#endif
