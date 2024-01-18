#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Takmicar
{
private:
	int id;
	int startniBroj;
	int rezultat;
public:
	Takmicar();
	Takmicar(int iid, int sstartniBroj, int rrezultat);
	bool operator==(int x);
	friend ostream& operator<<(ostream& izlaz, Takmicar& t);
};

