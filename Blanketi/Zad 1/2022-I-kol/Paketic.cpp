#include "Paketic.h"
#include <string.h>

Paketic::Paketic()
{
	adresa = nullptr;
	boja = nullptr;
}

Paketic::Paketic(char* _adresa, char* _boja)
{
	adresa = new char[strlen(_adresa) + 1];
	strcpy(adresa, _adresa);

	boja = new char[strlen(_boja) + 1];
	strcpy(boja, _boja);
}

Paketic::~Paketic()
{
	if (adresa != nullptr)
		delete adresa;
	if (boja != nullptr)
		delete boja;
}

void Paketic::prikaziPaketic(ostream& izlaz)
{
	izlaz << adresa << ", " << boja << ", ";
}


