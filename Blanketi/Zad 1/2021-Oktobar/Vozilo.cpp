#include "Vozilo.h"
#include <iomanip>
#include <string.h>
#include <fstream>
using namespace std;

void Vozilo::zauzmiMem(const char* _naziv, const char* _reg)
{
	naziv = new char[strlen(_naziv) + 1];
	strcpy(naziv, _naziv);

	reg = new char[strlen(_reg) + 1];
	strcpy(reg, _reg);
}

Vozilo::Vozilo()
{
	naziv = nullptr;
	reg = nullptr;
	maxBrzina = 0;
	potrosnja = 0;
}

Vozilo::Vozilo(const char* _naziv, const char* _reg, double _maxBr, double _potrosnja)
{
	zauzmiMem(_naziv, _reg);
	maxBrzina = _maxBr;
	potrosnja = _potrosnja;
}

Vozilo::~Vozilo()
{
	if (naziv != nullptr)
		delete[] naziv;
	if (reg != nullptr)
		delete[] reg;
}

void Vozilo::ispisi(ostream& izlaz)
{
	izlaz << left << setw(25) << "NAZIV: " << naziv << endl;
	izlaz << left << setw(25) << "REGISTRACIJA: " << reg << endl;
	izlaz << left << setw(25) << "MAX BRZINA(km/h): " << maxBrzina << endl;
	izlaz << left << setw(25) << "POTROSNJA(l/km): " << potrosnja << endl;
}
