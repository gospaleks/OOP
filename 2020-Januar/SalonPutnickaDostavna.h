#pragma once
#include "SalonPutnicka.h"
class SalonPutnickaDostavna : public SalonPutnicka
{
	int brojZaposlenihDostavna;
	int brojProdatihDostavnih;
public:
	SalonPutnickaDostavna();
	SalonPutnickaDostavna(char* n, int bzp, double x,
		double y, int bpp, int bzd,
		int bpd);
	virtual ~SalonPutnickaDostavna();
	virtual int vratiBrojZaposlenih() { return brojZaposlenihDostavna; }
	virtual int vratiBrProdatih() { return brojProdatihDostavnih + brojProdatihPutnickih; }
	virtual void uvecaj(int broj) {
		brojProdatihDostavnih += broj;
	}
	virtual double efikasnost();
	virtual void ispisi(ostream& izlaz);

};


// naziv
// brojZaposlenihPutnicka
// xKoo
// yKoo
// brojProdatihPutnickih
// brojZaposlenihDostavna
// brojProdatihDostavna
