#include "SalonPutnickaDostavna.h"

SalonPutnickaDostavna::SalonPutnickaDostavna()
	: SalonPutnicka()
{
	strcpy(tip, "PutnickaDostavna");
	brojZaposlenihDostavna = 0;
	brojProdatihDostavnih = 0;
}
// naziv
// brojZaposlenihPutnicka
// xKoo
// yKoo
// brojProdatihPutnickih
// brojZaposlenihDostavna
// brojProdatihDostavna
SalonPutnickaDostavna::SalonPutnickaDostavna(char* n, int bzp, double x, double y, int bpp, int bzd, int bpd)
	: SalonPutnicka(n, bzp, x, y, bpp)
{
	strcpy(tip, "PutnickaDostavna");
	brojZaposlenihDostavna = bzd;
	brojProdatihDostavnih = bpd;
}

SalonPutnickaDostavna::~SalonPutnickaDostavna()
{
}

double SalonPutnickaDostavna::efikasnost()
{
	double rez;
	rez = (brojProdatihDostavnih / brojZaposlenihDostavna + efikasnost()) / 2;
	return rez;
}

void SalonPutnickaDostavna::ispisi(ostream& izlaz)
{
	izlaz << "SALON ZA PUTNICKA I DOSTAVNA VOZILA: "
		<< "Naziv: " << naziv << endl
		<< "Broj Zaposlenih Za Putnicka: " << brojZaposlenihPutnicka << endl
		<< "Koordinate: " << "(" << xKoo << ", " << yKoo << ")" << endl
		<< "Broj Prodathih Putnickih Vozila: " << brojProdatihPutnickih << endl
		<< "Broj Zaposlenih Za Dostavna: " << brojZaposlenihDostavna << endl
		<< "Broj Prodatih Dostavnih Vozila: " << brojProdatihDostavnih << endl << endl << endl;
}
