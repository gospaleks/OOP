#pragma once
#include "IspitniMaterijal.h"

class IspitPriprema
{
private:
	IspitniMaterijal** niz;
	int nmax;
	int brtr;

public:
	IspitPriprema();
	IspitPriprema(int nmax);
	~IspitPriprema();

	void Dodaj(IspitniMaterijal* im);
	void Obrisi(int oznaka);
	void Savladaj(int oznaka);
	int UkupnoSavladanih();
	float UkupnoVreme(int vreme);
	void VratiNaj(int vreme, IspitniMaterijal** min, IspitniMaterijal** max);

	friend ostream& operator<<(ostream& izlaz, IspitPriprema& ip);
};

