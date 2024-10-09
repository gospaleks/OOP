#include "Minesweeper.h"
#include <iostream>
#include <string.h>
using namespace std;

Minesweeper::Minesweeper()
{
	zauzmiMemoriju(10, 10);
	nazivPolja = nullptr;
}

Minesweeper::Minesweeper(int nn, int mm)
{
	zauzmiMemoriju(nn, mm);
	nazivPolja = nullptr;
}

Minesweeper::Minesweeper(Minesweeper& obj)
{
	zauzmiMemoriju(obj.n, obj.m);
	kopiraj(obj);
}

Minesweeper::~Minesweeper()
{
	oslobodiMemoriju();
}


int Minesweeper::vratiBrmina(int r, int k)
{
	if (matrica[r][k] == true)
		return -1;

	int brm = 0;
	int prsten = 2;
	for (int j = k - prsten; j <= k + prsten; ++j) {
		if (j >= 0 && r - prsten >= 0 && matrica[r - prsten][j] == true) 
			++brm;
		if (j >= 0 && r + prsten < n && matrica[r + prsten][j] == true) 
			++brm;
	}

	for (int i = r - prsten + 1; i <= r + prsten - 1; ++i) {
		if (i >= 0 && k - prsten >= 0 && matrica[i][k - prsten] == true) 
			++brm;
		if (i >= 0 && k + prsten < m && matrica[i][k + prsten] == true) 
			++brm;
	}

	//int pored[] = { -1, -1, -1,  1, 1, 1,  0, 0 };
	//int pokol[] = { -1,  0,  1, -1, 0, 1, -1, 1 };

	//for (int i = 0; i < 8; ++i) {
	//	int red = r + pored[i];
	//	int kol = k + pokol[i];
	//	if (!(red < 0 || red >= n || kol < 0 || kol >= m) && matrica[red][kol] == true)
	//		++brm;
	//}

	return brm;
}

void Minesweeper::ucitajRaspored()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x; cin >> x;
			if (x == 0) matrica[i][j] = false;
			else matrica[i][j] = true;
		}
	}
}

void Minesweeper::prikazi()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrica[i][j] == true) 
				cout << "1" << " ";
			else 
				cout << "0" << " ";

		}
		cout << endl;
	}
}

void Minesweeper::izbaci()
{
	// IZBACUJE REDOVE
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 1; j < m; ++j)
			if (matrica[i][j] != matrica[i][j - 1])
				break;

		if (j == m && matrica[i][j - 1] == false) // naso red sa sve 0 
		{
			bool** pomMat;
			pomMat = new bool* [n - 1];
			for (int i = 0; i < n - 1; ++i)
				pomMat[i] = new bool[m];


			// kopiraj u pomMat bez praznog reda
			int brRed = 0;
			for (int k = 0; k < n; ++k, brRed++) {
				for (int t = 0; t < m; ++t) {
					if (k == i) {
						brRed--;
						break;
					}
					else
						pomMat[brRed][t] = matrica[k][t];
				}
			}

			// brisi staro
			for (int i = 0; i < n; i++)
				delete[] matrica[i];
			delete[] matrica;

			matrica = pomMat;
			n--;

			--i;
		}
	}

	//	IZBACUJE KOLONE 
	for (j = 0; j < m; ++j) {
		for (i = 1; i < n; ++i)
			if (matrica[i][j] != matrica[i - 1][j])
				break;

		if (i == n && matrica[i - 1][j] == false) // naso kolonu sa sve 0 
		{
			bool** pomMat;
			pomMat = new bool* [n];
			for (int i = 0; i < n; ++i)
				pomMat[i] = new bool[m - 1];

			int brKol = 0;
			for (int t = 0; t < m; ++t, brKol++) {
				for (int k = 0; k < n; ++k) {
					if (t == j) {
						brKol--;
						break;
					}
					else
						pomMat[k][brKol] = matrica[k][t];
				}
			}

			// oslobodi
			for (int i = 0; i < n; i++)
				delete[] matrica[i];
			delete[] matrica;

			// samo pokazivaci capni
			matrica = pomMat;
			m--;

			--j;
		}
	}
}


// ZA LAB2
void Minesweeper::rotDesno()
{
	for (int i = 0; i < n; ++i) {
		bool pom = matrica[i][m-1];
		for (int j = m - 1; j > 0; --j)
			matrica[i][j] = matrica[i][j - 1];
		matrica[i][0] = pom;
	}
}

void Minesweeper::rotLevo()
{
	for (int i = 0; i < n; ++i) {
		bool pom = matrica[i][0];
		for (int j = 0; j < m-1; ++j)
			matrica[i][j] = matrica[i][j + 1];
		matrica[i][m-1] = pom;
	}
}

void Minesweeper::rotGore()
{
	for (int j = 0; j < m; ++j) {
		bool pom = matrica[0][j];
		for (int i = 0; i < n - 1; ++i)
			matrica[i][j] = matrica[i+1][j];
		matrica[n-1][j] = pom;
	}
}

void Minesweeper::rotDole()
{
	for (int j = 0; j < m; ++j) {
		bool pom = matrica[n-1][j];
		for (int i = n-1; i > 0; --i)
			matrica[i][j] = matrica[i - 1][j];
		matrica[0][j] = pom;
	}
}

void Minesweeper::zameniNtoPolje(int nn)
{
	int brPraznih = 0;
	for (int i = 0; i < n && brPraznih != nn; ++i) {
		for (int j = 0; j < m && brPraznih != nn; ++j)
		{
			if (matrica[i][j] == false)
				++brPraznih;
			if (brPraznih == nn)
				matrica[i][j] = true;
		}
	}
}

istream& operator>>(istream& ulaz, Minesweeper& m)
{
	for (int i = 0; i < m.vratiN(); ++i)
		for (int j = 0; j < m.vratiM(); ++j)
			ulaz >> m.matrica[i][j];
	return ulaz;
}

ostream& operator<<(ostream& izlaz, Minesweeper& m)
{
	// izlaz << m.nazivPolja << endl;
	for (int i = 0; i < m.vratiN(); ++i) {
		for (int j = 0; j < m.vratiM(); ++j)
			izlaz << m.matrica[i][j] << " ";
		izlaz << endl;
	}
	izlaz << endl;
	return izlaz;
}


// POMOCNE FUNKCIJE ZA REDUKOVANJE DUPLIRANJA KODA
void Minesweeper::oslobodiMemoriju()
{
	for (int i = 0; i < n; i++)
		delete[] matrica[i];
	delete[] matrica;
	delete[] nazivPolja;
}

void Minesweeper::zauzmiMemoriju(int nn, int mm)
{
	n = nn;
	m = mm;
	matrica = new bool* [n];
	for (int i = 0; i < n; i++)
		matrica[i] = new bool[m];
	nazivPolja = nullptr;
}

void Minesweeper::kopiraj(Minesweeper& obj)
{
	n = obj.n;
	m = obj.m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			this->matrica[i][j] = obj.matrica[i][j];
	// strcpy(nazivPolja, obj.nazivPolja);
}

