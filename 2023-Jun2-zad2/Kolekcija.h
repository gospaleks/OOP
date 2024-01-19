#pragma once
#include <fstream>
#include <iostream>
using namespace std;

template<class Tip>
class Kolekcija
{
private:
	Tip** niz;
	int top;
	void zauzmiMem(int n);
	void oslobodiProstor();
public:
	Kolekcija();
	Kolekcija(int _maxEl);
	~Kolekcija();

	Kolekcija(const Kolekcija& k);

	void unos(const char* fileName);
	void prikaz();
	float prosek();
	void sort();

	Kolekcija<Tip> operator+(Kolekcija<Tip>& d);
	Kolekcija<Tip>& operator=(const Kolekcija<Tip>& k);

};

template<class Tip>
inline void Kolekcija<Tip>::zauzmiMem(int n)
{
	top = n;
	niz = new Tip * [top];
	for (int i = 0; i < top; ++i)
		niz[i] = new Tip();
}

template<class Tip>
inline void Kolekcija<Tip>::oslobodiProstor()
{
	if (niz != nullptr)
	{
		for (int i = 0; i < top; ++i)
			delete niz[i];
		delete[] niz;
	}
}

template<class Tip>
inline Kolekcija<Tip>::Kolekcija()
{
	niz = nullptr;
	top = 0;
}

template<class Tip>
inline Kolekcija<Tip>::Kolekcija(int _maxEl)
{
	zauzmiMem(_maxEl);
}

template<class Tip>
inline Kolekcija<Tip>::~Kolekcija()
{
	oslobodiProstor();
}

template<class Tip>
inline Kolekcija<Tip>::Kolekcija(const Kolekcija& k)
{
	oslobodiProstor();
	zauzmiMem(k.top);
	for (int i = 0; i < k.top; ++i)
		*niz[i] = *k.niz[i];			// default operator= ce odradi kako treba
}

template<class Tip>
inline void Kolekcija<Tip>::unos(const char* fileName)
{
	ifstream ulaz(fileName);
	if (!ulaz.good())
		throw "Greska pri unosu.";
	else {
		ulaz >> top;
		zauzmiMem(top);
		for (int i = 0; i < top; ++i)
			ulaz >> *niz[i];

		ulaz.close();
	}
}

template<class Tip>
inline void Kolekcija<Tip>::prikaz()
{
	for (int i = 0; i < top; ++i)
		cout << *niz[i] << endl;
	cout << endl;
}

template<class Tip>
inline float Kolekcija<Tip>::prosek()
{
	float rez = 0;
	for (int i = 0; i < top; ++i)
		rez = *niz[i] + rez;			// treba operator+(float r)
	return (rez / top);
}

template<class Tip>
inline void Kolekcija<Tip>::sort()
{
	for (int i = 0; i < top - 1; ++i) {
		for (int j = i + 1; j < top; ++j) {
			if (*niz[i] > *niz[j])
				swap(niz[i], niz[j]);
		}
	}
}

template<class Tip>
inline Kolekcija<Tip> Kolekcija<Tip>::operator+(Kolekcija<Tip>& d)
{
	Kolekcija<Tip> nova(this->top + d.top);

	int i, j;
	for (i = 0; i < this->top; ++i)
		nova.niz[i] = new Tip(*this->niz[i]);
	for (j = 0; i < nova.top && j < d.top; ++j, ++i)
		nova.niz[i] = new Tip(*d.niz[j]);

	return nova;
}

template<class Tip>
inline Kolekcija<Tip>& Kolekcija<Tip>::operator=(const Kolekcija<Tip>& k)
{
	if (this != &k) {
		oslobodiProstor();
		zauzmiMem(k.top);
		for (int i = 0; i < k.top; ++i)
			*niz[i] = *k.niz[i];			// default operator= ce odradi kako treba
	}
	return *this;
}
