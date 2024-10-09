#pragma once
#include <iostream>
#include "Complex.h"
#include <fstream>
using namespace std;

template <class T>
class KvadratnaMatrica
{
	T** mat;
	int n;
public:
	KvadratnaMatrica();
	KvadratnaMatrica(int nn);
	~KvadratnaMatrica();
	KvadratnaMatrica(const KvadratnaMatrica& m);

	KvadratnaMatrica<T>& operator+(KvadratnaMatrica<T>& m);
	KvadratnaMatrica<T>& operator*(KvadratnaMatrica<T>& m);
	KvadratnaMatrica<T>& operator=(KvadratnaMatrica<T>& m);

	friend istream& operator>>(istream& ulaz, KvadratnaMatrica& m)
	{
		for (int i = 0; i < m.n; i++)
			for (int j = 0; j < m.n; j++)
				ulaz >> m.mat[i][j];
		return ulaz;
	}
	friend ostream& operator<<(ostream& izlaz, KvadratnaMatrica& m)
	{
		for (int i = 0; i < m.n; i++)
		{
			for (int j = 0; j < m.n; j++)
				izlaz << m.mat[i][j] << " ";
			izlaz << endl;
		}
		return izlaz;
	}

	void snimi(const char* imeFajla);
};

template<class T>
inline KvadratnaMatrica<T>::KvadratnaMatrica()
{
	mat = nullptr;
	n = 0;
}

template<class T>
inline KvadratnaMatrica<T>::KvadratnaMatrica(int nn)
{
	n = nn;
	mat = new T*[n];
	for (int i = 0; i < n; i++)
		mat[i] = new T[n];
}

template<class T>
inline KvadratnaMatrica<T>::~KvadratnaMatrica()
{
	if (mat != nullptr)
	{
		for (int i = 0; i < n; i++)
			delete[] mat[i];
		delete[] mat;
	}
}

template<class T>
inline KvadratnaMatrica<T>::KvadratnaMatrica(const KvadratnaMatrica& m)
{
	// mrzi me da pravim zauzmi i obrisi al treba
	for (int i = 0; i < n; i++)
		delete[] mat[i];
	delete[] mat;

	n = m.n;
	mat = new T*[n];
	for (int i = 0; i < n; i++)
		mat[i] = new T[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mat[i][j] = m.mat[i][j];
}

template<class T>
inline KvadratnaMatrica<T>& KvadratnaMatrica<T>::operator+(KvadratnaMatrica<T>& m)
{
	if(this->n != m.n)
	{ 
		throw "Nije moguce sabrati matrice";
	}
	else
	{
		KvadratnaMatrica<T> *m1 = new KvadratnaMatrica<T>(n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				m1->mat[i][j] = mat[i][j] + m.mat[i][j];
			}
		}
		return *m1;
	}
}

template<class T>
inline KvadratnaMatrica<T>& KvadratnaMatrica<T>::operator*(KvadratnaMatrica<T>& m)
{
	if (this->n != m.n)
	{
		throw "Nije moguce pomnoziti matrice";
	}
	else
	{
		KvadratnaMatrica<T> *m1 = new KvadratnaMatrica(n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				m1->mat[i][j] = T();

				for (int k = 0; k < n; k++)
				{
					m1->mat[i][j] = m1->mat[i][j] + (mat[i][k] * m.mat[k][j]);
				}
			}
		}
		return *m1;
	}
	
}

template<class T>
inline KvadratnaMatrica<T>& KvadratnaMatrica<T>::operator=(KvadratnaMatrica<T>& m)
{
	for (int i = 0; i < n; i++)
		delete[] mat[i];
	delete[] mat;
	this->n = m.n;
	mat = new T*[n];
	for (int i = 0; i < n; i++)
		mat[i] = new T[n];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mat[i][j] = m.mat[i][j];

	return *this;
}

template<class T>
inline void KvadratnaMatrica<T>::snimi(const char* imeFajla)
{
	ofstream izlaz(imeFajla);
	if (!(izlaz.good()))
	{
		throw "Fajl ne postoji";
	}
	else
	{
		izlaz << *this;
	}

}
