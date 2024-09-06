#pragma once
#include <string.h>
#include <iostream>

using std::endl;

class NovcanicaValuta
{
private:
	char kodValute[4];
	int vrednost;
	float kurs;

public:
	NovcanicaValuta();
	NovcanicaValuta(const char* _kodValute, int _vrednost, float _kurs);
	~NovcanicaValuta();

	NovcanicaValuta(const NovcanicaValuta& n);
	NovcanicaValuta& operator=(const NovcanicaValuta& n);

	bool operator<=(NovcanicaValuta& n);
	bool operator==(NovcanicaValuta& n);

	float operator+(float desno);

	friend std::ostream& operator<<(std::ostream& izlaz, const NovcanicaValuta& n);
	friend std::istream& operator>>(std::istream& ulaz, NovcanicaValuta& n);
};

