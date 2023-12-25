#include "Preduzece.h"

Preduzece::Preduzece()
{
	niz = nullptr;
	maxEl = 0;
	top = 0;
}

Preduzece::Preduzece(int mmaxEl)
{
	maxEl = mmaxEl;
	niz = new Domacinstvo * [maxEl];
	for (int i = 0; i < maxEl; i++)
		niz[i] = nullptr;
	top = 0;
}

Preduzece::~Preduzece()
{
	if (niz != nullptr)
	{
		for (int i = 0; i < top; i++)
			delete[] niz[i];
		delete[] niz;
	}
}

void Preduzece::prikazi(ostream& izlaz)
{
	for (int i = 0; i < top; i++)
		niz[i]->ispisi(izlaz);
}

void Preduzece::dodaj(Domacinstvo* d)
{
	if (top < maxEl)
		niz[top++] = d;
}

void Preduzece::izbaci(int broj)
{
	for (int i = 0; i < top; i++)
	{
		if (niz[i]->GetbrojDom() == broj)
		{
			delete[] niz[i];
			for (int j = i; j < top; j++)
				niz[j] = niz[j + 1];
			top--;
			niz[top] = nullptr;
		}
	}
}

double Preduzece::prosecnaPotrosnja()
{
	double rez = 0;
	for (int i = 0; i < top; i++)
	{
		rez += niz[i]->Getpotrosnja() / niz[i]->GetpovrsinaObjekti();
	}
	return (rez / (double)top);
}

Domacinstvo* Preduzece::najmanjaSvota(double cena)
{
	int minInd = 0;
	double rez = niz[0]->cenaPotrosnje(cena);

	for (int i = 0; i < top; i++)
	{
		if (niz[i]->cenaPotrosnje(cena) < rez)
		{
			rez = niz[i]->cenaPotrosnje(cena);
			minInd = i;
		}
	}
	return niz[minInd];

}

Domacinstvo* Preduzece::najvecaSvota(double cena)
{
	int maxInd = 0;
	double rez = niz[0]->cenaPotrosnje(cena);

	for (int i = 0; i < top; i++)
	{
		if (niz[i]->cenaPotrosnje(cena) > rez)
		{
			rez = niz[i]->cenaPotrosnje(cena);
			maxInd = i;
		}
	}
	return niz[maxInd];
}
