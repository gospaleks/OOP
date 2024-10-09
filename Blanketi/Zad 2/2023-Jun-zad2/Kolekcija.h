#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class Kolekcija
{
private:
	T aktPodatak;
	T* niz;
	int maxEl;
	int top;
	void ZauzmiMem(int _maxEl);
public:
	Kolekcija();
	Kolekcija(int _maxEl);
	~Kolekcija();

	void Dodaj(int redniBroj, T& noviPodatak);
	T RazlikaPotrosnje(int redniBroj);
	float ProsecnaPotrosnja();
	void MinMaxPotrosnja(T* minPotrosnja, T* maxPotrosnja);
	int BrojVecihOdAktuelne();

	void Sacuvaj(const char* imeFajla);
	void Ucitaj(const char* imeFajla);


	// trebaju operatori << i >> 
	friend ostream& operator<<(ostream& izlaz, Kolekcija<T>& k) {
		izlaz << k.aktPodatak << endl;
		izlaz << k.maxEl << endl;
		izlaz << k.top << endl;
		for (int i = 0; i < k.maxEl; ++i)
			izlaz << k.niz[i] << endl;
		return izlaz;
	}

	friend istream& operator>>(istream& ulaz, Kolekcija<T>& k) {
		ulaz >> k.aktPodatak;
		ulaz >> k.maxEl;
		ulaz >> k.top;
		k.ZauzmiMem(k.maxEl);
		for (int i = 0; i < k.maxEl; ++i) {
			ulaz >> k.niz[i];
		}
		return ulaz;
	}

	void PrikaziSpisak(ostream& izlaz) {
		izlaz << "Aktuelni podatak:\t" << aktPodatak << endl;
		for (int i = 0; i < maxEl; ++i)
		{
			izlaz << i + 1 << ":\t";
			izlaz << niz[i] << endl;
		}
	}
};

template<class T>
inline void Kolekcija<T>::ZauzmiMem(int _maxEl)
{
	maxEl = _maxEl;
	niz = new T[maxEl];
	for (int i = 0; i < maxEl; ++i)
		niz[i] = T();
}

template<class T>
inline Kolekcija<T>::Kolekcija()
{
	aktPodatak = T();
	niz = nullptr;
	maxEl = top = 0;
}

template<class T>
inline Kolekcija<T>::Kolekcija(int _maxEl)
{
	top = 0;
	aktPodatak = T();
	ZauzmiMem(_maxEl);
}

template<class T>
inline Kolekcija<T>::~Kolekcija()
{
	if (niz != nullptr)
		delete[] niz;
}

template<class T>
inline void Kolekcija<T>::Dodaj(int redniBroj, T& noviPodatak)
{	
	// kako radi neam pojma, ne pitaj me
	--redniBroj;

	if (top + 1 == maxEl) {
		niz[top] = aktPodatak;
		aktPodatak = T();
		top = 0;
	}

	// treba mi operator == 
	if (redniBroj == 0 && top == 0 && aktPodatak == T()) {
		aktPodatak = noviPodatak;
	}
	else if (redniBroj == top+1) {
		niz[top] = aktPodatak;
		aktPodatak = noviPodatak;
		top++;
	}
	else {
		throw exception("Nije moguce dodati podatak.");
	}

}

template<class T>
inline T Kolekcija<T>::RazlikaPotrosnje(int redniBroj)
{
	// ovo pod komentar da bi u svaki prolaz mogo da ispisem razliku u odnosu na prethodno stanje tog meseca/dana/godine
	//if (niz[redniBroj - 1] == T())
	//	throw exception("Podatak za koji se trazi razlika u potrosnji ne postoji u istoriji.");

	// traba mi operator-
	return (aktPodatak - niz[redniBroj-1]);
}

template<class T>
inline float Kolekcija<T>::ProsecnaPotrosnja()
{
	int rez = 0;
	int br = 0;

	for (int i = 0; i < maxEl; ++i)
		if (!(niz[i] == T())) {
			rez = niz[i] + rez;				// treba operator+(int x)
			++br;
		}

	if (br == 0) return 0;
	return ((float)rez / (float)br);
}

template<class T>
inline void Kolekcija<T>::MinMaxPotrosnja(T* minPotrosnja, T* maxPotrosnja)
{
	if (top == 0)
		throw exception("Nema podataka u istoriji. Ne moze se vratiti min i max potrosnja");

	*minPotrosnja = niz[0];
	*maxPotrosnja = niz[0];

	for (int i = 1; i < maxEl; ++i) {
		if (!(niz[i] == T()))
		{
			// operatori > i <
			if (niz[i] > *maxPotrosnja)
				*maxPotrosnja = niz[i];
			if (niz[i] < *minPotrosnja)
				*minPotrosnja = niz[i];
		}
	}
}

template<class T>
inline int Kolekcija<T>::BrojVecihOdAktuelne()
{
	int br = 0;
	for (int i = 0; i < maxEl; ++i) {
		if (!(niz[i] == T()))
			if (niz[i] > aktPodatak)
				++br;
	}
	return br;
}

template<class T>
inline void Kolekcija<T>::Sacuvaj(const char* imeFajla)
{
	ofstream izlaz(imeFajla);
	if (!izlaz.good())
		throw exception("Greska pri cuvanju u datoteku.");

	izlaz << *this;
}

template<class T>
inline void Kolekcija<T>::Ucitaj(const char* imeFajla)
{
	ifstream ulaz(imeFajla);
	if (!ulaz.good())
		throw exception("Greska pri ucitavanju iz datoteke.");

	if (niz != nullptr)
		delete[] niz;
	
	ulaz >> *this;
}
