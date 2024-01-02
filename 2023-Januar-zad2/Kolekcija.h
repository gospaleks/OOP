#pragma once
#include <fstream>
#include <iostream>

template <class T>
class Kolekcija
{
private:
	T* niz;
	int top;
	int maxEl;

	void prosiriMem();
public:

	Kolekcija();
	Kolekcija(int _maxEl);
	~Kolekcija();

	void dodaj(T t);
	void obrisiPrvihX(int x);
	int brojPosetilacaIzmedju(int Od, int Do);
	void dvaDanaMinZarada(int *dan1, int *dan2);

	void sacuvaj(const char* fajl);
	void ucitaj(const char* fajl);

	// ovo se ne trazi
	void ispisiNaEkran() {
		std::cout << std::endl;
		for (int i = 0; i < top; ++i)
			std::cout << niz[i] << " / ";
		std::cout << std::endl;
	}
};

template<class T>
inline void Kolekcija<T>::prosiriMem()
{
	int newMax = maxEl + (maxEl / 2);
	T* tmp = new T[newMax];
	for (int i = 0; i < top; ++i)
		tmp[i] = niz[i];				// mozda ce treba copy constructor
	
	delete[] niz;

	maxEl = newMax;
	niz = new T[maxEl];
	for (int i = 0; i < top; ++i)
		niz[i] = tmp[i];

	delete[] tmp;
}

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
}

template<class T>
inline Kolekcija<T>::~Kolekcija()
{
	if (niz != nullptr)
		delete [] niz;
}

template<class T>
inline void Kolekcija<T>::dodaj(T t)
{
	if (top == maxEl) {
		prosiriMem();
		niz[top++] = t;
	}
	else {
		niz[top++] = t;
	}
}

template<class T>
inline void Kolekcija<T>::obrisiPrvihX(int x)
{
	if (x < 0 || x >= top) {
		throw "Vrednost X je nevalidna.";
	}
	else {
		// u sustini treba da pomerimo sve za x mesta ulevo
		for (int k = 0; k < x; ++k) {
			for (int i = 0; i < top - 1; ++i)
				niz[i] = niz[i + 1];			// i ovde mzd treba se napravi copy constructor (ipak ne mora jer nema pokazivaci)
			--top;
			// niz[top] = T();
		}
	}
}

template<class T>
inline int Kolekcija<T>::brojPosetilacaIzmedju(int Od, int Do)
{
	int rez = 0;
	if (Od > Do)
		throw "Prvi broj mora biti manji.";
	else if (Od < 0 || Od >= top || Do < 0 || Do >= top)
		throw "Nevalidni brojevi od-do.";
	else {
		for (int i = Od; i <= Do; ++i) {
			rez = niz[i] + rez;
		}
	}

	return rez;
}

template<class T>
inline void Kolekcija<T>::dvaDanaMinZarada(int *dan1, int *dan2)
{
	*dan1 = 0;
	for (int i = 1; i < top; ++i) {
		if (niz[i] < niz[*dan1])
			*dan1 = i;
	}

	*dan2 = (*dan1 + 1) % top;
	for (int i = 1; i < top; ++i)
	{
		if (i != *dan1 && niz[i] < niz[*dan2])
			*dan2 = i;
	}
}


template<class T>
inline void Kolekcija<T>::sacuvaj(const char* fajl)
{
	std::ofstream izlaz(fajl);
	if (!izlaz.good()) {
		throw "Greska pri upisu u fajl.";
	}
	else {
		for (int i = 0; i < top; ++i)
			izlaz << niz[i] << " ";
		izlaz.close();
	}
}

template<class T>
inline void Kolekcija<T>::ucitaj(const char* fajl)
{
	std::ifstream ulaz(fajl);
	if (!ulaz.good()) {
		throw "Greska pri citanju fajla.";
	}
	else {
		top = 0;
		while (ulaz >> niz[top])
			++top;
		ulaz.close();
	}
}
