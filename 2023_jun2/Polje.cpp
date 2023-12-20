#include "Polje.h"
#include"Entitet.h"
#include"Osa.h"
#include"Pcela.h"
#include<math.h>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

Polje::Polje()
{
	n = m = 0;
	mat = nullptr;
}

Polje::Polje(int nn, int mm)
{
	zauzmiMem(nn, mm);
}

Polje::~Polje()
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (mat[i][j] != nullptr)
				delete mat[i][j];

	for (int i = 0; i < n; ++i)
		delete [] mat[i];

	delete[] mat;

}

bool Polje::daLiPripada(int i, int j)
{
	if (i<0 || i > n - 1)
		return false;
	if (j<0 || j > m - 1)
		return false;
}

void Polje::ucitaj(istream& ulaz)
{
	char ttip;
	ulaz >> n >> m;
	zauzmiMem(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			ulaz >> ttip;
			if (ttip == 'o')
				postavi(i, j, new Osa(this, i, j));
			else if (ttip == 'p')
				postavi(i, j, new Pcela(this, i, j));
		}		
}

void Polje::zauzmiMem(int nn, int mm)
{
	n = nn;
	m = mm;
	mat = new Entitet **[n];
	for (int i = 0; i < n; i++)
	{
		mat[i] = new Entitet *[m];
		for (int j = 0; j < m; j++)
			mat[i][j] = nullptr;
	}
}

void Polje::postavi(int ii, int jj, Entitet* e)
{
	mat[ii][jj] = e;
}

void Polje::prikazi()
{
	cout << "tabla sa zankovima" << endl;
	for (int i = 0; i < n; i++)
	{		for (int j = 0; j < m; j++)
			if (mat[i][j] == nullptr)
				cout << "\tx ";
			else
				cout <<"\t" << mat[i][j]->getTip() << "(" << mat[i][j]->getEnergija() << ") ";
		cout << endl;
	}
}

void Polje::brisi(int i, int j)
{
	delete mat[i][j];
	mat[i][j] = nullptr;
}

void Polje::sviDobro()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (mat[i][j] != nullptr)
				mat[i][j]->dobro();
}

void Polje::sviLose()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (mat[i][j] != nullptr)
				mat[i][j]->lose();
}
