#include "Tacka.h"
#include <iomanip>

Tacka::Tacka()
{
	x = y = z = 0;
}

Tacka::Tacka(double xx, double yy, double zz) :x(xx), y(yy), z(zz) { }

// OPERATORSKE FUNKCIJE
istream& operator>>(istream& ulaz, Tacka& t)
{
	ulaz >> t.x >> t.y >> t.z;
	return ulaz;
}

ostream& operator<<(ostream& izlaz, Tacka& t)
{
	izlaz << "(" << setw(2) << t.x << ", " << setw(2) << t.y << ", " << setw(2) << t.z << ")";
	return izlaz;
}

Tacka Tacka::operator*(Tacka& t)
{
	return Tacka(t.x * this->x, t.y * this->y, t.z * this->z);
}

Tacka Tacka::operator+(Tacka& t)
{
	return Tacka(t.x + this->x, t.y + this->y, t.z + this->z);
}

Tacka Tacka::operator-(Tacka& t)
{
	return Tacka(this->x - t.x, this->y - t.y, this->z - t.z);
}

Tacka operator*(double skalar, Tacka& t)
{
	return Tacka(skalar * t.x, skalar * t.y, skalar * t.z);
}

Tacka operator+(double konst, Tacka& t)
{
	return Tacka(konst + t.x, konst + t.y, konst + t.z);
}


// MOJE DODATNO

// Ovo je za sort da ih po nesto poredi jer ima 3 koord.
bool poredi(const Tacka& t1, const Tacka& t2)
{
	return (t1.x > t2.x || t1.y > t2.y);
}

bool Tacka::operator==(const Tacka& t)
{
	if (this->x == t.x && this->y == t.y && this->z == t.z)
		return true;
	return false;
}

Tacka& Tacka::operator=(const Tacka& t)
{
	if (this != &t) {
		this->x = t.x;
		this->y = t.y;
		this->z = t.z;
	}
	return *this;
}

// prefiksni
Tacka& Tacka::operator++()
{
	this->x += 1;
	this->y += 1;
	this->z += 1;
	return *this;
}

// postfiksni
const Tacka Tacka::operator++(int)
{
	Tacka tmp(this->x, this->y, this->z);
	this->x += 1;
	this->y += 1;
	this->z += 1;
	return tmp;
}
