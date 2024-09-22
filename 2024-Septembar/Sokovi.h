#pragma once
#include <string.h>
#include <iostream>
using namespace std;

class Sokovi
{
private:
	char* nazivVoca;
	float zapremina;
	int procenatVoca;

	void zauzmiMem(const char* nazivVoca, float zapremina, int procenatVoca);
	void oslobodiMem();

public:
	Sokovi();
	Sokovi(const char* nazivVoca, float zapremina, int procenatVoca);
	Sokovi(const Sokovi& s);
	~Sokovi();

	Sokovi& operator=(const Sokovi& s);

	friend ostream& operator<<(ostream& izlaz, Sokovi& s);
	friend istream& operator>>(istream& ulaz, Sokovi& s);

	bool operator<(const Sokovi& s);
	bool operator!=(const Sokovi& s);
	bool operator==(const Sokovi& s);
	float operator+(float desni);
	float operator*(int desni);
};

