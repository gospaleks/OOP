#pragma once
#include "Student.h"
#include <iostream>
using namespace std;

template <class T>
class Skup
{
	T* niz;
	int maxEl;
	int top;
public:
	Skup();
	Skup(int mmaxEl);
	~Skup();
	void dodaj(T& e);
	void sortiraj(int k); // ako se unese 1 rastuce, ako se unese 2 opadajuce
	Skup<T> operator*(Skup<T>& s1);
	Skup<T>& operator=(const Skup<T>& s);

	friend istream& operator>>(istream& ulaz, Skup& s)
	{
		int n;
		ulaz >> n;
		for(int i = 0; i < n; i ++)
		{
			T pom = T();
			ulaz >> pom;
			s.dodaj(pom);
		}
		return ulaz;
	}
	friend ostream& operator<<(ostream& izlaz, Skup& s)
	{
		for (int i = 0; i < s.top; i++)
			izlaz << s.niz[i] << endl;
		return izlaz;
	}

};

template<class T>
inline Skup<T>::Skup()
{
	niz = nullptr;
	maxEl = 0;
	top = 0;
}

template<class T>
inline Skup<T>::Skup(int mmaxEl)
{
	maxEl = mmaxEl;
	niz = new T[maxEl];
/*	for (int i = 0; i < maxEl; i++)
		niz[i] = T();*/
	top = 0;
}

template<class T>
inline Skup<T>::~Skup()
{
	if (niz != nullptr)
		delete[] niz;
}

template<class T>
inline void Skup<T>::dodaj(T& e)
{
	if (top == maxEl)
		throw "Element se ne moze dodati";
	else
		niz[top++] = e;
}

template<class T>
inline void Skup<T>::sortiraj(int k)
{
	T pom = T();
	if (k == 1)
	{
		for (int i = 0; i < top - 1; i++)
		{
			for (int j = i; j < top; j++)
			{
				if (niz[i] > niz[j])
				{
					pom = niz[i];
					niz[i] = niz[j];
					niz[j] = pom;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < top - 1; i++)
		{
			for (int j = i; j < top; j++)
			{
				if (niz[i] < niz[j])
				{
					pom = niz[i];
					niz[i] = niz[j];
					niz[j] = pom;
				}
			}
		}
	}
}

template<class T>
inline Skup<T> Skup<T>::operator*(Skup<T>& s1)
{
	Skup<T> s2(min(top, s1.top) + 1);
	for (int i = 0; i < top; i++)
	{
		for (int j = 0; j < s1.top; j++)
		{
			if (niz[i] == s1.niz[j])
			{
				s2.dodaj(niz[i]);
				break;
			}
				
		}

	}

	return s2;
}

template<class T>
inline Skup<T>& Skup<T>::operator=(const Skup<T>& s)
{
	if (this != &s) {
		if (niz != nullptr)
			delete[] niz;
		maxEl = s.maxEl;
		niz = new T[maxEl];
		top = 0;
		for (int i = 0; i < s.top; ++i)
			dodaj(s.niz[i]);
	}

	return *this;
}




