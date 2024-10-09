#pragma once
#include<fstream>
using namespace std;

class Gledalac
{
protected:
	char ime[20];
	char prezime[20];
	int starost;
	float ocena;
	bool prisutan;
public:
	Gledalac();
	Gledalac(char*, char*, int, float, bool);
	~Gledalac();
	float getOcena() { return ocena; }
	int getStarost() {return starost; }
	bool getPrisutan() { return prisutan; }
	friend istream& operator>>(istream& ulaz, Gledalac& g);
	friend ostream& operator<<(ostream& izlaz, Gledalac& g);
};

