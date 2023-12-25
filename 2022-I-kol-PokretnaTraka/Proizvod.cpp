#include "Proizvod.h"
#include <string.h>
#include <iomanip>
using namespace std;

Proizvod::Proizvod()
{
	strcpy(barkod, "000000");
	tip = nullptr;
}

Proizvod::Proizvod(const char* _barkod, const char *_tip)
{
	strcpy(barkod, _barkod);
	tip = new char[strlen(_tip) + 1];
	strcpy(tip, _tip);
}

Proizvod::~Proizvod()
{
	if (tip != nullptr)
		delete[] tip;
}

void Proizvod::prikazi(ostream& izlaz)
{
	izlaz << tip << endl;
	izlaz << setw(15) << left << "BARKOD: " << barkod << endl;
	// izlaz << barkod << "(" << tip << "):\n";
}
