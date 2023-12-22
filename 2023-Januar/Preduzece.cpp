#include "Preduzece.h"

Preduzece::Preduzece()
{
	niz = nullptr;
	top = maxEl = 0;
}

Preduzece::Preduzece(int _maxEl)
{
	maxEl = _maxEl;
	top = 0;
	niz = new Karta * [maxEl];
	for (int i = 0; i < maxEl; ++i)
		niz[i] = nullptr;
}

Preduzece::~Preduzece()
{
	if (niz != nullptr)
	{
		for (int i = 0; i < maxEl; ++i)
			if (niz[i] != nullptr)
				delete niz[i];
		delete[] niz;
	}
}

void Preduzece::dodajKartu(Karta* k)
{
	if (top < maxEl) {
		niz[top++] = k;
	}
	else {
		// ovde kaze prijaviti problem
		// moze da se baci exception sa throw "Nema mesta!";
	}
}

void Preduzece::obrisiKartu(int _id)
{
	bool kraj = false;
	for (int i = 0; i < top && !kraj; ++i) {
		if (_id == niz[i]->getId()) {
			delete niz[i];
			niz[i] = nullptr;
			for (int j = i; j < top - 1; ++j)
				niz[j] = niz[j + 1];
			--top;
			niz[top] = nullptr;
			kraj = true;
		}
	}
}

void Preduzece::produziTrajanje(int _id, int _brDanaZaProduzenje)
{
	bool kraj = false;
	for (int i = 0; i < top && !kraj; ++i) {
		if (_id == niz[i]->getId()) {
			niz[i]->produzi(_brDanaZaProduzenje);
			kraj = true;
		}
	}
}

void Preduzece::prikazi(ostream& izlaz)
{
	izlaz << "PRODATE KARTE(" << top << "):\n\n";
	for (int i = 0; i < top; ++i)
		if (niz[i] != nullptr)
			niz[i]->prikazi(izlaz);
	izlaz << "________________________________________________________________-KRAJ PREDUZECE\n\n";
}

int Preduzece::brojVazecihKarata(int _redniBroj, const char* _vrsta)
{
	int rez = 0;
	for (int i = 0; i < top; ++i) {
		// dan ili noc
		if (niz[i] != nullptr && !strcmp(niz[i]->getVrsta(), _vrsta)) {
			if (niz[i]->getRedniBrojDana() + niz[i]->getBrojDanaVazenja() >= _redniBroj)
				++rez;
		}
	}

	return rez;
}

double Preduzece::ukupnaZarada()
{
	double rez = 0;
	for (int i = 0; i < top; ++i)
	{
		if (niz[i] != nullptr)
			rez += niz[i]->getCena();
	}
	return rez;
}

void Preduzece::minMax(Karta** min, Karta** max)
{
	*min = *max = niz[0];
	for (int i = 0; i < top; ++i) {
		if (niz[i]->getBrojDanaVazenja() < (*min)->getBrojDanaVazenja())
			*min = niz[i];
		if (niz[i]->getBrojDanaVazenja() > (*max)->getBrojDanaVazenja())
			*max = niz[i];
	}
}
