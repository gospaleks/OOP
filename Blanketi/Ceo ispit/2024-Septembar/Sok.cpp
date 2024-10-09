#include "Sok.h"

Sok::Sok() : Pice()
{
	ukusSoka = nullptr;
	procenat = 0;
	odnosCene = 0;
}

Sok::Sok(float zapremina, char* ukusSoka, int procenat, float odnosCene)
	: Pice(zapremina, 1)
{
	this->ukusSoka = new char[strlen(ukusSoka) + 1];
	strcpy(this->ukusSoka, ukusSoka);
	this->procenat = procenat;
	this->odnosCene = odnosCene;
}

Sok::~Sok()
{
	if (ukusSoka)
		delete[] ukusSoka;
}

void Sok::Prikazi(ostream& izlaz)
{
	izlaz << "Sok:\n";
	Pice::Prikazi(izlaz);
	izlaz << "Ukus soka: " << ukusSoka << "\nProcenat: " << procenat << "\nOdnos cene: " << odnosCene << endl;
}

bool Sok::operator==(Pice& p)
{
	return this->zapremina == p.getZapremina() &&
		strcmp(this->ukusSoka, p.getUkusSoka()) == 0 &&
		this->procenat == p.getProcenat() &&
		this->odnosCene == p.getOdnosCene();
}

float Sok::cena()
{
	float litriVodeUSoku = ((100 - procenat) / 100.0f) * zapremina;

	float x = (litriVodeUSoku * 100) / (odnosCene * 100);

	return x * brAmbalaza;
}

