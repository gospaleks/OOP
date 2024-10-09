#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class Fabrika
{
private:
	T* niz;
	int brTr;
	int maxBr;

public:
	Fabrika(int maxBr);
	~Fabrika();

	void Dodaj(T el);
	void Izbaci(T el);

	float Ukupno();
	int UkupniBrojVrednost(T vrednost, float* ukupnaVrednost);
	int NajmanjeAmbalaza(float zapremina);

	void Sacuvaj(const char* nazivFajla);
	void Ucitaj(const char* nazivFajla);

	friend ostream& operator<<(ostream& izlaz, Fabrika& f) {
		izlaz << f.maxBr << endl;
		izlaz << f.brTr << endl;
		for (int i = 0; i < f.brTr; i++) {
			izlaz << f.niz[i] << endl; // operator<<
		}
		return izlaz;
	}

	void oslobodiMem();
	void zauzmiMem(int _maxBr);
};

template<class T>
inline Fabrika<T>::Fabrika(int maxBr)
{
	zauzmiMem(maxBr);
}

template<class T>
inline Fabrika<T>::~Fabrika()
{
	if (niz)
		delete[] niz;
}

template<class T>
inline void Fabrika<T>::Dodaj(T el)
{
	if (brTr == maxBr)
		throw "Nema mesta u fabrickom nizu";

	int i = 0;
	while (i < brTr && niz[i] < el) // operator <
		i++;

	for (int j = brTr; j > i; j--)
		niz[j] = niz[j - 1]; // operator=


	niz[i] = el;
	brTr++;
}

template<class T>
inline void Fabrika<T>::Izbaci(T el)
{
	if (brTr == 0)
		throw "Fabricki niz je prazan";

	int i = 0;
	while (i < brTr && niz[i] != el) // operator !=
		i++;

	if (i == brTr)
		throw "Element nije pronadjen";

	for (int j = i; j < brTr - 1; j++)
		niz[j] = niz[j + 1];
	
	brTr--;
}

template<class T>
inline float Fabrika<T>::Ukupno()
{
	float uk = 0;
	for (int i = 0; i < brTr; ++i)
		uk = niz[i] + uk; // operator+(float)

	return uk;
}

template<class T>
inline int Fabrika<T>::UkupniBrojVrednost(T vrednost, float * ukupnaVrednost)
{
	int br = 0;
	for (int i = 0; i < brTr; ++i) {
		if (niz[i] == vrednost) // oerator ==
			br++;
	}

	*ukupnaVrednost = vrednost * br; // operator*(int)

	return br;
}

template<class T>
inline int Fabrika<T>::NajmanjeAmbalaza(float zapremina)
{
	int br = 0;
	float trZapremina = 0;
	int i = brTr - 1;
	while (i >= 0 && trZapremina <= zapremina) {
		++br;
		trZapremina = niz[i] + trZapremina;
		--i;
	}

	return br;
}

template<class T>
inline void Fabrika<T>::Sacuvaj(const char* nazivFajla)
{
	ofstream izlaz(nazivFajla);
	if (!izlaz.good())
		throw "Neuspesno otvaranje fajla";

	izlaz << *this;
	izlaz.close();
}

template<class T>
inline void Fabrika<T>::Ucitaj(const char* nazivFajla)
{
	ifstream ulaz(nazivFajla);
	if (!ulaz.good())
		throw "Neuspesno otvaranje fajla";

	oslobodiMem();
	ulaz >> maxBr;
	zauzmiMem(maxBr);

	ulaz >> brTr;
	for (int i = 0; i < brTr; i++)
		ulaz >> niz[i]; // operator>> 

	ulaz.close();
}

template<class T>
inline void Fabrika<T>::oslobodiMem()
{
	if (niz)
		delete[] niz;
	niz = nullptr;
	brTr = 0;
	maxBr = 0;
}

template<class T>
inline void Fabrika<T>::zauzmiMem(int _maxBr)
{
	this->maxBr = _maxBr;
	this->niz = new T[maxBr];
	this->brTr = 0;
}
