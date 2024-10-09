#pragma once
#include "Skup.h"
#include <math.h>

Skup::Skup()
{
	n = 0;
	niz = nullptr;
}

Skup::Skup(int n)
{
	this->n = n;
	niz = new Complex[this->n];
}

Skup::~Skup()
{
	if (niz != nullptr)
		delete[] niz;
	n = 0;
}

void Skup::izbaciDupl()
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (niz[i] == niz[j]) {
				for (int k = i; k < n; k++)
					niz[k] = niz[k + 1];
				n--;
			}
	Skup novi(n);
	for (int i = 0; i < n; i++)
		novi.niz[i] = niz[i];
	
	delete[] niz;
	
	niz = new Complex[n];
	
	for (int i = 0; i < n; i++)
		niz[i] = novi.niz[i];
}

int Skup::ispitaj(Complex& element)
{
	for (int i = 0; i < n; i++)
		if (niz[i] == element)
			return 1;
	return 0;
}

void Skup::input()
{
	for (int i = 0; i < n; i++)
		cin >> niz[i];
}

void Skup::nerastuci()
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (niz[i] < niz[j])
				swap(niz[i], niz[j]);
}

void Skup::output()
{
	for (int i = 0; i < n; i++)
		cout << niz[i] << " ";
}

Skup::Skup(const Skup& s)
{
	this->n = s.n;
	delete[] niz;
	niz = new Complex[this->n];
	for (int i = 0; i < this->n; ++i)
		this->niz[i] = s.niz[i];
}

Skup& Skup::operator-(Skup& s)
{
	Skup* rez = new Skup(n);
	if (this->n == s.n)
	{
		for (int i = 0; i < n; i++)
			rez->niz[i] = this->niz[i] - s.niz[i];
	}
	return *rez;
}

Skup& Skup::unija(Skup& s)
{
	Skup* rez = new Skup(n+s.n);
	int i = 0;

	for (i = 0; i < n; ++i)
		rez->niz[i] = this->niz[i];

	for (int j = 0; j < s.n; ++j)
		rez->niz[i++] = s.niz[j];

	rez->izbaciDupl();
	return *rez;
}

Skup& Skup::operator=(const Skup& s)
{
	if (this != &s)
	{
		delete[] niz;
		this->n = s.n;
		niz = new Complex[this->n];
		for (int i = 0; i < n; i++)
			this->niz[i] = s.niz[i];
	}
	return *this;
}

istream& operator>>(istream& ulaz, Skup& s)
{
	for (int i = 0; i < s.n; i++)
		ulaz >> s.niz[i];
	return ulaz;
}

ostream& operator<<(ostream& izlaz, Skup& s)
{
	for (int i = 0; i < s.brojElemenata(); i++)
		izlaz << s[i] << endl;
	return izlaz;
}
