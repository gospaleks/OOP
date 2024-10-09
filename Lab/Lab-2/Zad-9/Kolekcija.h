#pragma once
#include"Picture.h"
#include<iostream>
#include<fstream>
using namespace std;

class Kolekcija
{
private:
	int maxBroj;
	int trenutniBroj;
	Picture* niz;
public:
	Kolekcija();
	Kolekcija(int maxBroj);
	~Kolekcija();
	void dodajSliku(Picture& p);
	friend ostream& operator<<(ostream& izlaz, Kolekcija& k);

	Kolekcija& operator++();
	const Kolekcija operator++(int);
};

