#pragma once
#include <iostream>
#include <fstream>
#include "Roda.h"
#include "Zaba.h"

using namespace std;

template <class T>
class Niz
{
	T* niz;
	int top;
	int maxEl;
public:
	Niz();
	Niz(int mmaxEl);
	~Niz();
	void dodaj(T& e);
	void izbaci(int br);
	void ucitaj(istream& ulaz);
	void ispisi(ostream& izlaz);
	float ukupnaMasa();
};

template<class T>
inline Niz<T>::Niz()
{
	niz = nullptr;
	top = 0;
	maxEl = 0;
}

template<class T>
inline Niz<T>::Niz(int mmaxEl)
{
	maxEl = mmaxEl;
	niz = new T[maxEl];
	top = 0;
}

template<class T>
inline Niz<T>::~Niz()
{
	if (niz != nullptr)
		delete[] niz;
}

template<class T>
inline void Niz<T>::dodaj(T& e)
{
	if (top == maxEl)
		throw "Niz je pun";
	for (int i = 0; i < top; i++)
		if (niz[i] == e)
			throw "Element vec postoji";

	if (top == 0)
	{
		niz[top++] = e;
		return;
	}
	else
	for (int i = 0; i < top; i++)
	{
		if (niz[i] > e)
		{
			int k = i; // na to mesto treba da se stavi
			for (int j = top; j > i; j--)
				niz[j] = niz[j - 1];
			top++;
			niz[k] = e;
			return;
		}
		
	}
	niz[top++] = e;
}

template<class T>
inline void Niz<T>::izbaci(int br)
{
	if (br > top || br < 1)
		throw "Taj element ne postoji";
	else
	{
		int indeks = br - 1;
		for (int i = indeks; i < top - 1; i++)
			niz[i] = niz[i + 1];
		top--;
	}
}

template<class T>
inline void Niz<T>::ucitaj(istream& ulaz)
{
	int n;
	ulaz >> n;
	
	for (int i = 0; i < n; i++)
	{
		T* pom = new T();
		ulaz >> *pom;
		this->dodaj(*pom);
	}
}

template<class T>
inline void Niz<T>::ispisi(ostream& izlaz)
{
	for (int i = 0; i < top; i++)
		izlaz << niz[i] << endl;
}

template<class T>
inline float Niz<T>::ukupnaMasa()
{
	float rez = 0;
	for (int i = 0; i < top; i++)
	{
		rez = niz[i] + rez;
	}
	return rez;
}

