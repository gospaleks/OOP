#pragma once
#include <fstream>
using namespace std;

class Figura
{
protected:
	float x, y;
public:
	Figura();
	Figura(float xx, float yy);
	virtual void upisi(istream& ulaz) = 0;
	virtual void ispisi(ostream& izlaz) = 0;
	virtual float vratiP() = 0;
	virtual float vratiO() = 0;
	virtual float getsirina() = 0;
	virtual float getvisina() = 0;
};

