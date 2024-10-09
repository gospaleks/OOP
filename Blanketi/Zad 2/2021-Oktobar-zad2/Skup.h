#pragma once
#include <iostream>
using namespace std;

template <class t>
class Skup
{
private:
	int max;
	int brtr;
	t* niz;
public:
	Skup();
	Skup(int mmax);
	~Skup();
	void dodaj(t& element);
	void obrisi(int indeks);		//redni broj brtr
	
	Skup<t>& operator+(Skup<t>& s);
	Skup<t>& operator=(const Skup<t>& s);
	
	friend ostream& operator<<(ostream& izlaz, Skup<t>& s) {
		for (int i = 0; i < s.brtr; i++)
			izlaz << s.niz[i];
		izlaz << endl;
		return izlaz;
	}
	
	void oslobodimem();
	void zauzmimem(int mmax);
	void kopiraj(t* temp, int duzina);
};

template<class t>
inline Skup<t>::Skup()
{
	max = brtr = 0;
	niz = nullptr;
}

template<class t>
inline Skup<t>::Skup(int mmax)
{
	zauzmimem(mmax);
}

template<class t>
inline Skup<t>::~Skup()
{
	oslobodimem();
}

template<class t>
inline void Skup<t>::dodaj(t& element)
{
	if (!(brtr < max))
		throw "nema mesta vise";
	else
		for (int i = 0; i < brtr; i++)
			if (niz[i] == element)
				throw "ima vec taj student";
		niz[brtr++] = element;
}

template<class t>
inline void Skup<t>::obrisi(int indeks)
{
	if (indeks <= 0 || indeks >= brtr)
		throw "nepostojeci element";
	for (int i = indeks; i < brtr - 1; i++)
		niz[i] = niz[i + 1];			
	--brtr;
	//treba mozda niz[brtr]=t(), ali ko ume nek resi, a realno i ne mora
}

template<class t>
inline Skup<t>& Skup<t>::operator+(Skup<t>& s)
{
	Skup<t> *temp = new Skup<t>(this->max + s.max);
	for (int i = 0; i < this->brtr; i++)
		temp->dodaj(this->niz[i]);
	for (int i = 0; i < s.brtr; i++)
		temp->dodaj(s.niz[i]);
	return *temp;
}

template<class t>
inline Skup<t>& Skup<t>::operator=(const Skup<t>& s)
{
	if (this != &s) {
		oslobodimem();
		zauzmimem(s.max);
		kopiraj(s.niz, s.brtr);
	}
	return *this;
}

template<class t>
inline void Skup<t>::oslobodimem()
{
	if (niz != nullptr)
		delete[] niz;
}

template<class t>
inline void Skup<t>::zauzmimem(int mmax)
{
	brtr = 0;
	max = mmax;
	niz = new t[max];
}

template<class t>
inline void Skup<t>::kopiraj(t* temp, int duzina)
{
	for (int i = 0; i < duzina; i++)
		dodaj(temp[i]);
}
