#pragma once
#include <iostream>
#include <fstream>

template <class T>
class Skola
{
private:
	T* niz;
	int top;
	int maxEl;

	void ZauzmiMem(int n);
public:
	Skola();
	Skola(int _maxEl);
	~Skola();

	void Dodaj(T& aktivnost);
	void Otkazi(int broj);
	float ProsecnaVrednost();

	friend std::istream& operator>>(std::istream& ulaz, Skola<T>& skola) {
		int n;
		ulaz >> n;
		for (int i = 0; i < n; ++i) {
			T *akt = new T();
			ulaz >> *akt;
			skola.Dodaj(*akt);
		}
		return ulaz;
	}

	void IzvestajProsek(const char* imeFajla);
	void IzvestajNajvrednija(const char* imeFajla);
	void IzvestajNajmanjeVredna(const char* imeFajla);

	void StampajNaEkran() {
		for (int i = 0; i < top; ++i)
			std::cout << niz[i] << std::endl;
		std::cout << std::endl << "Prosecna vrednost: " << ProsecnaVrednost() << std::endl;
		std::cout << "Najvrednija aktivnost: " << niz[0] << std::endl;
		std::cout << "Najmanje vredna aktivnost: " << niz[top - 1] << std::endl;
		std::cout << "----------------------------------------------\n\n";
	}
};

template<class T>
inline void Skola<T>::ZauzmiMem(int n)
{
	maxEl = n;
	top = 0;
	niz = new T[maxEl];
}

template<class T>
inline Skola<T>::Skola()
{
	niz = nullptr;
	top = maxEl = 0;
}

template<class T>
inline Skola<T>::Skola(int _maxEl)
{
	ZauzmiMem(_maxEl);
}

template<class T>
inline Skola<T>::~Skola()
{
	if (niz != nullptr)
		delete[] niz;
}

template<class T>
inline void Skola<T>::Dodaj(T& aktivnost)
{
	if (top == maxEl) {
		throw "Nema slobodnih mesta.";
	}
	else {
		// Treba aktivnost dodati na ono mesto tako da se ne naruse uslovi
		// (tj. da se raspored aktivnosti odrzava po vrednosti)
		if (top > 0) {
			int i = 0;
			bool nadjen = false;
			while (i < top && !nadjen) {
				if (aktivnost > niz[i]) {										// treba operator > za klasu Sport
					nadjen = true;
					// sve pomeri jedno mesto u desno
					for (int j = top; j > i; --j)
						niz[j] = niz[j - 1];
					// na prazno mesto ubaci novu aktivnost
					niz[i] = aktivnost;
				}
				++i;
			}

			if (!nadjen) {
				niz[top] = aktivnost;
			}

			top++;
		}
		// ovo ce samo u prvi prolaz da se odradi kad nema elemenata u nizu
		else {
			niz[top++] = aktivnost;
		}


	}
}

template<class T>
inline void Skola<T>::Otkazi(int broj)
{
	if (broj < 0 || broj >= maxEl) {
		throw "Broj sale je nepostojeci.";
	}
	else {
		// dovoljno je da se sve pomeri za jedno mesto u levo do tog elementa
		// zato sto nije niz pokazivaca, samo preklapanje je u stvari brisanje trenutnog objekta
		for (int i = broj; i < top - 1; ++i)
			niz[i] = niz[i + 1];				// ce se pozove operator=
		top--;
	}
}

template<class T>
inline float Skola<T>::ProsecnaVrednost()
{
	float rez = 0;
	for (int i = 0; i < top; ++i) {
		rez = niz[i] + rez;						// ovako ga zapisujem da bi napravio operator+(float x)
	}
	return (rez / (float)top);
}

template<class T>
inline void Skola<T>::IzvestajProsek(const char* imeFajla)
{
	std::ofstream izlaz(imeFajla);
	if (izlaz.good()) {
		if (top == 0)
			izlaz << "0";
		else
			izlaz << "Prosecna vrednost svih aktivnosti je:\t" << ProsecnaVrednost();
		izlaz.close();
	}
}

template<class T>
inline void Skola<T>::IzvestajNajvrednija(const char* imeFajla)
{
	if (top == 0)
		throw "U skoli nema ni jedna aktivnost. Ne moze se kreirati izvestaj o najvrednijoj aktivnosti.";

	std::ofstream izlaz(imeFajla);
	if (izlaz.good()) {
		izlaz << "Podaci o najvrednijoj aktivnosti:\n" << niz[0];
		izlaz.close();
	}
}

template<class T>
inline void Skola<T>::IzvestajNajmanjeVredna(const char* imeFajla)
{
	if (top == 0)
		throw "U skoli nema ni jedna aktivnost. Ne moze se kreirati izvestaj o najmanje vrednoj aktivnosti.";

	std::ofstream izlaz(imeFajla);
	if (izlaz.good()) {
		izlaz << "Podaci o najmanje vrednoj aktivnosti:\n" << niz[top-1];
		izlaz.close();
	}
}

