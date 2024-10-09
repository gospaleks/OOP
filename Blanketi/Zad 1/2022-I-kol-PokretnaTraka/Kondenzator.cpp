#include "Kondenzator.h"
#include <iomanip>

Kondenzator::Kondenzator()
{
	c = 0;
}

Kondenzator::Kondenzator(const char* _barkod, float _c)
	: Proizvod(_barkod, "Kondenzator") {
	c = _c;
}

bool Kondenzator::jeDefektan()
{
	if (c == 0.0) return true;
	return false;
}

void Kondenzator::prikazi(ostream& izlaz)
{
	Proizvod::prikazi(izlaz);
	izlaz << setw(15) << left << "KAPACITIVNOST: " << c << endl << endl;
}
