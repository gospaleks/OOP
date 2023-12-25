#pragma once
#include "Proizvod.h"
#include <fstream>
using namespace std;

class Kondenzator : public Proizvod
{
private:
	float c;	// kapacitivnost
public:
	Kondenzator();
	Kondenzator(const char* _barkod, float _c);
	~Kondenzator() { }

	virtual bool jeDefektan();
	virtual void prikazi(ostream& izlaz);
};

