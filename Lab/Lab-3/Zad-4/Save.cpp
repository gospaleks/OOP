#include "Save.h"
#include <iostream>

Save::Save()
	:Command((char*)"Save", (char*)"") {
}

Save::Save(char* vvalue)
	:Command((char*)"Save", vvalue) {
}

Save::~Save()
{
}

void Save::execute()
{
	std::cout << getTitle() << ": " << getValue() << std::endl;
}