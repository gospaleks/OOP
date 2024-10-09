#include "Paragraf.h"
#include <string.h>

Paragraf::Paragraf()
{
	p = nullptr;
}

Paragraf::Paragraf(char* pp)
{
	p = new char[strlen(pp) + 1];
	strcpy(p, pp);
}

Paragraf::~Paragraf()
{
	if (p != nullptr)
		delete[] p;
}

void Paragraf::prikazi(ostream& izlaz)
{
	izlaz << p;
}
