#include "Protivnik.h"
#include<string.h>

Protivnik::Protivnik()
{
	B = M = 0;
	ime = nullptr;
}

Protivnik::Protivnik(char* iime, double bb, double mm)
{
	ime = new char[strlen(iime) + 1];
	strcpy(ime, iime);
	B = bb;
	M = mm;
}

Protivnik::~Protivnik()
{
	if(ime!=0)
		delete[] ime;
}
