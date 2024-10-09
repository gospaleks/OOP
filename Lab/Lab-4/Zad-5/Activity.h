#pragma once
#include "Step.h"
#include <fstream>
#include <iostream>
using namespace std;
class Activity : public Step
{
private:
	int obavezna;
public:
	Activity();
	Activity(char* nnaziv, int o);
	virtual ~Activity();
	Activity(Step* a) :Step(a) {
		obavezna = a->GetSpecAttribute();
	}

	virtual int GetSpecAttribute() { return obavezna; }
	virtual void Prikazi(ostream& izlaz);
	friend istream& operator>>(istream& ulaz, Activity& a);
};

