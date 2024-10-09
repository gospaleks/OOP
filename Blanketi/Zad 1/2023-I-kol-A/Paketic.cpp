#include "Paketic.h"
#include "Cokolada.h"
#include "Igracka.h"

void Paketic::zauzmiMem(int n)
{
	this->maxEl = n;
	niz = new Poklon*[n];
	for (int i = 0; i < n; i++)
		niz[i] = nullptr;
}

void Paketic::oslobodiMem()
{
	for (int i = 0; i < maxEl; i++)
		if (niz[i] != nullptr)
			delete niz[i];
	delete[] niz;
}

Paketic::Paketic(int maxEl)
{
	this->top = 0;
	zauzmiMem(maxEl);
}

Paketic::Paketic(const Paketic& p)
{
	// kopiraj sve poklone ali nemoj da kopiras pokazivace
	this->top = 0;
	zauzmiMem(p.maxEl);
	for (int i = 0; i < p.top; i++) {
		if (typeid(*p.niz[i]) == typeid(Cokolada))
			Add(new Cokolada(*dynamic_cast<Cokolada*>(p.niz[i])));
		else
			Add(new Igracka(*dynamic_cast<Igracka*>(p.niz[i])));
	}
}

Paketic::~Paketic()
{
	oslobodiMem();
}

int Paketic::BrojPoklona() const
{
	return maxEl;
}

void Paketic::Add(Poklon* p)
{
	if (top < maxEl)
		niz[top++] = p;
}

Paketic Paketic::operator+(Paketic p)
{
	Paketic novi(maxEl + p.maxEl);

	// mora ovo cast-ovanje jer bi se onako samo pokazivaci prelepili
	// a to ne bi bilo dobro jer bi se onda brisali dva puta i to bi puklo

	// moze cast-ovanje kao u C-u ili fancy fancy jebeno komplikovano kao u C++ (al je preporuka po novom standardu jbg)
	for (int i = 0; i < maxEl; i++) {
		if (typeid(*niz[i]) == typeid(Cokolada))
			novi.Add(new Cokolada(*dynamic_cast<Cokolada*>(niz[i])));
			// novi.Add(new Cokolada(*((Cokolada*)niz[i])));
		else
			novi.Add(new Igracka(*dynamic_cast<Igracka*>(niz[i])));
			// novi.Add(new Igracka(*((Igracka*)niz[i])));
	}

	for (int i = 0; i < p.maxEl; i++) {
		if (typeid(*p.niz[i]) == typeid(Cokolada))
			novi.Add(new Cokolada(*dynamic_cast<Cokolada*>(p.niz[i])));
		else
			novi.Add(new Igracka(*dynamic_cast<Igracka*>(p.niz[i])));
	}

	return novi;
}

void Paketic::Save(const char* imeFajla)
{
	ofstream izlaz(imeFajla);
	if (izlaz.good())
		izlaz << *this;
	izlaz.close();
}

Poklon* Paketic::Max() const
{
	Poklon* max = niz[0];
	for (int i = 1; i < maxEl; i++)
		if (niz[i]->vratiBrojMasnica() > max->vratiBrojMasnica())
			max = niz[i];
	return max;
}

void Paketic::RemoveMinimum(Poklon** p)
{
	if (top == 0)
		return;

	int min = 0;
	for (int i = 1; i < top; i++)
		if (niz[i]->vratiBrojMasnica() < niz[min]->vratiBrojMasnica())
			min = i;

	// kontam da u ovaj ulazni parametar treba stavim taj koji se brise
	*p = niz[min];

	for (int i = min; i < top - 1; i++)
		niz[i] = niz[i + 1];

	niz[top - 1] = *p; // ovo je da bi se izbrisao pokazivac na poklon u destruktor zato ga stavljam na zadnje mesto
	top--;
}


ostream& operator<<(ostream& izlaz, const Paketic& p)
{
	for (int i = 0; i < p.maxEl; i++)
		if (p.niz[i] != nullptr)
			p.niz[i]->print(izlaz);
	return izlaz;
}
