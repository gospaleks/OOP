#include "DekadniMatricniDisplej.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

DekadniMatricniDisplej::DekadniMatricniDisplej()
{
	n = m = 0;
	for (int i = 0; i < 7; i++)
		niz[i] = 1;
	ofstream izlaz("izlaz.txt");
	izlaz.close();
}

DekadniMatricniDisplej::DekadniMatricniDisplej(int ccifra)
	:Displej(ccifra) {
	n = 5;
	m = 3;
	zauzmiMem(n, m);
	for (int i = 0; i < 7; i++)
		niz[i] = 1;
	set(cifra);
	ofstream izlaz("izlaz.txt");
	izlaz.close();
}

DekadniMatricniDisplej::~DekadniMatricniDisplej()
{
	for (int i = 0; i < n; i++)
		delete[] mat[i];
	delete[] mat;
}

void DekadniMatricniDisplej::ucitajCifru(istream& ulaz)
{
	ulaz >> n >> m;
	zauzmiMem(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ulaz >> mat[i][j];

	for (int i = 0; i < m; i++)
	{
		niz[0] &= mat[0][i];
		niz[6] &= mat[n / 2][i];
		niz[3] &= mat[n-1][i];
	}
	for (int i = 0; i <= n / 2; i++)
	{
		niz[1] &= mat[i][m - 1];
		niz[5] &= mat[i][0];
	}
	for (int i = n / 2; i < n; i++)
	{
		niz[2] &= mat[i][m - 1];
		niz[4] &= mat[i][0];
	}
	detektuj();
}

void DekadniMatricniDisplej::detektuj()
{
	string s = "";
	for (int i = 0; i < 7; ++i)
		if (niz[i])
			s += '1';
		else 
			s += '0';
	
	if (s == "1111110") cifra = 0;
	else if (s == "0110000") cifra = 1;
	else if (s == "1101101") cifra = 2;
	else if (s == "1111001") cifra = 3;
	else if (s == "0110011") cifra = 4;
	else if (s == "1011011") cifra = 5;
	else if (s == "1011111") cifra = 6;
	else if (s == "1110000") cifra = 7;
	else if (s == "1111111") cifra = 8;
	else if (s == "1111011") cifra = 9;
	else cifra = 0;
}

void DekadniMatricniDisplej::zauzmiMem(int nn, int mm)
{
	n = nn;
	m = mm;
	mat = new bool* [n];
	for (int i = 0; i < n; i++)
		mat[i] = new bool[m];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			mat[i][j] = 0;
}

void DekadniMatricniDisplej::set(int ccifra)
{
	if (ccifra >= 0 && ccifra <= 9)
		cifra = ccifra;
	else
		cifra = 0;
	ispisiNaDisplej();
}

void DekadniMatricniDisplej::ispisiNaDisplej()
{
	string s = "";
	if (cifra == 0) s = "1111110";
	else if (cifra == 1) s = "0110000";
	else if (cifra == 2) s = "1101101";
	else if (cifra == 3) s = "1111001";
	else if (cifra == 4) s = "0110011";
	else if (cifra == 5) s = "1011011";
	else if (cifra == 6) s = "1011111";
	else if (cifra == 7) s = "1110000";
	else if (cifra == 8) s = "1111111";
	else if (cifra == 9) s = "1111011";

	for (int i = 0; i < 7; ++i)
		if (s[i] == '1') niz[i] = 1;
		else niz[i] = 0;

	for (int i = 0; i < m; i++)
	{
		mat[0][i] = niz[0];
		mat[n / 2][i] = niz[6];
		mat[n - 1][i] = niz[3];
	}
	for (int i = 1; i < n / 2; i++)
	{
		mat[i][m - 1] = niz[1];
		mat[i][0] = niz[5];
	}
	for (int i = n / 2 + 1; i < n - 1; i++)
	{
		mat[i][m - 1] = niz[2];
		mat[i][0] = niz[4];
	}

	//ofstream izlaz("izlaz.txt");
	//ispisiNa(izlaz);
	//izlaz.close();

	//MNOGO JE SPORO OVO GORE
}

void DekadniMatricniDisplej::ispisiNa(ostream& izlaz)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			izlaz << mat[i][j] << " ";
		izlaz << endl;
	}
	izlaz << "----------------------" << endl;
}

void DekadniMatricniDisplej::show()
{
	Displej::show();
	ispisiNa(cout);
	ofstream izlaz;
	izlaz.open("izlaz.txt", ios_base::app);
	ispisiNa(izlaz);
	izlaz.close();
}

void DekadniMatricniDisplej::inc()
{
	cifra++;
	cifra = cifra % 10;
	ispisiNaDisplej();
}