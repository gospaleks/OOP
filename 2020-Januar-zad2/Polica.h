#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class Polica
{
private:
	T* niz;
	int top;
	int maxEl;
	void ZauzmiMem(int _maxEl);
public:
	Polica();
	Polica(int _maxEl);
	~Polica();

	void Dodaj(T& element);
	void Izbaci(int index);

	void Ucitaj(const char* imeFajla);

	friend ostream& operator<<(ostream& izlaz, const Polica& p) {
		izlaz << p.top << endl;
		for (int i = 0; i < p.top; ++i)
			izlaz << p.niz[i] << endl;
		izlaz << endl;
		return izlaz;
	}

	friend istream& operator>>(istream& ulaz, Polica& p) {

		int n;
		ulaz >> n;
		p.maxEl = n + (n / 2);	// osiguram da ima 
		p.ZauzmiMem(p.maxEl);
		for (int i = 0; i < n; ++i)
		{
			T* el = new T();
			ulaz >> *el;
			p.Dodaj(*el);
		}

		return ulaz;
	}
};

template<class T>
inline void Polica<T>::ZauzmiMem(int _maxEl)
{
	maxEl = _maxEl;
	niz = new T[maxEl];
	for (int i = 0; i < top; ++i)
		niz[i] = T();
}

template<class T>
inline Polica<T>::Polica()
{
	niz = nullptr;
	top = maxEl = 0;
}

template<class T>
inline Polica<T>::Polica(int _maxEl)
{
	top = 0;
	ZauzmiMem(_maxEl);
}

template<class T>
inline Polica<T>::~Polica()
{
	if (niz != nullptr)
		delete[] niz;
}

template<class T>
inline void Polica<T>::Dodaj(T& element)
{
	if (top == maxEl)
		throw exception("Niz je pun.");


	// operator ==
	bool nadjen = false;
	for (int i = 0; i < top && !nadjen; ++i)
		if (niz[i] == element)
			nadjen = true;

	if (nadjen)
		throw exception("Element vec postoji u nizu");

	if (top == 0)
		niz[top++] = element;
	else {
		// treba operator >
		int i = 0;
		while (i < top && element > niz[i])
			++i;

		if (i == top)
			niz[top++] = element;
		else {
			for (int j = top; j > i; --j)
				niz[j] = niz[j - 1];
			niz[i] = element;
			top++;
		}
	}
}

template<class T>
inline void Polica<T>::Izbaci(int index)
{
	if (top == 0 || index < 0 || index >= top)
		throw exception("Nepostojeci index.");

	for (int i = index; i < top - 1; ++i)
		niz[i] = niz[i + 1];
	top--;
	// niz[top] = T();
}

template<class T>
inline void Polica<T>::Ucitaj(const char* imeFajla)
{
	ifstream ulaz(imeFajla);
	if (!ulaz.good())
		throw exception("Greska pri ucitavanju iz fajla.");

	ulaz >> *this;

	ulaz.close();
}
