#include "Print.h"
#include <iostream>

Print::Print()
	:Command((char*)"Save", (char*)"") {
}

Print::Print(char* vvalue)
	:Command((char*)"Save", vvalue) {
}

Print::~Print()
{
}

void Print::execute()
{
	std::cout << getTitle() << ": " << getValue() << std::endl;
}

