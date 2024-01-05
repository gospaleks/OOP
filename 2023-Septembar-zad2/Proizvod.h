#pragma once
#include <fstream>

class Proizvod
{
private:
	char* naziv;
	int brojMeseciDoIsteka;
	float cena;
	float koef;
public:
	Proizvod();
	Proizvod(const char* _naziv, int _brojMeseci, float _cena, float _koef);
	~Proizvod();

	friend std::ostream& operator<<(std::ostream& izlaz, Proizvod& p);
	friend std::istream& operator>>(std::istream& ulaz, Proizvod& p);

	float operator+(float x);
};

