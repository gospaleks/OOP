#include "KosarkaskiKlub.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void KosarkaskiKlub::zauzmimem(const char _boja, char* _lista[100], int _brojsponzora, int _brojulaznica, int _cenaulaznica, int _budzet)
{
	boja = _boja;
	brojsponzora = _brojsponzora;
	brojulaznica = _brojulaznica;
	cenaulaznice = _cenaulaznica;
	budzet = _budzet;
	lista = new char* [brojsponzora];

	for (int i = 0; i < brojsponzora; ++i)
		lista[i] = new char[100];

	for (int i = 0; i < brojsponzora; ++i)
		strcpy(lista[i], _lista[i]);

	aktivnost = budzet + brojulaznica * cenaulaznice;
}

void KosarkaskiKlub::oslobodimem()
{
	if (lista != nullptr) {
		for (int i = 0; i < brojsponzora; ++i)
			delete[] lista[i];
		delete[] lista;
	}
}

KosarkaskiKlub::KosarkaskiKlub()
{
	lista = nullptr;
	boja = 'c';
	brojsponzora = 0;
	brojulaznica = 0;
	cenaulaznice = 0;
	budzet = 0;
	aktivnost = 0;
}

KosarkaskiKlub::KosarkaskiKlub(const char _boja, char* _lista[], int _brojsponzora, int _brojulaznica, int _cenaulaznica, int _budzet)
{
	zauzmimem(_boja, _lista, _brojsponzora, _brojulaznica, _cenaulaznica, _budzet);
}

KosarkaskiKlub::~KosarkaskiKlub()
{
	oslobodimem();
}

KosarkaskiKlub::KosarkaskiKlub(const KosarkaskiKlub& kk)
{
	zauzmimem(kk.boja, kk.lista, kk.brojsponzora, kk.brojulaznica, kk.cenaulaznice, kk.budzet);
}

bool KosarkaskiKlub::operator>(KosarkaskiKlub& kk)
{
	return (this->aktivnost > kk.aktivnost);
}

KosarkaskiKlub& KosarkaskiKlub::operator=(KosarkaskiKlub& kk)
{
	if (this != &kk) {
		oslobodimem();
		zauzmimem(kk.boja, kk.lista, kk.brojsponzora, kk.brojulaznica, kk.cenaulaznice, kk.budzet);
	}
	return *this;
}

float KosarkaskiKlub::operator+(float x)
{
	return (this->aktivnost + x);
}

istream& operator>>(istream& ulaz, KosarkaskiKlub& kk)
{
	char b;
	char **l;
	int bs, bu, cu, bbb, a;

	ulaz >> b >> bs >> bu >> cu >> bbb;
	l = new char* [bs];
	for (int i = 0; i < bs; ++i)
		l[i] = new char[100];

	for (int i = 0; i < bs; ++i) {
		char sponzor[100];
		ulaz >> sponzor;
		strcpy(l[i], sponzor);
	}
	kk.zauzmimem(b, l, bs, bu, cu , bbb);

	for (int i = 0; i < bs; ++i)
		delete [] l[i];
	delete[] l;
	return ulaz;
}

ostream& operator<<(ostream& izlaz, const KosarkaskiKlub& kk)
{
	izlaz << setw(20) << left << "boja dresa:" << kk.boja << endl
		<< setw(20) << left << "broj ulaznica:" << kk.brojulaznica << endl
		<< setw(20) << left << "cena ulaznice:" << kk.cenaulaznice << endl
		<< setw(20) << left << "budzet:" << kk.budzet << endl
		<< setw(20) << left << "aktivnost:" << kk.aktivnost << endl
		<< setw(20) << left << "broj sponzora:" << kk.brojsponzora << endl
		<< "sponzori:" << endl;
	for (int i = 0; i < kk.brojsponzora; i++)
		izlaz << kk.lista[i] << endl;
	return izlaz;
}
