#include "Picture.h"
#include<iostream>
#include<math.h>
using namespace std;

Picture::Picture()
{
	n = m = 0;
	mat = nullptr;
}

Picture::~Picture()
{
	for (int i = 0; i < n; i++)
		delete[] mat[i];
	delete[] mat;
	n = m = 0;
}

Picture::Picture(int visina, int sirina)
{
	n = visina;
	m = sirina;
	mat = new int* [n];
	for (int i = 0; i < n; i++)
		mat[i] = new int[m];
}

void Picture::Brihtness(int s)
{
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (mat[i][j] + s >= 0 && mat[i][j] + s <= 512) {
				mat[i][j] += s;
			}
			else {
				if (s < 0)
					mat[i][j] = 0;
				else
					mat[i][j] = 512;
			}
		}
}
// pisemo komentar ide ide gas

void Picture::ucitaj()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mat[i][j];
}

void Picture::ispisi()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
}

void Picture::resize(int newN, int newM)
{
	// ovo tu mi mnogo sumnjivo (proveriti!!!)
	// PS: mislim da u neku od sledece vezbe ima dobro odradjeno
	// to je prosirivanje memorije koje se stalno pada na kol/ispit
	double nifactor = (double)n / (double)newN;
	double njfactor = (double)m / (double)newM;

	int** pomMat;
	pomMat = new int* [newN];
	for (int i = 0; i < newN; ++i)
		pomMat[i] = new int[newM];

	for (int i = 0; i < newN; i++)
		for (int j = 0; j < newM; j++)
			pomMat[i][j] = this->mat[((int)(floor(i * nifactor)))][((int)(floor(j * njfactor)))];
	
	for (int i = 0; i < n; i++)
		delete[] mat[i];
	delete[] mat;

	n = newN;
	m = newM;
	mat = pomMat;
}


