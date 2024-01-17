#pragma once
#include <iostream>
#include <fstream>

class Sport
{
private:
	int brojIgraca;
	int brojRezervnih;
	char* obuca;
	float budzet;
	float koef;
	
	float vrednost;

	void KreirajObjekat(int _brojIgraca, int _brojRezervnih, const char* _obuca, float _budzet, float _koef);
public:
	Sport();
	Sport(int _brojIgraca, int _brojRezervnih, const char* _obuca, float _budzet, float _koef);
	~Sport();

	Sport(const Sport& s);

	Sport& operator=(const Sport& s);

	friend std::istream& operator>>(std::istream& ulaz, Sport& s);
	friend std::ostream& operator<<(std::ostream& izlaz, Sport& s);
	float operator+(float x);
	bool operator>(Sport& s);


};

