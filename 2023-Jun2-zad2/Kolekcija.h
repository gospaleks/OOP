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
public:
	Kolekcija();
	Kolekcija(int _maxEl);
	~Kolekcija();

	void unos(const char* fileName);
	void prikaz();
	float prosek();
	void sort();

	Kolekcija<Tip> operator+(Kolekcija<Tip>& d);
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
	if (niz != nullptr) 
	{
		for (int i = 0; i < top; ++i)
			delete niz[i];
		delete[] niz;
	}
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
		cout << *niz[i] << " ";
	cout << endl;
}

template<class Tip>
inline float Kolekcija<Tip>::prosek()
{
	float rez = 0;
	for (int i = 0; i < top; ++i)
		rez = rez + *niz[i];
	return (float)(rez / (float)top);
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
