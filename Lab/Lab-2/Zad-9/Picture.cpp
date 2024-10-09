#pragma once
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
	oslobodiMem();
	n = m = 0;
}

Picture::Picture(int visina, int sirina)
{
	zauzmiMem(visina, sirina);
}

void Picture::Brihtness(int s)
{
	for (int i = 0; i < n; i++)
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

void Picture::ucitaj()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			do
			{
				cin >> mat[i][j];
			} while (mat[i][j] < 0 || mat[i][j]>512);
}

void Picture::ispisi()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

void Picture::resize(int newN, int newM)
{
	double nifactor = (double)n / (double)newN;
	double njfactor = (double)m / (double)newM;
	//pomocna matrica i zauzimanje njene memorije
	int** temp;
	temp = new int* [newN];
	for (int i = 0; i < newN; i++)
		temp[i] = new int[newM];
	//upis vrednosti u pomocnu matricu
	for (int i = 0; i < newN; i++)
		for (int j = 0; j < newM; j++)
			temp[i][j] = this->mat[((int)(floor(i * nifactor)))][((int)(floor(j * njfactor)))];
	//brisanje stare memorije
	oslobodiMem();
	//azuriranje vrednosti atributa
	n = newN;
	m = newM;
	//azuriranje pokazivaca koji ukazuje na memoriju
	mat = temp;
}

Picture::Picture(const Picture& p)
{
	zauzmiMem(p.n, p.m);
	kopiraj(p);
}

void Picture::oslobodiMem()
{
	if (mat != 0)
	{
		for (int i = 0; i < n; i++)
			delete[] mat[i];
		delete[] mat;
	}
}

void Picture::zauzmiMem(int n, int m)
{
	this->n = n;
	this->m = m;
	this->mat = new int* [n];
	for (int i = 0; i < n; i++)
		mat[i] = new int[m];
}

void Picture::kopiraj(const Picture& p)
{
	this->n = p.n;
	this->m = p.m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			this->mat[i][j] = p.mat[i][j];
}

void Picture::preklopi(Picture& p1, Picture& p2)
{
	if (p1.n != p2.n && p1.m != p2.m)
		return;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			this->mat[i][j] = (p1.mat[i][j] + p2.mat[i][j]) / 2;
}

int Picture::brojBoja()
{
	int* temp = new int[n * m];
	temp[0] = mat[0][0];
	int br = 1;
	bool imaGa;
	for(int i = 0; i<n;i++)
		for (int j = 0; j < m; j++)
		{
			imaGa = 0;
			for (int k = 0; k < br; k++)
				if (temp[k] == mat[i][j])
					imaGa = 1;
			if (!imaGa)
				temp[br++] = mat[i][j];
		}
	return br;
}

Picture& Picture::operator=(Picture& p)
{
	if (this != &p)
	{
		oslobodiMem();
		zauzmiMem(p.n, p.m);
		kopiraj(p);
	}
	return *this;
}

//prefiksno inkrementiranje
Picture& Picture::operator++()
{
	for (int i = 0; i < this->n; i++)
		for (int j = 0; j < this->m; j++)
			if (this->mat[i][j] < 512)
				this->mat[i][j]++;
	return *this;
}

//postfiksno inkrementiranje
const Picture Picture::operator++(int)
{
	Picture temp(*this);
	for (int i = 0; i < this->n; i++)
		for (int j = 0; j < this->m; j++)
			if (this->mat[i][j] < 512)
				this->mat[i][j]++;
	return temp;
}

istream& operator>>(istream& ulaz, Picture& p)
{
	for (int i = 0; i < p.n; i++)
		for (int j = 0; j < p.m; j++)
			ulaz >> p.mat[i][j];
	return ulaz;
}

ostream& operator<<(ostream& izlaz, Picture& p)
{
	for (int i = 0; i < p.n; i++)
	{
		for (int j = 0; j < p.m; j++)
			izlaz << p.mat[i][j] << " ";
		izlaz << endl;
	}
	return izlaz;
}