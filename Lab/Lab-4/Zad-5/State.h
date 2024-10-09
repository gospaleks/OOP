#pragma once
#include "Step.h"
#include <fstream>
#include <iostream>
using namespace std;

class State : public Step
{
private:
	int prioritet;
public:
	State();
	State(char* nnaziv, int p);
	virtual ~State();
	State(Step* s) : Step(s) {
		prioritet = s->GetSpecAttribute();
	}

	virtual int GetSpecAttribute() { return prioritet; }
	virtual void Prikazi(ostream& izlaz);
	friend istream& operator>>(istream& ulaz, State& s);
};

