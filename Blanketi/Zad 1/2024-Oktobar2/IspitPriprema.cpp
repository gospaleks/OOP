#include "IspitPriprema.h"

IspitPriprema::IspitPriprema()
{
	nmax = 0;
	brtr = 0;
	niz = nullptr;
}

IspitPriprema::IspitPriprema(int nmax)
{
	this->nmax = nmax;
	niz = new IspitniMaterijal * [nmax];
	for (int i = 0; i < nmax; i++)
		niz[i] = nullptr;
	this->brtr = 0;
}

IspitPriprema::~IspitPriprema()
{
	for (int i = 0; i < nmax; i++)
		if (niz[i] != nullptr)
			delete niz[i];
	if (niz != nullptr)
		delete[] niz;
}

void IspitPriprema::Dodaj(IspitniMaterijal* im)
{
	if (brtr < nmax)
		niz[brtr++] = im;
}

void IspitPriprema::Obrisi(int oznaka)
{
	int indeks = -1;
	for (int i = 0; i < brtr; i++)
		if (niz[i]->vratiOznaku() == oznaka)
			if (niz[i]->jeSavladan()) {
				delete niz[i];
				indeks = i;
			}
	if (indeks != -1) {
		niz[indeks] = nullptr;
		for (int i = indeks; i < brtr - 1; i++)
			niz[i] = niz[i + 1];
		niz[--brtr] = nullptr;
	}
}

void IspitPriprema::Savladaj(int oznaka)
{
	for (int i = 0; i < brtr; i++)
		if (niz[i]->vratiOznaku() == oznaka)
			niz[i]->savladaj();
}

int IspitPriprema::UkupnoSavladanih()
{
	int brojSavladanih = 0;
	for (int i = 0; i < brtr; i++)
		if (niz[i]->jeSavladan())
			brojSavladanih++;
	return brojSavladanih;
}

float IspitPriprema::UkupnoVreme(int vreme)
{
	float vremeUkupno = 0;
	for (int i = 0; i < brtr; i++)
		vremeUkupno += niz[i]->vratiVreme(vreme);
	return vremeUkupno;
}

void IspitPriprema::VratiNaj(int vreme, IspitniMaterijal** min, IspitniMaterijal** max)
{
	int indMax = 0, indMin = 0;
	for(int i = 1; i<brtr; i++)
	{
		if (niz[i]->vratiVreme(vreme) > niz[indMax]->vratiVreme(vreme))
			indMax = i;
		if (niz[i]->vratiVreme(vreme) < niz[indMin]->vratiVreme(vreme))
			indMin = i;
	}

	*min = niz[indMin];
	*max = niz[indMax];
}

ostream& operator<<(ostream& izlaz, IspitPriprema& ip)
{
	for (int i = 0; i < ip.brtr; i++)
		izlaz << i << " " << * ip.niz[i];
	izlaz << endl;
	return izlaz;
}
