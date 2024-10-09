#pragma once
#include "Command.h"
class Print : public Command
{
public:
	Print();
	Print(char* vvalue);
	~Print();
	virtual void execute();
};

