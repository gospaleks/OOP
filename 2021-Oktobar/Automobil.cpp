#include "Automobil.h"
#include <iomanip>
#include <fstream>
using namespace std;

Automobil::Automobil()
	: Vozilo() {
	maxBrPutnika = 0;
}

Automobil::Automobil(const char* _naziv, const char* _reg, double _maxBr, double _potrosnja, double _maxBrPutnika)
	: Vozilo(_naziv, _reg, _maxBr, _potrosnja) {
	maxBrPutnika = _maxBrPutnika;
}

Automobil::~Automobil()
{
}

void Automobil::ispisi(ostream& izlaz)
{
	Vozilo::ispisi(izlaz);
	izlaz << left << setw(25) << "MAX BR PUTNIKA: " << maxBrPutnika << endl << endl;
}

void Automobil::citaj(istream& ulaz)
{
	char _naziv[100];
	ulaz >> _naziv;

	char _reg[100];
	ulaz >> _reg;

	zauzmiMem(_naziv, _reg);

	ulaz >> maxBrzina >> potrosnja;

	// privatni atributi za automobil
	ulaz >> maxBrPutnika;
}

bool Automobil::operator>(const Automobil& a)
{
	if (this->maxBrzina > a.maxBrzina)
		return true;
	return false;
}

bool Automobil::operator<(const Automobil& a)
{
	return !(*this > a);
}
