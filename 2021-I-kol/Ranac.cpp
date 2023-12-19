#include "Ranac.h"

Ranac::Ranac()
{
	N = trBr = 0;
	niz = nullptr;
}

Ranac::Ranac(int Nmax)
{
	N = Nmax;
	niz = new Predmet * [N];
	for (int i = 0; i < N; ++i)
		niz[i] = nullptr;
	trBr = 0;
}

Ranac::~Ranac()
{
	if (niz != nullptr) {
		for (int i = 0; i < N; ++i)
			if (niz[i] != nullptr)
				delete niz[i];
		delete[] niz;
	}
}

void Ranac::dodajPredmet(Predmet* p)
{
	if (trBr + 1 < N)
		niz[trBr++] = p;
}

void Ranac::prikazi(ostream& izlaz)
{
	izlaz << "SADRZAJ RANCA(trBr " << trBr << "):\n";
	for (int i = 0; i < trBr; ++i)
		niz[i]->prikazi(izlaz);
}

double Ranac::srednjaVrednost()
{
	double srVr = 0;
	for (int i = 0; i < trBr; ++i)
		srVr += niz[i]->vratiVrednost();

	return (srVr / trBr);
}

Predmet* Ranac::najvrednijiPoJediniciMase()
{
	if (trBr == 0) return nullptr;

	double maxVr = niz[0]->vratiVrednost() / niz[0]->vratiMasu();
	int maxInd = 0;
	for (int i = 1; i < trBr; ++i) {
		double newVr = niz[i]->vratiVrednost() / niz[i]->vratiMasu();
		if (newVr > maxVr) {
			maxVr = newVr;
			maxInd = i;
		}
	}

	return niz[maxInd];
}
