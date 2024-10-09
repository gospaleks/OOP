#pragma once
#include<iostream>
#include<fstream>
#include"Complex.h"
using namespace std;

class Skup
{
private:
	int n;
	Complex* niz;
public:
	Skup();
	Skup(int n);
	~Skup();
	inline int brojElemenata() { return n; };
	void izbaciDupl();
	int ispitaj(Complex& element);
	void input();
	void nerastuci();
	void output();

	Skup(const Skup& s);

	Skup& operator-(Skup& s);
	Skup& unija(Skup& s);
	Skup& presek(Skup& s);
	friend istream& operator>>(istream& ulaz, Skup& s);
	friend ostream& operator<<(ostream& izlaz, Skup& s);
	Complex& operator[](int k) { return niz[k]; }
	Skup& operator=(const Skup& s);
};

