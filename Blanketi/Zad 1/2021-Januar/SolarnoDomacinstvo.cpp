#include "SolarnoDomacinstvo.h"

SolarnoDomacinstvo::SolarnoDomacinstvo()
	: Domacinstvo()
{
	dobijenaEnergija = 0;
	koefPodsticaja = 0;
	odrzavanje = 0;
}

SolarnoDomacinstvo::SolarnoDomacinstvo(int brd, double po, double potr, double de, double kp, double odr)
	: Domacinstvo(brd, po, potr)
{
	dobijenaEnergija = de;
	koefPodsticaja = kp;
	odrzavanje = odr;
}

SolarnoDomacinstvo::~SolarnoDomacinstvo()
{
}

double SolarnoDomacinstvo::cenaPotrosnje(double cena)
{
	double rez = cena * potrosnja + odrzavanje -
		dobijenaEnergija * cena * koefPodsticaja;
	return rez;
}

void SolarnoDomacinstvo::ispisi(ostream& izlaz)
{
	izlaz << "SOLARNO DOMACINSTVO: " << endl
		<< "Broj domacinstva: " << brojDom << endl
		<< "Povrsina pod objektima: " << povrsinaObjekti << endl
		<< "Potrosnja: " << potrosnja << endl
		<< "Dobijena Energija: " << dobijenaEnergija << endl
		<< "Koeficient podsticaja: " << koefPodsticaja << endl
		<< "Cena odrzavanja: " << odrzavanje << endl
		<< "--------------------------------------------------" << endl;
}
