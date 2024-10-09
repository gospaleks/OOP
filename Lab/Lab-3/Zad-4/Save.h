#pragma once
#include "Command.h"
class Save : public Command
{
public:
	Save();
	Save(char* vvalue);
	~Save();
	virtual void execute();
};

