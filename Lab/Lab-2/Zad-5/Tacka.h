#pragma once
#include <iostream>
using namespace std;
class Tacka
{
private:
	double x, y, z;
public:
	Tacka();
	Tacka(double xx, double yy, double zz);
	// Tacka(const Tacka& t);

	inline double getX() { return x; }
	inline double getY() { return y; }
	inline double getZ() { return z; }

	friend istream& operator>>(istream& ulaz, Tacka& t);
	friend ostream& operator<<(ostream& izlaz, Tacka& t);
	friend Tacka operator*(double skalar, Tacka& t);		// mnozenje skalarom
	Tacka operator*(Tacka& t);
	Tacka operator+(Tacka& t);
	friend Tacka operator+(double konst, Tacka& t);
	Tacka operator-(Tacka& t);

	friend bool poredi(const Tacka& t1, const Tacka& t2);
	bool operator==(const Tacka& t);
	Tacka& operator=(const Tacka& t);


	// operator ++
	Tacka& operator++(); // prefiks
	const Tacka operator++(int); // postfiks
};

