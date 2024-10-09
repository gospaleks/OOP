#include "Otpornik.h"
#include <limits>	// za infinity
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

Otpornik::Otpornik()
{
	r = minTemp = maxTemp = 0;
}

Otpornik::Otpornik(const char* _barkod, float _r, float _minTemp, float _maxTemp)
	: Proizvod(_barkod, "Otpornik") {
	r = _r;
	minTemp = _minTemp;
	maxTemp = _maxTemp;
}

bool Otpornik::jeDefektan()
{
	if (r == 0.0 || r == numeric_limits<float>::infinity())
		return true;
	return false;
}

void Otpornik::prikazi(ostream& izlaz)
{
	Proizvod::prikazi(izlaz);
	izlaz << setw(15) << left << "OTPORNOST: " << r << endl;
	izlaz << setw(15) << left << "MIN TEMP: " << minTemp << endl;
	izlaz << setw(15) << left << "MAX TEMP: " << maxTemp << endl << endl;
}

