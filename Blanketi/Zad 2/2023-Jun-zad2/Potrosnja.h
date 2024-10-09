#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Potrosnja
{
private:
	int niza;
	int visa;
public:
	Potrosnja();
	Potrosnja(int _niza, int _visa);
	~Potrosnja();

	friend ostream& operator<<(ostream& izlaz, const Potrosnja& p);
	friend istream& operator>>(istream& ulaz, Potrosnja& p);

	bool operator==(const Potrosnja& p);
	Potrosnja operator-(const Potrosnja& p);
	int operator+(int x);
	bool operator>(const Potrosnja& p);
	bool operator<(const Potrosnja& p);
};

