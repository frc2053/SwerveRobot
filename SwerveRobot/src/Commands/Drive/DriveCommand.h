#ifndef DriveCommand_H
#define DriveCommand_H

#include "../../Robot.h"

class DriveCommand : public Command {
public:
	DriveCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void GetInputs();
private:
	double xAxis;
	double yAxis;
	double rotAxis;
	bool isAPressed;
	bool isBPressed;
	bool isXPressed;
	bool isYPressed;
};

#endif
