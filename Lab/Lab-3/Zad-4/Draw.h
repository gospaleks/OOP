#pragma once
#include "Command.h"
class Draw : public Command
{
public:
	Draw();
	Draw(char* vvalue);
	~Draw();
	virtual void execute();
};

