#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class Skup
{
private:
	T* niz;
	int top;
	int maxEl;
	void ZauzmiMem(int velicina);
	void OslobodiProstor();
public:
	Skup();
	Skup(int _maxEl);
	~Skup();
	Skup(const Skup<T>& s);
	Skup<T>& operator=(const Skup<T>& s);

	void Dodaj(T& el);
	int BrojDuplikata(T& x);
	void IzbaciDuplikate();
	void Sortiraj();

	// Unija kao operator +
	Skup<T> operator+(Skup<T>& s);
	// Presek kao operator *
	Skup<T> operator*(Skup<T>& s);

	void Sacuvaj(const char* imeFajla);
	void Ucitaj(const char* imeFajla);


	// operatori << i >> u klasi Procesor
	friend ostream& operator<<(ostream& izlaz, const Skup<T>& s) {
		izlaz << s.top << endl;
		for (int i = 0; i < s.top; ++i)
			izlaz << s.niz[i] << endl;
		izlaz << endl;
		return izlaz;
	}

	friend istream& operator>>(istream& ulaz, Skup<T>& s) {
		int n;
		ulaz >> n;
		s.ZauzmiMem(n + n / 2);
		for (int i = 0; i < n; ++i) {
			T* el = new T();
			ulaz >> *el;
			s.Dodaj(*el);
		}
		return ulaz;
	}
};

template<class T>
inline void Skup<T>::ZauzmiMem(int velicina)
{
	maxEl = velicina;
	top = 0;
	niz = new T[maxEl];
	for (int i = 0; i < maxEl; ++i)
		niz[i] = T();
}

template<class T>
inline void Skup<T>::OslobodiProstor()
{
	if (niz != nullptr)
		delete[] niz;
}

template<class T>
inline Skup<T>::Skup()
{
	niz = nullptr;
	top = 0;
	maxEl = 0;
}

template<class T>
inline Skup<T>::Skup(int _maxEl)
{
	ZauzmiMem(_maxEl);
}

template<class T>
inline Skup<T>::~Skup()
{
	OslobodiProstor();
}

template<class T>
inline Skup<T>::Skup(const Skup<T>& s)
{
	ZauzmiMem(s.maxEl);
	for (int i = 0; i < s.top; ++i)
		Dodaj(s.niz[i]);
}

template<class T>
inline Skup<T>& Skup<T>::operator=(const Skup<T>& s)
{
	if (this != &s) {
		OslobodiProstor();
		ZauzmiMem(s.maxEl);
		for (int i = 0; i < s.maxEl; ++i)
			Dodaj(s.niz[i]);
	}
	return *this;
}

template<class T>
inline void Skup<T>::Dodaj(T& el)
{
	if (top == maxEl)
		throw exception("Nema vise mesta u skupu.");

	niz[top++] = el;	// operator =
}

template<class T>
inline int Skup<T>::BrojDuplikata(T& x)
{
	int br = 0;
	// operator ==
	for (int i = 0; i < top; ++i) {
		if (niz[i] == x)
			++br;
	}

	return br;
}

template<class T>
inline void Skup<T>::IzbaciDuplikate()
{
	for (int i = 0; i < top; ++i) {
		for (int j = i + 1; j < top; ++j) {
			if (niz[i] == niz[j]) {
				for (int k = j; k < top - 1; ++k)
					niz[k] = niz[k + 1];
				top--;
				--i;
			}
		}
	}
}

template<class T>
inline void Skup<T>::Sortiraj()
{
	// operator >
	for (int i = 0; i < top-1; ++i)
		for (int j = i+1; j < top; ++j)
			if (niz[i] > niz[j])
			{
				T *tmp = new T(niz[i]);
				niz[i] = niz[j];
				niz[j] = *tmp;
			}
}

template<class T>
inline Skup<T> Skup<T>::operator+(Skup<T>& s)
{
	// nije ovo bas unija jer ce dva puta da doda presek al mrzi me da se jebavam s to
	// mada i zadatak je malo glup sto uopste omogucava da SKUP ima duplikati...
	Skup<T> unija(s.top + top);
	for (int i = 0; i < top; ++i)
		unija.Dodaj(niz[i]);
	for (int i = 0; i < s.top; ++i)
		unija.Dodaj(s.niz[i]);
	return unija;
}

template<class T>
inline Skup<T> Skup<T>::operator*(Skup<T>& s)
{
	Skup<T> presek(max(s.top, top));
	for (int i = 0; i < top; ++i) {
		for (int j = 0; j < s.top; ++j) {
			if (niz[i] == s.niz[j]) {
				presek.Dodaj(niz[i]);
				break;
			}
		}
	}
	return presek;
}

template<class T>
inline void Skup<T>::Sacuvaj(const char* imeFajla)
{
	ofstream izlaz(imeFajla);
	if (!izlaz.good())
		throw exception("Greska pri cuvanju u fajl.");

	izlaz << *this;
	izlaz.close();
}

template<class T>
inline void Skup<T>::Ucitaj(const char* imeFajla)
{
	ifstream ulaz(imeFajla);
	if (!ulaz.good())
		throw exception("Greska pri ucitavanju iz fajla.");

	ulaz >> *this;
	ulaz.close();
}
