#include "Command.h"
#include <string.h>
#include <iostream>

Command::Command()
{
	title = value = nullptr;
}

Command::Command(char* t, char* v)
{
	title = new char[strlen(t) + 1];
	strcpy(title, t);
	value = new char[strlen(v) + 1];
	strcpy(value, v);
}

Command::~Command()
{
	if (title != nullptr) delete[] title;
	if (value != nullptr) delete[] value;
}

void Command::execute()
{
	std::cout << title;
}
