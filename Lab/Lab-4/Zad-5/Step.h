#pragma once
#include <fstream>
#include <iostream>
using namespace std;

class Step
{
protected:
	char* naziv;
	char* tip;
public:
	Step();
	Step(char* nnaziv, char* ttip);
	virtual ~Step();
	Step(Step* s);

	char* VratiNaziv() { return naziv; }
	char* VratiTip() { return tip; }
	virtual int GetSpecAttribute() = 0;
	virtual void Prikazi(ostream& izlaz);
};

