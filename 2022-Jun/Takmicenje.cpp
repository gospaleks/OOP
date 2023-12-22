#include "Takmicenje.h"

Takmicenje::Takmicenje()
{
	niz = nullptr;
	maxEl = 0;
	top = 0;
}

Takmicenje::Takmicenje(int mmaxEl)
{
	maxEl = mmaxEl;
	niz = new Ucesnik * [maxEl];
	for (int i = 0; i < maxEl; i++)
		niz[i] = nullptr;
	top = 0;
}

Takmicenje::~Takmicenje()
{
	if (niz != nullptr)
	{
		for (int i = 0; i < top; i++)
			delete[] niz[i];
		delete[] niz;
	}
}

void Takmicenje::dodaj(Ucesnik* u)
{
	if (top < maxEl)
	{
		niz[top++] = u;
	}
}

void Takmicenje::obrisi(int redniBr)
{
	for (int i = 0; i < top; i++)
	{
		if (niz[i]->GetredniBroj() == redniBr)
		{
			delete niz[i];
			for (int j = i; j < top; j++)
				niz[j] = niz[j + 1];
			delete niz[top];
			top--;
		}
	}
	
}

double Takmicenje::srednjaVrednostPoena()
{
	double rez = 0;
	double br = 0;
	for (int i = 0; i < top; i++)
	{
		if (niz[i]->prolazi()) {
			rez += (double)niz[i]->ukupnoPoena();
			br++;
		}
	}
	return (rez / br);
}

Ucesnik* Takmicenje::najveciBrPoena()
{
	
	int poeni = 0;
	int maxInd = 0;
	for (int i = 1; i < top; i++)
	{
		if (niz[i]->ukupnoPoena() > poeni)
		{
			poeni = niz[i]->ukupnoPoena();
			maxInd = i;
		}
	}
	return niz[maxInd];
}

void Takmicenje::upisi(ostream& izlaz)
{
	for (int i = 0; i < top; i++)
		niz[i]->ispisi(izlaz);
}

void Takmicenje::sortiraj()
{
	Ucesnik* u;
	for (int i = 0; i < top; i++)
	{
		for (int j = 0; j < top; j++)
		{
			if (niz[i]->brPomocnogOsoblja() < niz[j]->brPomocnogOsoblja())
			{
				u = niz[i];
				niz[i] = niz[j];
				niz[j] = u;
			}
		}
	}
}
