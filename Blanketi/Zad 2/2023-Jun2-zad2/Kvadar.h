#pragma once
#include <fstream>
#include <iostream>
using namespace std;
class Kvadar
{
private:
	float duzina;
	float visina;
	float sirina;
	float gustina;

	float getMasa();
public:
	Kvadar();
	Kvadar(float d, float v, float s, float g);
	~Kvadar() { }

	friend ostream& operator<<(ostream& izlaz, Kvadar& k);
	friend istream& operator>>(istream& ulaz, Kvadar& k);
	bool operator>(Kvadar& k);
	float operator+(float r);
};

