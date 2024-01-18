#pragma once
#include <iostream>
#include "Banana.h"
using namespace std;

template <class Pod>
class Kolekcija
{
	Pod* niz;
	int top;
	int maxEl;
public:
	Kolekcija();
	Kolekcija(int mmaxEl);
	~Kolekcija();
	void dodaj(Pod& p);
	float prosek();
	void obrisi(float procenat);

	friend ostream& operator<<(ostream& izlaz, Kolekcija& k)
	{
		for (int i = 0; i < k.top; i++)
			izlaz << k.niz[i] << endl;
		return izlaz;
	}
};

template<class Pod>
inline Kolekcija<Pod>::Kolekcija()
{
	niz = nullptr;
	top = 0;
	maxEl = 0;
}

template<class Pod>
inline Kolekcija<Pod>::Kolekcija(int mmaxEl)
{
	maxEl = mmaxEl;
	niz = new Pod[maxEl];
	top = 0;
}

template<class Pod>
inline Kolekcija<Pod>::~Kolekcija()
{
	if (niz != nullptr)
		delete[] niz;
}

template<class Pod>
inline void Kolekcija<Pod>::dodaj(Pod& p)
{
	if (top == maxEl)
		throw "Nije moguce dodati element";
	else
		niz[top++] = p;
}

template<class Pod>
inline float Kolekcija<Pod>::prosek()
{
	float rez = 0;
	for (int i = 0; i < top; i++)
		rez = niz[i] + rez;
	return (rez / top);
}

template<class Pod>
inline void Kolekcija<Pod>::obrisi(float procenat)
{
	float pprosek = this->prosek();
	float rez = 0;
	float dozvoljeno = 0;
	for (int i = 0; i < top; i++)
	{
		rez = abs(niz[i] - pprosek); // razlika izmedju prosek i trenutni element 
		dozvoljeno = this->prosek() * procenat / 100;	// kolko sme da bude izvan proseka
		if (rez > dozvoljeno)
		{
			for (int j = i; j < top - 1; j++)
			{
				niz[j] = niz[j + 1];
			}
			//delete niz[top];
			top--;
		}

	}
}
