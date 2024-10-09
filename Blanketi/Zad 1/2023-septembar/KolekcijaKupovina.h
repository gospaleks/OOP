#pragma once
#include<iostream>
#include<fstream>
#include"RobaKes.h"
#define danasnjiDan 8754	//razlika dana izmdeju 1.1.2000. i 20.12.2023.
using namespace std;

class KolekcijaKupovina
{
private:
	RobaKes** niz;
	int nmax, brtr;
public:
	KolekcijaKupovina();
	KolekcijaKupovina(int nmax);
	void ubacikupovinu(RobaKes* r);
	void vratiproizvod(int kkod);
	void ispissvihprodaja();
	void vratiminmax(RobaKes* r1, RobaKes* r2);
	int vratibrojkupovina(int dan1, int dan2, int sifra);	//dan1<dan2
	float ukupnacenaprodata(int dan1, int dan2);			//dan1<dan2
	float dugovanje(int dan1);
	void ucitaj(istream& ulaz);
	void zauzmimem(int nnmax);
};

