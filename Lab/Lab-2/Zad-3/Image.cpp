#include "Image.h"
#include <iostream>
using namespace std;

Image::Image()
{
	n = 0;
	mat = nullptr;
	lokacija = nullptr;
}

Image::Image(int duzina)
{
	zauzmiMemoriju(duzina);
	lokacija = nullptr;
}

Image::~Image()
{
	oslobodiMemoriju();
}

Image::Image(const Image& mat)
{
	zauzmiMemoriju(mat.n);
	kopiraj(mat);
}

void Image::invertuj()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (mat[i][j] == 0)
				mat[i][j] = 1;
			else
				mat[i][j] = 0;
		}
}

void Image::ucitaj()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mat[i][j];
}

void Image::ispisi()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
}

void Image::odsecanje(int novaDimenzija)
{

	int** pomMat;
	pomMat = new int* [novaDimenzija];
	for (int i = 0; i < novaDimenzija; ++i)
		pomMat[i] = new int[novaDimenzija];

	for (int i = 0; i < novaDimenzija; i++)
		for (int j = 0; j < novaDimenzija; j++)
			pomMat[i][j] = this->mat[i][j];


	for (int i = 0; i < n; i++)
		delete[] mat[i];
	delete[] mat;

	n = novaDimenzija;
	mat = pomMat;
}

Image& Image::preklopi(Image& img2)
{
	Image* i3 = new Image(n);
	if (img2.n == n)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (mat[i][j] == 1 || img2.mat[i][j] == 1)
					i3->mat[i][j] = 1;
				else
					i3->mat[i][j] = 0;
			}
	}
	return *i3;
}

void Image::rotiraj()
{
	int** transp;
	transp = new int* [n];
	for (int i = 0; i < n; ++i)
		transp[i] = new int[n];

	// transponuj
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			transp[i][j] = this->mat[j][i];

	// okreni u ogledalo
	for (int j = 0; j < n / 2; ++j)
		for (int i = 0; i < n; ++i)
			swap(transp[i][j], transp[i][n-j-1]);

	// vrati u this
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			this->mat[i][j] = transp[i][j];
	
	// oslobodi mem za transp
	for (int i = 0; i < n; ++i)
		delete[] transp[i];
	delete [] transp;
}

// OPERATORSKE FUNKCIJE
Image& Image::operator=(const Image& img)
{
	if (this != &img)
	{
		oslobodiMemoriju();
		zauzmiMemoriju(img.n);
		kopiraj(img);
	}
	return *this;
}

ostream& operator<<(ostream& izlaz, Image& img)
{
	for (int i = 0; i < img.n; i++)
	{
		for (int j = 0; j < img.n; j++)
			izlaz << img.mat[i][j] << " ";
		izlaz << endl;
	}
	return izlaz;
}

istream& operator>>(istream& ulaz, Image& img)
{
	for (int i = 0; i < img.n; i++)
		for (int j = 0; j < img.n; j++)
			ulaz >> img.mat[i][j];
	return ulaz;
}

// POMOCNE - REDUKUJEMO DUPLIRANJE KODA!
void Image::oslobodiMemoriju()
{
	if (mat != 0)
	{
		for (int i = 0; i < n; i++)
			delete[] mat[i];
		delete mat;
	}
	n = 0;
}

void Image::zauzmiMemoriju(int dimenzija)
{
	this->n = dimenzija;
	mat = new int* [n];
	for (int i = 0; i < n; i++)
		mat[i] = new int[n];
}

void Image::kopiraj(const Image& img)
{
	this->n = img.n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mat[i][j] = img.mat[i][j];
}