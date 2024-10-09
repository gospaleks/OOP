#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class CD
{
private:
	float velicina;
	float zauzetProstor;
	float slobodanProstor;
public:
	CD();
	CD(float v, float zP, float sP);

	bool operator==(CD& c);
	bool operator>(CD& c);

	friend ostream& operator<<(ostream& izlaz, const CD& c);
	friend istream& operator>>(istream& ulaz, CD& c);
};

