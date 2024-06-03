#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Ispit
{
private:
	char* naziv;
	int ocena;
	int espb;
	void zauzmiMem(const char* naziv, int ocena, int espb);

public:
	Ispit();
	Ispit(const char* naziv, int ocena, int espb);
	~Ispit();
	Ispit(const Ispit& i);
	friend ostream& operator<<(ostream& izlaz, Ispit& i);
	friend istream& operator>>(istream& ulaz, Ispit& i);
	float operator+(float leviOp);
	Ispit& operator=(const Ispit& i);
	bool operator>(Ispit& s);
};

