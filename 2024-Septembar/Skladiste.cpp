#include "Skladiste.h"
#include "Voda.h"
#include "Sok.h"

Skladiste::Skladiste(int maxBr)
{
	this->maxBr = maxBr;
	trBr = 0;
	niz = new Pice * [maxBr];
}

Skladiste::~Skladiste()
{
	if (niz) {
		for (int i = 0; i < trBr; i++)
			delete niz[i];
		delete[] niz;
	}
}

void Skladiste::Dodaj(Pice* p)
{
	for (int i = 0; i < trBr; ++i) {
		// veljanovski ne daje typeid tkd ovo je drugi nacin (kod vladana msm da nije problem typeid)
		// operator== ovo sigurno moze bolje da se resi but when it works dont touch it
		if (niz[i]->Tip() == p->Tip() && *niz[i] == *p) {
			// to znaci da ima u kolekciju
			niz[i]->promeniBrAmbalazaZa(1);
			delete p;
			return;
		}
	}

	if (trBr < maxBr)
		niz[trBr++] = p;
}

void Skladiste::Izdvoji(Pice& p, int brAmbalaza)
{
	for (int i = 0; i < trBr; ++i) {

		if (niz[i]->Tip() == p.Tip() && *niz[i] == p) {

			//brAmbalaza = min(brAmbalaza, niz[i]->getBrAmbalaza());

			if (brAmbalaza > niz[i]->getBrAmbalaza()) {
				cout << "Nema dovoljno ambalaze za izdvajanje\n";
				return;
			}

			niz[i]->promeniBrAmbalazaZa(-brAmbalaza);

			if (niz[i]->getBrAmbalaza() == 0)
				Izbaci(i);

			return;
		}
	}

	cout << "Nije pronadjen pice za izdvajanje\n";
}

void Skladiste::Presipaj(Pice& vece, Pice& manje)
{
	if (vece.getZapremina() < manje.getZapremina()) {
		cout << "Ne moze se presipati\n";
		return;
	}
	
    float vecaZapremina = vece.getZapremina();
    float manjaZapremina = manje.getZapremina();

    float zaDodati = vecaZapremina / manjaZapremina;

	if (zaDodati - (int)zaDodati != 0) {
		cout << "Ne moze se presipati\n";
		return;
	}
	
	for (int i = 0; i < trBr; ++i) {

		if (niz[i]->Tip() == vece.Tip() && *niz[i] == vece) {
			// nadjena veca ambalaza koja se menja za manje
			niz[i]->promeniBrAmbalazaZa(-1);

			if (niz[i]->getBrAmbalaza() == 0)
				Izbaci(i);

			for (int j = 0; j < zaDodati; ++j) {
				if (manje.Tip() == 'V') 
					this->Dodaj(new Voda(manjaZapremina));
				else
					this->Dodaj(new Sok(manjaZapremina, manje.getUkusSoka(), manje.getProcenat(), manje.getOdnosCene()));
			}

			return;
		}
	}

}

void Skladiste::Izbaci(int i)
{
	delete niz[i];
	for (int j = i; j < trBr - 1; ++j)
		niz[j] = niz[j + 1];
	niz[trBr - 1] = nullptr;
	trBr--;
}

bool Skladiste::DovoljnaKolicina(int nabavka)
{
	int litriUkupno = 0;
	for (int i = 0; i < trBr; ++i)
		litriUkupno += niz[i]->getBrAmbalaza() * niz[i]->getZapremina();

	return nabavka <= litriUkupno;
}

void Skladiste::VratiNaj(Pice** piceMin, Pice** piceMax)
{
	if (trBr == 0) return;

	*piceMin = niz[0];
	*piceMax = niz[0];

	for (int i = 1; i < trBr; ++i) {
		if (niz[i]->cena() < (*piceMin)->cena())
			*piceMin = niz[i];
		if (niz[i]->cena() > (*piceMax)->cena())
			*piceMax = niz[i];
	}
}

ostream& operator<<(ostream& izlaz, Skladiste& s)
{
	cout << "Skladiste:\n----------------------------------------\n";
	for (int i = 0; i < s.trBr; i++)
		izlaz << *s.niz[i] << endl;
	return izlaz;
}
