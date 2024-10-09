#pragma once
#include <fstream>
#include <iostream>
using namespace std;

class ProsireniPodatak
{
private:
	float T;
	float E;
	float V;

public:
	ProsireniPodatak();
	ProsireniPodatak(float _T, float _E, float _V);
	~ProsireniPodatak();

	float getOsecaj();

	friend ostream& operator<<(ostream& izlaz, ProsireniPodatak& p);
	friend istream& operator>>(istream& ulaz, ProsireniPodatak& p);
	bool operator>(ProsireniPodatak& p);

	float operator+(float x);
};

