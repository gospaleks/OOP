#include "PorodicniNovcanik.h"

double PorodicniNovcanik::UkupnaVrednostNovcanika() const
{
	double suma = 0;
	for (int i = 0; i < brTr; i++)
		suma += novcanice[i]->ukupnaVrednost();
	return suma;
}

PorodicniNovcanik::PorodicniNovcanik(int kapacitet)
{
	this->kapacitet = kapacitet;
	this->brTr = 0;
	this->novcanice = new Novcanica * [kapacitet];
}

PorodicniNovcanik::~PorodicniNovcanik()
{
	if (novcanice != nullptr)
	{
		for (int i = 0; i < brTr; i++)
			delete novcanice[i];
		delete[] novcanice;
	}
}

void PorodicniNovcanik::Dodaj(Novcanica* n)
{
	// Proveri da li novcanica vec postoji
	for (int i = 0; i < brTr; i++)
	{
		// proveri tipove preko typeid i onda proveri da li su jednake preko operatora == koji je virtuelni
		if (typeid(*novcanice[i]) == typeid(*n) && *novcanice[i] == *n) // treba operator==
		{
			novcanice[i]->povecajBrojNovcanica();
			delete n; // obrisi novcanicu jer je vec postojala
			return;
		}
	}

	// Ako ne postoji, dodaj novcanicu na kraj ako ima mesta
	if (brTr == kapacitet)
	{
		cout << "Nema mesta u novcaniku" << endl;
		return;
	}

	novcanice[brTr++] = n;	// dodavanje na kraj
}

void PorodicniNovcanik::Izdvoji(Novcanica& n, int br)
{
	for (int i = 0; i < brTr; i++)
	{
		if (typeid(*novcanice[i]) == typeid(n) && *novcanice[i] == n)
		{
			// Proveri da li ima dovoljno novcanica za izdvajanje
			if (novcanice[i]->getBrojNovcanica() < br)
			{
				cout << "Nema dovoljno novcanica za izdvajanje" << endl;
				return;
			}

			novcanice[i]->smanjiBrojNovcanica(br);

			// Ako broj novcanica postane 0 obrisati je iz kolekcije
			if (novcanice[i]->getBrojNovcanica() == 0)
			{
				delete novcanice[i];
				for (int j = i; j < brTr - 1; j++)
					novcanice[j] = novcanice[j + 1];
				brTr--;
			}

			return;
		}
	}

	cout << "Novcanica ne postoji u novcaniku" << endl;
}

void PorodicniNovcanik::Rasitni(Novcanica& veca, Novcanica& manja)
{
	// Handluj pogresne podatke

	if (typeid(veca) != typeid(manja))
	{
		cout << "Novcanice nisu iste valute" << endl;
		return;
	}

	if (veca.getVrednost() <= manja.getVrednost())
	{
		cout << "Nije moguce rasitniti." << endl;
		return;
	}

	// Proveri da li moze da se rasitni (tipa ako je 50 i 20 to se ne moz rasitni)

	if (veca.getVrednost() % manja.getVrednost() != 0)
	{
		cout << "Nije moguce rasitniti." << endl;
		return;
	}

	// Izracunaj koliko novcanica manje valute treba da se dobije novcanica vece valute
	int brNovihNovcanica = veca.getVrednost() / manja.getVrednost();

	// Smanji broj novcanica vece valute za 1 jer jednu menjas s vise manjih
	Izdvoji(veca, 1); // koristi implementiranu funkciju

	for (int i = 0; i < brTr; i++)
	{
		if (typeid(*novcanice[i]) == typeid(manja) && *novcanice[i] == manja)
		{
			// ovde je kad nadje
			novcanice[i]->povecajBrojNovcanica(brNovihNovcanica);
		}
	}
}

bool PorodicniNovcanik::MozePlatiti(int iznos) const
{
	return iznos <= UkupnaVrednostNovcanika();
}

void PorodicniNovcanik::VratiNaj(Novcanica** min, Novcanica** max) const
{
	*min = novcanice[0];
	*max = novcanice[0];

	for (int i = 1; i < brTr; i++)
	{
		if (novcanice[i]->ukupnaVrednost() < (*min)->ukupnaVrednost())
			*min = novcanice[i];
		if (novcanice[i]->ukupnaVrednost() > (*max)->ukupnaVrednost())
			*max = novcanice[i];
	}
}

std::ostream& operator<<(std::ostream& izlaz, const PorodicniNovcanik& pn)
{
	izlaz << "Porodicni novcanik(" << pn.brTr <<  " razl)\nUkupna vrednost: " << pn.UkupnaVrednostNovcanika() << " RSD" << endl;
	for (int i = 0; i < pn.brTr; i++)
	{
		izlaz << "\t";
		pn.novcanice[i]->Prikazi(izlaz);
	}

	return izlaz;
}
