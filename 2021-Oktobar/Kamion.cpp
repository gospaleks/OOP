#include "Kamion.h"
#include <iomanip>
#include <fstream>
using namespace std;

Kamion::Kamion()
	: Vozilo() {
	nosivost = 0;
}

Kamion::Kamion(const char* _naziv, const char* _reg, double _maxBr, double _potrosnja, double _nosivost)
	: Vozilo(_naziv, _reg, _maxBr, _potrosnja) {
	nosivost = _nosivost;
}

Kamion::~Kamion()
{
}

void Kamion::ispisi(ostream& izlaz)
{
	Vozilo::ispisi(izlaz);
	izlaz << left << setw(25) << "NOSIVOST(t): " << nosivost << endl << endl;
}

void Kamion::citaj(istream& ulaz)
{
	char _naziv[100];
	ulaz >> _naziv;

	char _reg[100];
	ulaz >> _reg;

	zauzmiMem(_naziv, _reg);

	ulaz >> maxBrzina >> potrosnja;

	// privatni atributi za kamion
	ulaz >> nosivost;
}

bool Kamion::operator>(const Kamion& a)
{
	if (this->potrosnja < a.potrosnja)
		return true;
	return false;
}

bool Kamion::operator<(const Kamion& a)
{
	return !(*this > a);
}


