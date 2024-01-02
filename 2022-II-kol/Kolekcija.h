#pragma once
#include <fstream>
#include <iostream>
using namespace std;

template<class T>
class Kolekcija
{
private:
	T* niz;
	int top;
	int maxEl;
public:
	Kolekcija();
	Kolekcija(int _maxEl);
	~Kolekcija();

	friend ostream& operator<<(ostream& izlaz, Kolekcija<T>& k) {
		// izlaz << "Sadrzaj kolekcije:\n";
		for (int i = 0; i < k.top; ++i)
			izlaz << (k.niz[i]) << " ";
		// izlaz << endl;
		return izlaz;
	}

	void DodajPodatak(T pod);
	void Obrisi(int i);

	float OdrediProsek();
	T NajveciPodatak();

	void Sacuvaj(const char* imeFajla);
	void Ucitaj(const char* imeFajla);
};

template<class T>
inline Kolekcija<T>::Kolekcija()
{
	niz = nullptr;
	top = maxEl = 0;
}

template<class T>
inline Kolekcija<T>::Kolekcija(int _maxEl)
{
	maxEl = _maxEl;
	top = 0;
	niz = new T[maxEl];
	for (int i = 0; i < maxEl; ++i)
		niz[i] = T();
}

template<class T>
inline Kolekcija<T>::~Kolekcija()
{
	if (niz != nullptr) {
		delete[] niz;
	}
}

template<class T>
inline void Kolekcija<T>::DodajPodatak(T podatak)
{
	if (top == maxEl) {
		throw "Kolekcija je puna!";
	}
	else {
		niz[top++] = podatak;
	}
}

template<class T>
inline void Kolekcija<T>::Obrisi(int i)
{
	if (i < 0 || i >= top) {
		throw "Ne postoji podatak sa zadatim rednim brojem!";
	}
	else {
		for (int j = i; j < top - 1; ++j)
			niz[j] = niz[j + 1];
		top--;
		niz[top] = T();
	}
}

template<class T>
inline float Kolekcija<T>::OdrediProsek()
{
	// operator + vestacki sabira subjektivne osecaje
	// eksplicitno je predefinisan da bi ovo radilo
	// lvalue je this, rvalue je float, vraca float (vidi ProsireniPodaci.h)
	float rez = 0;
	for (int i = 0; i < top; ++i)
		rez = niz[i] + rez;
	return (rez / top);
}

template<class T>
inline T Kolekcija<T>::NajveciPodatak()
{
	T maks = niz[0];
	for (int i = 1; i < top; ++i)
		if (niz[i] > maks)
			maks = niz[i];
	return maks;
}

template<class T>
inline void Kolekcija<T>::Sacuvaj(const char* imeFajla)
{
	ofstream izlaz(imeFajla);
	if (!izlaz.good()) {
		throw "Problem pri cuvanju kolekcije!";
	}
	else {
		izlaz << *this;
	}
}

template<class T>
inline void Kolekcija<T>::Ucitaj(const char* imeFajla)
{
	ifstream ulaz(imeFajla);
	if (!ulaz.good()) {
		throw "Problem pri ucitavanju datoteke!";
	}
	else {
		T podatak = T();
		while (ulaz >> podatak) {
			this->DodajPodatak(podatak);
		}
	}
}
