#pragma once
#include <fstream>
#include <iostream>
using namespace std;

template <class T>
class Spisak
{
private:
	T* niz;
	int top;
	int maxEl;
	void ZauzmiMem(int n);
	void OslobodiMem();
public:
	Spisak();
	Spisak(int _maxEl);
	~Spisak();

	void Dodaj(T& t);
	void Obrisi(int pozicija);
	int OdrediMesto(T ind);
	int RazlikaIzmedju(T t1, T t2);
	void MinMaxIndeks(T* maxInd, T* minInd);
	void OkreniRedosled();

	// treba napraviti operator << i >> 
	friend ostream& operator<<(ostream& izlaz, const Spisak<T>& s) {
		izlaz << s.top << endl;
		for (int i = 0; i < s.top; ++i)
			izlaz << s.niz[i] << endl;
		return izlaz;
	}

	friend istream& operator>>(istream& ulaz, Spisak<T>& s) {
		int n;
		ulaz >> n;
		for (int i = 0; i < n; ++i)
		{
			T* t = new T();
			ulaz >> *t;
			s.Dodaj(*t);
			delete t;
		}
		return ulaz;
	}


	void Sacuvaj(const char* imeFajla);
	void Ucitaj(const char* imeFajla);
};

template<class T>
inline void Spisak<T>::ZauzmiMem(int n)
{
	top = 0;
	maxEl = n;
	niz = new T[maxEl];
}

template<class T>
inline void Spisak<T>::OslobodiMem()
{
	if (niz != nullptr)
		delete[] niz;
}

template<class T>
inline Spisak<T>::Spisak()
{
	niz = nullptr;
	top = 0;
	maxEl = 0;
}

template<class T>
inline Spisak<T>::Spisak(int _maxEl)
{
	ZauzmiMem(_maxEl);
}

template<class T>
inline Spisak<T>::~Spisak()
{
	OslobodiMem();
}

template<class T>
inline void Spisak<T>::Dodaj(T& t)
{
	if (top == maxEl)
		throw exception("Na spisku vise nema mesta.");
	
	niz[top++] = t;
}

template<class T>
inline void Spisak<T>::Obrisi(int pozicija)
{
	if (pozicija < 0 || pozicija >= top)
		throw exception("Pozicija nije validna.");

	for (int i = pozicija; i < top-1; ++i)
		niz[i] = niz[i + 1];
	top--;
	// niz[top] = T();
}

template<class T>
inline int Spisak<T>::OdrediMesto(T ind)
{
	int i = 0;
	while (i < top && niz[i] != ind)			// potreban operator!=
		++i;

	if (i == top)
		throw exception("Podatak ne postoji na spisku.");

	return i;
}

template<class T>
inline int Spisak<T>::RazlikaIzmedju(T t1, T t2)
{
	// nadji poziciju t1
	int t1poz = 0;
	while (t1poz < top && niz[t1poz] != t1)
		t1poz++;

	if (t1poz == top)
		throw exception("Prvi podatak ne postoji na spisku.");

	int t2poz = 0;
	while (t2poz < top && niz[t2poz] != t2)
		t2poz++;

	if (t2poz == top)
		throw exception("Drugi podatak ne postoji na spisku.");

	return (t2poz - t1poz);
}

template<class T>
inline void Spisak<T>::MinMaxIndeks(T* maxInd, T* minInd)
{
	if (top == 0)
		throw exception("Spisak je prazan.");		// ovo nigde ne pise da treba al deluje logicno

	*maxInd = niz[0];
	*minInd = niz[0];
	for (int i = 0; i < top; ++i) {

		// operatori > i <
		if (niz[i] > *maxInd)
			*maxInd = niz[i];		// operator =
		if (niz[i] < *minInd)
			*minInd = niz[i];

	}
}

template<class T>
inline void Spisak<T>::OkreniRedosled()
{
	int i = 0;
	int j = top - 1;
	while (i < j) {

		swap(niz[i], niz[j]);

		++i;
		--j;
	}
}

template<class T>
inline void Spisak<T>::Sacuvaj(const char* imeFajla)
{
	ofstream izlaz(imeFajla);
	if (!izlaz.good())
		throw exception("Greska pri cuvanju spiska u datoteku.");

	izlaz << *this;
	izlaz.close();
}

template<class T>
inline void Spisak<T>::Ucitaj(const char* imeFajla)
{
	ifstream ulaz(imeFajla);
	if (!ulaz.good())
		throw exception("Greska pri ucitavanju spiska iz datoteke.");

	ulaz >> *this;
	ulaz.close();
}
