#pragma once

#include <iostream>

using std::cout;
using std::endl;

template <class T>
class Novcanik
{
private:
	T* niz;
	int maxPodataka;
	int brTr;

public:
	Novcanik(int _maxPodataka);
	~Novcanik();

	friend std::ostream& operator<<(std::ostream& izlaz, const Novcanik<T>& n)
	{
		// istim redom posle ucitati iz fajla
		izlaz << n.maxPodataka << endl;
		izlaz << n.brTr << endl;
		for (int i = 0; i < n.brTr; ++i)
			izlaz << n.niz[i] << endl;

		return izlaz;
	}

	void Dodaj(T t);
	void Izbaci(T t);

	float Ukupno();
	int UkupniBrojVrednost(T vrednost, float& ukupnaVrednost);
	int NajmanjeNovcanica(int vrednostDin);

	void Sacuvaj(const char* imeFajla);
	void Ucitaj(const char* imeFajla);
};

template<class T>
inline Novcanik<T>::Novcanik(int _maxPodataka)
{
	maxPodataka = _maxPodataka;
	brTr = 0;
	niz = new T[maxPodataka];
}

template<class T>
inline Novcanik<T>::~Novcanik()
{
	if (niz != nullptr)
		delete[] niz;
}

template<class T>
inline void Novcanik<T>::Dodaj(T t)
{
	if (brTr == maxPodataka) {
		throw "Nema mesta u novcaniku!";
	}

	// Pronalazenje mesta za ubacivanje tako da niz ostane sortiran nerastuce
	int i = 0;
	while (i < brTr && t <= niz[i]) // operator<=
		++i;

	for (int j = brTr; j > i; --j)
		niz[j] = niz[j - 1]; // operator=

	niz[i] = t;
	++brTr;
}

template<class T>
inline void Novcanik<T>::Izbaci(T t) // copy constructor
{
	if (brTr == 0)
		throw "Novcanik je prazan!";

	for (int i = 0; i < brTr; ++i)
	{
		if (t == niz[i]) { // operator==
			for (int j = i; j < brTr - 1; ++j)
				niz[j] = niz[j + 1];

			--brTr;
			return;
		}
	}

	throw "Novcanica nije pronadjena!";
}

template<class T>
inline float Novcanik<T>::Ukupno()
{
	float rez = 0.0f; // u dinari
	for (int i = 0; i < brTr; ++i)
		rez = niz[i] + rez; // operator+(float)

	return rez;
}

template<class T>
inline int Novcanik<T>::UkupniBrojVrednost(T vrednost, float& ukupnaVrednost)
{
	int brNovSaVrednoscu = 0;
	ukupnaVrednost = 0.0f;

	for (int i = 0; i < brTr; ++i) {
		if (niz[i] == vrednost) { // operator==
			++brNovSaVrednoscu;
			ukupnaVrednost = niz[i] + ukupnaVrednost; // operator+(float)
		}
	}

	return brNovSaVrednoscu;
}

template<class T>
inline int Novcanik<T>::NajmanjeNovcanica(int vrednostDin)
{
	int brNovZaPlacanje = 0;
	int trenutnaVrednost = 0;

	for (int i = 0; i < brTr; ++i) {
		if (niz[i] + trenutnaVrednost >= vrednostDin) {
			++brNovZaPlacanje;
			return brNovZaPlacanje;
		}
		else {
			trenutnaVrednost = niz[i] + trenutnaVrednost;
			++brNovZaPlacanje;
		}
	}

	return brNovZaPlacanje;
}

template<class T>
inline void Novcanik<T>::Sacuvaj(const char* imeFajla)
{
	std::ofstream izlaz(imeFajla);

	if (izlaz.good()) {
		izlaz << *this;
		izlaz.close();
	}
	else {
		cout << "Greska prilikom otvaranja fajla za upis!" << endl;
	}
}

template<class T>
inline void Novcanik<T>::Ucitaj(const char* imeFajla)
{
	std::ifstream ulaz(imeFajla);

	if (ulaz.good()) {
		ulaz >> maxPodataka;
		ulaz >> brTr;
		for (int i = 0; i < brTr; ++i)
			ulaz >> niz[i];

		ulaz.close();
	}
	else {
		cout << "Greska prilikom otvaranja fajla za citanje!" << endl;
	}
}


