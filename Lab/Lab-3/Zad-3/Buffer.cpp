#include "Buffer.h"
#include <iostream>
#include <iomanip>
using namespace std;
Buffer::Buffer()
{
	kapacitet = 0;
	brElemenata = 0;
	niz = nullptr;
}

Buffer::Buffer(int k)
{
	this->brElemenata = 0;
	zauzmiMemoriju(k);
}

Buffer::~Buffer()
{
	obrisiMemoriju();
}


void Buffer::push(int k)
{
	if (brElemenata == 0) {
		niz[0] = new int;
		*niz[0] = k;
		++brElemenata;
	}
	else if (brElemenata < kapacitet)
	{
		int brojac = 0, i;
		for (i = 0; i < kapacitet; ++i)
		{
			if (niz[i] != nullptr)
				brojac++;
			if (brojac == brElemenata)
				break;
		}

		niz[i+1] = new int;
		*niz[i+1] = k;
		++brElemenata;
	}
}

void Buffer::pop()
{
	if (brElemenata > 0)
	{
		int i = 0;
		while (niz[i++] == nullptr);
		delete niz[i - 1];
		niz[i - 1] = nullptr;
		--brElemenata;
	}
}

void Buffer::testPop(int poz)
{
	delete niz[poz];
	niz[poz] = nullptr;
	brElemenata--;
}

void Buffer::clear()
{
	for (int i = 0; i < kapacitet; ++i)
	{
		if (niz[i] != nullptr)
			delete niz[i];
		niz[i] = nullptr;
	}
	brElemenata = 0;
}

void Buffer::obrisiMemoriju()
{
	for (int i = 0; i < kapacitet; i++)
		delete niz[i];
	delete[] niz;
	kapacitet = 0;
}

void Buffer::zauzmiMemoriju(int k)
{
	kapacitet = k;
	niz = new int*[kapacitet];
	for (int i = 0; i < kapacitet; i++)
		niz[i] = nullptr;
}

void Buffer::ispisi()
{
	int brojac = 0;
	for (int i = 0; i < kapacitet; i++)
	{
		if (niz[i] != nullptr)
		{
			cout << setw(2) << *niz[i] << " ";
			++brojac;
		}
		if (brojac == brElemenata)
			break;
	}
	cout << endl;
}

void Buffer::ispisiBafer()
{
	int brojac = 0;
	for (int i = 0; i < kapacitet; i++)
	{
		if (niz[i] == nullptr)
			cout << "_ ";
		else
			cout << *niz[i] << " ";
	}
	cout << endl;
}



