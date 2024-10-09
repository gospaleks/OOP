#include "Evidencija.h"

Evidencija::Evidencija()
{
	niz = nullptr;
	maxEl = 0;
	top = 0;
}

Evidencija::Evidencija(int mmaxEl)
{
	top = 0;
	maxEl = mmaxEl;
	niz = new Student * [maxEl];
	for (int i = 0; i < maxEl; i++)
		niz[i] = nullptr;
}

Evidencija::~Evidencija()
{
	for (int i = 0; i < top; i++)
		delete[] niz[i];
	delete[] niz;
}

void Evidencija::dodaj(Student* s)
{
	if(top < maxEl)
	niz[top++] = s;
}

void Evidencija::izbaci(int brInd)
{
	for (int i = 0; i < top; i++)
	{
		if (niz[i]->GetbrojInd() == brInd)
		{
			delete niz[i];
			for (int j = i; j < top-1; j++)
			{
				niz[j] = niz[j + 1];
			}
			top--;
			niz[top] = nullptr;
		}
	}
	
}

void Evidencija::prikazi(ostream& izlaz)
{
	for (int i = 0; i < top; i++)
		niz[i]->ispisi(izlaz);
}

Student* Evidencija::najvisePismeni()
{
	int maxInd = 0;
	int rez = niz[0]->ukupnobodoviPismeni();
	for (int i = 1; i < top; i++)
	{
		if (niz[i]->ukupnobodoviPismeni() > rez)
		{
			rez = niz[i]->ukupnobodoviPismeni();
			maxInd = i;
		}
	}
	return niz[maxInd];
}

Student* Evidencija::najviseCeo()
{
	int maxInd = 0;
	int rez = niz[0]->ukupanBrojBodova();
	for (int i = 1; i < top; i++)
	{
		if (niz[i]->ukupanBrojBodova() > rez)
		{
			rez = niz[i]->ukupanBrojBodova();
			maxInd = i;
		}
	}
	return niz[maxInd];
}

void Evidencija::promeni(int brIndeksa, int brBodova)
{
	for (int i = 0; i < top; i++)
	{
		if (niz[i]->GetbrojInd() == brIndeksa)
			niz[i]->izmeni(brBodova);
	}
}

void Evidencija::promeni(int brIndeksa, int brBodova, int kol)
{
	for (int i = 0; i < top; i++)
	{
		if (niz[i]->GetbrojInd() == brIndeksa)
			niz[i]->izmeni(brBodova, kol);
	}
}

int Evidencija::brPolozili()
{
	int rez = 0;
	for (int i = 0; i < top; i++)
	{
		if (niz[i]->polozio())
			rez++;
	}
	return rez;
}

double Evidencija::prosekBodova()
{
	double rez = 0;
	for (int i = 0; i < top; i++)
	{
		if (niz[i]->polozio())
		{
			rez += (double)niz[i]->ukupanBrojBodova();
		}
	}
	return (rez / double(top));
}


