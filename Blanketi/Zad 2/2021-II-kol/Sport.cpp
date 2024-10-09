#include "Sport.h"
#include <string.h>

void Sport::KreirajObjekat(int _brojIgraca, int _brojRezervnih, const char* _obuca, float _budzet, float _koef)
{
	if (_brojIgraca > 20)
		throw "Maksimalan broj igraca je 20.";
	brojIgraca = _brojIgraca;

	if (_brojRezervnih > 10)
		throw "Maksimalan broj rezervnih igraca je 10.";
	brojRezervnih = _brojRezervnih;

	obuca = new char[strlen(_obuca) + 1];
	strcpy(obuca, _obuca);

	if (_koef < 0 || _koef > 1)
		throw "Koeficijent popularnosti mora imati vrednost izmedju 0 i 1.";
	koef = _koef;

	if (_budzet > 50000)
		throw "Maksimalan budzet tima je 50 000.";
	budzet = _budzet;

	vrednost = (brojIgraca + brojRezervnih) * budzet * koef;
}

Sport::Sport()
{
	brojIgraca = brojRezervnih = 0;
	obuca = nullptr;
	budzet = koef = 0;

	vrednost = 0;
}

Sport::Sport(int _brojIgraca, int _brojRezervnih, const char* _obuca, float _budzet, float _koef)
{
	KreirajObjekat(_brojIgraca, _brojRezervnih, _obuca, _budzet, _koef);
}

Sport::~Sport()
{
	if (obuca != nullptr)
		delete [] obuca;
}

Sport::Sport(const Sport& s)
{
	if (obuca != nullptr)
		delete [] obuca;
	KreirajObjekat(s.brojIgraca, s.brojRezervnih, s.obuca, s.budzet, s.koef);
}

Sport& Sport::operator=(const Sport& s)
{
	if (this != &s) {
		if (obuca != nullptr)
			delete obuca;
		KreirajObjekat(s.brojIgraca, s.brojRezervnih, s.obuca, s.budzet, s.koef);
	}

	return *this;
}

float Sport::operator+(float x)
{
	return (vrednost + x);
}

bool Sport::operator>(Sport& s)
{
	return (this->vrednost > s.vrednost);
}

std::istream& operator>>(std::istream& ulaz, Sport& s)
{
	int br;
	int brr;
	char o[50];
	float b;
	float k;
	ulaz >> br >> brr >> o >> b >> k;
	s.KreirajObjekat(br, brr, o, b, k);
	return ulaz;
}

std::ostream& operator<<(std::ostream& izlaz, Sport& s)
{
	izlaz << s.brojIgraca << " " << s.brojRezervnih << " " << s.obuca << " " << s.budzet << " " << s.koef;
	return izlaz;
}
