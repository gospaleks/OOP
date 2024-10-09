#include "Draw.h"
#include <iostream>

Draw::Draw()
	:Command((char*)"Draw", (char*)"") {
}

Draw::Draw(char * vvalue)
	:Command((char*)"Draw", vvalue)
{
}

Draw::~Draw()
{
}

void Draw::execute()
{
	std::cout << getTitle() << ": " << getValue() << std::endl;
}
