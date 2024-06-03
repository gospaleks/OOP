#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template <class t>
class Kolekcija
{
private:	
	t* niz;
	int nmax;
	int brtr;
	void zauzmiMem(int nmax);

public:
	Kolekcija();
	Kolekcija(int nmax);
	~Kolekcija();
	void DodajPodatak(t& podatak);
	void Obrisi(int indeks);
	float OdrediProsek();
	t& NajveciPodatak();
	void Sacuvaj(const char* imeFajla);
	void Ucitaj(const char* imeFajla);

	friend ostream& operator<<(ostream& izlaz, Kolekcija<t>& k) {
		izlaz << k.nmax << " " << k.brtr << endl;
		for (int i = 0; i < k.brtr; i++)
			izlaz << k.niz[i] << endl;				//treba operator<<	
		return izlaz;
	}
};

template<class t>
inline void Kolekcija<t>::zauzmiMem(int nmax)
{
	this->nmax = nmax;
	brtr = 0;
	niz = new t[nmax];
}

template<class t>
inline Kolekcija<t>::Kolekcija()
{
	niz = nullptr;
	nmax = brtr = 0;
}

template<class t>
inline Kolekcija<t>::Kolekcija(int nmax)
{
	zauzmiMem(nmax);
}

template<class t>
inline Kolekcija<t>::~Kolekcija()
{
	if (niz != nullptr)
		delete[] niz;
}

template<class t>
inline void Kolekcija<t>::DodajPodatak(t& podatak)
{
	if (brtr < nmax)
		niz[brtr++] = podatak;
	else
		throw "nema vise mesta u kolekciji!";
}

template<class t>
inline void Kolekcija<t>::Obrisi(int indeks)
{
	if (indeks <= 0 || indeks >= brtr)
		throw "nepostojeci indeks";
	for (int i = indeks; i < brtr - 1 ; i++)
		niz[i] = niz[i + 1];				// ovde treba operator=
	brtr--;
}

template<class t>
inline float Kolekcija<t>::OdrediProsek()
{
	float prosek = 0;			
	for (int i = 0; i < brtr; i++)
		prosek = niz[i] + prosek;			//treab operator+(float)
	return prosek / brtr;
}

template<class t>
inline t& Kolekcija<t>::NajveciPodatak()
{
	int max = 0;
	for (int i = 1; i < brtr; i++)
		if (niz[i] > niz[max])				//operator>
			max = i;
	return niz[max];
}

template<class t>
inline void Kolekcija<t>::Sacuvaj(const char* imeFajla)
{
	ofstream izlaz(imeFajla);
	if (!izlaz.good())
		throw "problem pri ucitavanju fajla!";
	else
		izlaz << *this;
}

template<class t>
inline void Kolekcija<t>::Ucitaj(const char* imeFajla)
{
	ifstream ulaz(imeFajla);
	if (!ulaz.good())
		throw "nije good!";
	else {
		int n, tempbrtr;
		ulaz >> n;
		niz = new t[n];
		ulaz >> tempbrtr;
		for (int i = 0; i < tempbrtr; i++) {
			t* pod = new t();
			ulaz >> *pod;			//operator>>
			this->DodajPodatak(*pod);
			delete pod;
		}
	}
}
