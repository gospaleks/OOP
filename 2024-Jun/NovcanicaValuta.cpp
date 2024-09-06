#include "NovcanicaValuta.h"

NovcanicaValuta::NovcanicaValuta()
{
	strcpy(kodValute, "DIN");
	vrednost = 0;
	kurs = 1;
}

NovcanicaValuta::NovcanicaValuta(const char* _kodValute, int _vrednost, float _kurs)
{
	strcpy(kodValute, _kodValute);
	vrednost = _vrednost;
	kurs = _kurs;
}

NovcanicaValuta::~NovcanicaValuta()
{
}

NovcanicaValuta::NovcanicaValuta(const NovcanicaValuta& n)
{
	strcpy(kodValute, n.kodValute);
	vrednost = n.vrednost;
	kurs = n.kurs;
}

NovcanicaValuta& NovcanicaValuta::operator=(const NovcanicaValuta& n)
{
	if (this != &n) {
		strcpy(kodValute, n.kodValute);
		vrednost = n.vrednost;
		kurs = n.kurs;
	}

	return *this;
}

bool NovcanicaValuta::operator<=(NovcanicaValuta& n)
{
	return strcmp(kodValute, n.kodValute) == 0 && (vrednost * kurs) <= (n.vrednost * n.kurs);
}

bool NovcanicaValuta::operator==(NovcanicaValuta& n)
{
	return strcmp(kodValute, n.kodValute) == 0 && (vrednost * kurs) == (n.vrednost * n.kurs);
}

float NovcanicaValuta::operator+(float desno)
{	
	return (vrednost * kurs) + desno;
}

std::ostream& operator<<(std::ostream& izlaz, const NovcanicaValuta& n)
{
	return izlaz << n.kodValute << " " << n.vrednost << " " << n.kurs;
}

std::istream& operator>>(std::istream& ulaz, NovcanicaValuta& n)
{
	return ulaz >> n.kodValute >> n.vrednost >> n.kurs;
}
