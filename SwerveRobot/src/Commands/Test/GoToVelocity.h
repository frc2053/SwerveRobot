#ifndef GoToVelocity_H
#define GoToVelocity_H

#include "../../Robot.h"
#include "Commands/Command.h"

class GoToVelocity : public frc::Command {
public:
	GoToVelocity(int velocity);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	int velSetpoint;
	bool isDone;
};

#endif
