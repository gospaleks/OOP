#include "Workflow.h"
#include "Activity.h"
#include "State.h"
#include <string.h>
#include <iostream>
#include <iomanip>
using namespace std;

Workflow::Workflow()
{
	n = 0;
	niz = nullptr;
}

Workflow::Workflow(int nn)
{
	ZauzmiMem(nn);
}

Workflow::Workflow(int nn, Step** nniz)
{
	n = nn;
	niz = nniz;
}

Workflow::~Workflow()
{
	OslobodiMem();
}

Workflow::Workflow(Workflow& w)
{
	OslobodiMem();
	ZauzmiMem(w.n);
	Kopiraj(w);
}

void Workflow::OslobodiMem()
{
	if (niz != nullptr) {
		for (int i = 0; i < n; ++i)
			if (niz[i] != nullptr)
				delete niz[i];
	}
}

void Workflow::ZauzmiMem(int nn)
{
	n = nn;
	niz = new Step * [n];
	for (int i = 0; i < n; ++i)
		niz[i] = nullptr;
}

void Workflow::Kopiraj(Workflow& w)
{
	for (int i = 0; i < w.n; ++i)
	{
		if (w.niz[i] != nullptr && !strcmp(w.niz[i]->VratiTip(), "Activity"))
			niz[i] = new Activity(w.niz[i]);
		else if (w.niz[i] != nullptr && !strcmp(w.niz[i]->VratiTip(), "State"))
			niz[i] = new State(w.niz[i]);
	}
}

void Workflow::InsertAt(Step* s, int ind)
{
	if (niz[ind] != nullptr)	// napravljeno tako da brise neki ako je bio i pregazi ga
		delete niz[ind];
	niz[ind] = s;
}

void Workflow::RemoveAt(int ind)
{
	if (niz[ind] != nullptr) {
		delete niz[ind];
		niz[ind] = nullptr;
	}
}

Step** Workflow::GetSpecificSteps(char* t, int* N)
{
	Step** nizOdrTipa;

	// PREBROJAVANJE DA ZNAM KLK DA ZAUZMEM MEMORIJU
	int nn = 0;
	for (int i = 0; i < n; ++i)
		if (niz[i] != nullptr && !strcmp(t, niz[i]->VratiTip()))
			++nn;

	*N = nn;
	nizOdrTipa = new Step * [nn];
	
	nn = 0;
	for (int i = 0; i < n; ++i)
		if (niz[i] != nullptr && !strcmp(t, niz[i]->VratiTip()))
		{
			if (!strcmp(t, "Activity"))
				nizOdrTipa[nn++] = new Activity(niz[i]);
			else
				nizOdrTipa[nn++] = new State(niz[i]);
		}

	return nizOdrTipa;
}

Workflow& Workflow::operator=(Workflow& w)
{
	if (this != &w) {
		OslobodiMem();
		ZauzmiMem(w.n);
		Kopiraj(w);
	}
	return *this;
}

ostream& operator<<(ostream& izlaz, Workflow& w)
{
	izlaz << "Broj elemenata: " << w.n << endl;
	izlaz << "Sadrzaj niza:\n";
	for (int i = 0; i < w.n; ++i) {
		if (w.niz[i] == nullptr)
			izlaz << left << setw(14) << "null" << endl;
		else
			w.niz[i]->Prikazi(izlaz);
	}
	izlaz << endl;
	return izlaz;
}
