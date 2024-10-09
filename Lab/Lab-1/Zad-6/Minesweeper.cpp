#include "Minesweeper.h"
#include <iostream>
#include <string.h>
using namespace std;

Minesweeper::Minesweeper()
{
	n = 10;
	m = 10;
	matrica = new bool* [n];
	for (int i = 0; i < n; i++)
		matrica[i] = new bool[m];

	nazivPolja = nullptr;
}

Minesweeper::Minesweeper(int nn, int mm)
{
	this->n = nn;
	this->m = mm;
	matrica = new bool* [n];
	for (int i = 0; i < n; i++)
		matrica[i] = new bool[m];

	nazivPolja = nullptr;
}

Minesweeper::~Minesweeper()
{
	for (int i = 0; i < n; i++)
		delete[] matrica[i];
	delete[] matrica;
}


int Minesweeper::vratiBrmina(int r, int k)
{
	if (matrica[r][k] == true) 
		return -1;

	int brm = 0;
	
	int pored[] = { -1, -1, -1,  1, 1, 1,  0, 0 };
	int pokol[] = { -1,  0,  1, -1, 0, 1, -1, 1 };

	for (int i = 0; i < 8; ++i) {
		int red = r + pored[i];
		int kol = k + pokol[i];
		if (!(red < 0 || red >= n || kol < 0 || kol >= m) && matrica[red][kol] == true)
			++brm;
	}

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
			if (matrica[i][j] == true) cout << "1" << " ";
			else cout << "0" << " ";

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
				pomMat[i] = new bool[m-1];

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