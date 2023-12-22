#include "Distributer.h"

Distributer::Distributer()
{
	niz = nullptr;
	top = 0;
	maxEl = 0;
}

Distributer::Distributer(int mmaxEl)
{
	maxEl = mmaxEl;
	niz = new SalonPutnicka * [maxEl];
	for (int i = 0; i < maxEl; i++)
		niz[i] = nullptr;
	top = 0;
}

Distributer::~Distributer()
{
	if (niz != nullptr)
	{
		for (int i = 0; i < top; i++)
			delete[] niz[i];
		delete[] niz;
	}
}

void Distributer::dodaj(SalonPutnicka* s)
{
	niz[top++] = s;
}

void Distributer::izbaci(int rredniBroj)
{
	for (int i = 0; i < top; i++)
	{
		if (rredniBroj == i)
		{
			for (int j = i; j < top - 1; j++)
				niz[j] = niz[j + 1];
			delete niz[top];
			top--;
		}
	}
}

void Distributer::uvecaj(int redniBroj, const char* tip, int za)
{
	if (redniBroj < top && niz[redniBroj] != nullptr)
	{
		if (!strcmp(niz[redniBroj]->getTip(), tip)) {
			niz[redniBroj]->uvecaj(za);
		}
	}
}

int Distributer::veciBrZaposlenih(int granica)
{
	int rez = 0;
	for (int i = 0; i < top; i++)
	{
		if (niz[i]->vratiBrojZaposlenih() > granica)
			rez++;
	}
	return rez;
}

SalonPutnicka* Distributer::najblizi(double x, double y)
{
	SalonPutnicka* p = niz[0];
	double rastojanje = sqrt((x - niz[0]->getX()) + (y - niz[0]->getY()));
	int minIndeks = 0;

	for (int i = 0; i < top; i++)
	{
		if (rastojanje < sqrt((x - niz[i]->getX()) + (y - niz[i]->getY())))
		{
			rastojanje = sqrt((x - niz[i]->getX()) + (y - niz[i]->getY()));
			minIndeks = i;
		}
	}
	return niz[minIndeks];
}

int Distributer::brProdatihVozila()
{
	int suma = 0;
	for (int i = 0; i < top; i++)
	{
		suma += niz[i]->vratiBrProdatih();
	}
	return suma;
}

void Distributer::prikazi(ostream& izlaz)
{
	for (int i = 0; i < top; i++)
		niz[i]->ispisi(izlaz);
}

double Distributer::prosecnaEfikasnost()
{
	double rez = 0;
	for (int i = 0; i < top; i++)
		rez += niz[i]->efikasnost();
	return (rez / (top - 1));
}
