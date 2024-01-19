#pragma once
#include <iostream>
using namespace std;

class Zaba
{
	float gustinaPega;
	float masa;
	float omiljenaVelMuve;
public:
	Zaba();
	Zaba(float ggustinaPega, float mmasa, float oomiljenaVelMuve);
	~Zaba();

	bool operator>(Zaba& z);
	bool operator==(Zaba& z);
	Zaba& operator=(Zaba& z);
	float operator+(float br);

	friend istream& operator>>(istream& ulaz, Zaba& z);
	friend ostream& operator<<(ostream& izlaz, Zaba& z);
};

