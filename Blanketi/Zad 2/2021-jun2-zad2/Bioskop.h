#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class Bioskop
{
private:
	T* niz;
	int top;
	int maxEl;
	float minOcena;
	void zauzmiMem(int _maxEl, float _minOcena);
public:
	Bioskop();
	Bioskop(int _maxEl, float _minOcena);
	~Bioskop();

	void Dodaj(T& podatak);
	void Obrisi(int pozicija);
	void PromeniOcenu(int pozicija, float novaOcena);
	int BrojFilmovaSaOcenom(float ocena);
	void VratiMinMaxPodatak(T* minPodatak, T* maxPodatak);

	void Sacuvaj(const char* imeFajla);
	void Ucitaj(const char* imeFajla);

	friend ostream& operator<<(ostream& izlaz, Bioskop<T>& b) {
		izlaz << b.minOcena << endl;
		izlaz << b.top << endl;
		// napraviti operator << u klasi Film
		for (int i = 0; i < b.top; ++i)
			izlaz << b.niz[i] << endl;
		return izlaz;
	}

	friend istream& operator>>(istream& ulaz, Bioskop<T>& b) {
		float minOcena;
		int n, _maxEl;
		ulaz >> minOcena >> n;
		_maxEl = n + (n * 0.2);
		b.zauzmiMem(_maxEl, minOcena);
		// napraviti operator >> u klasi Film
		for (int i = 0; i < n; ++i) {
			T* tmp = new T();
			ulaz >> *tmp;
			b.Dodaj(*tmp);
		}
		return ulaz;
	}
};

template<class T>
inline void Bioskop<T>::zauzmiMem(int _maxEl, float _minOcena)
{
	minOcena = _minOcena;
	maxEl = _maxEl;
	top = 0;
	niz = new T[maxEl];
}

template<class T>
inline Bioskop<T>::Bioskop()
{
	niz = nullptr;
	top = 0;
	maxEl = 0;
	minOcena = 0;
}

template<class T>
inline Bioskop<T>::Bioskop(int _maxEl, float _minOcena)
{
	zauzmiMem(_maxEl, _minOcena);
}

template<class T>
inline Bioskop<T>::~Bioskop()
{
	if (niz != nullptr)
		delete[] niz;
}

template<class T>
inline void Bioskop<T>::Dodaj(T& podatak)
{
	if (top == maxEl)
		throw exception("Prekoracenje. Nema vise mesta.");

	// treba napraviti operator<(float x) u klasi Film
	if (podatak < minOcena)
		throw exception("Ocena unetog podatka je manja od minimalne ocene.");

	niz[top++] = podatak;
}

template<class T>
inline void Bioskop<T>::Obrisi(int pozicija)
{
	if (pozicija < 0 || pozicija >= top)
		throw exception("Nepostojeca pozicija.");

	// treba predefinisati operator= u klasi Film
	for (int i = pozicija; i < top - 1; ++i)
		niz[i] = niz[i + 1];

	--top;
	niz[top] = T();
}

template<class T>
inline void Bioskop<T>::PromeniOcenu(int pozicija, float novaOcena)
{
	if (pozicija < 0 || pozicija >= top)
		throw exception("Nepostojeca pozicija.");
	
	if (novaOcena < minOcena)
		Obrisi(pozicija);
	else {
		// treba napraviti operator=(float x) u klasi Film
		niz[pozicija] = novaOcena;
	}
}

template<class T>
inline int Bioskop<T>::BrojFilmovaSaOcenom(float ocena)
{
	int rez = 0;
	// treba napraviti operator==(float x) koji poredi ocene u klasi Film
	for (int i = 0; i < top; ++i)
		if (niz[i] == ocena)
			++rez;
	return rez;
}

template<class T>
inline void Bioskop<T>::VratiMinMaxPodatak(T* minPodatak, T* maxPodatak)
{
	*minPodatak = niz[0];
	*maxPodatak = niz[0];
	for (int i = 1; i < top; ++i)
	{
		// operatori > i < u klasi film
		if (niz[i] > *maxPodatak)
			*maxPodatak = niz[i];

		if (niz[i] < *minPodatak)
			*minPodatak = niz[i];
	}
}

template<class T>
inline void Bioskop<T>::Sacuvaj(const char* imeFajla)
{
	ofstream izlaz(imeFajla);
	if (!izlaz.good())
		throw exception("Greska pri cuvanju u fajl.");

	izlaz << *this;
}

template<class T>
inline void Bioskop<T>::Ucitaj(const char* imeFajla)
{
	ifstream ulaz(imeFajla);
	if (!ulaz.good())
		throw exception("Greska pri ucitavanju fajla.");

	ulaz >> *this;
}
