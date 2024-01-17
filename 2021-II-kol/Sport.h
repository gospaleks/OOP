#pragma once
#include <iostream>
#include <fstream>

class Sport
{
private:
	int brojIgraca;
	int brojRezervnih;
	char obuca[25];			// dosta je 25 nmg se majem s dinamicku zonu
	float budzet;
	float koef;
	
	float vrednost;

	void KreirajObjekat(int _brojIgraca, int _brojRezervnih, const char* _obuca, float _budzet, float _koef);
public:
	Sport();
	Sport(int _brojIgraca, int _brojRezervnih, const char* _obuca, float _budzet, float _koef);
	~Sport();

	friend std::istream& operator>>(std::istream& ulaz, Sport& s);
	friend std::ostream& operator<<(std::ostream& izlaz, Sport& s);
	float operator+(float x);
	bool operator>(Sport& s);
};

