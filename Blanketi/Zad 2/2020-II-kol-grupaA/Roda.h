#pragma once
#include <iostream>
using namespace std;

class Roda
{
	float masa;
	float visina;
	float rasponKrila;
	float najveciBrojZaba;
public:
	Roda();
	Roda(float mmasa, float vis, float rasKr, float nbz);
	~Roda();

	bool operator>(Roda& r);
	bool operator==(Roda& r);
	Roda& operator=(Roda& r);
	float operator+(float br);

	friend istream& operator>>(istream& ulaz, Roda& r);
	friend ostream& operator<<(ostream& izlaz, Roda& r);
};

