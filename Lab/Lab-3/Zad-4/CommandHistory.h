#pragma once
#include "Command.h"
class CommandHistory
{
private:
	Command** vektor;
	int trBr;
public:
	CommandHistory();
	~CommandHistory();

	void undo();
	void create(int x, char* vvalue);
	void execute();
	void showHistory();
};
