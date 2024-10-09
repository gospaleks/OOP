#pragma once
#include "Step.h"
#include <fstream>
#include <iostream>
using namespace std;

class Workflow
{
private:
	int n;
	Step** niz;

	void OslobodiMem();
	void ZauzmiMem(int nn);
	void Kopiraj(Workflow& w);

public:
	Workflow();
	Workflow(int nn);
	Workflow(int nn, Step** nniz);
	~Workflow();
	Workflow(Workflow& w);

	int VratiBrEl() { return n; }
	
	void InsertAt(Step* s, int ind);
	void RemoveAt(int ind);
	Step** GetSpecificSteps(char* t, int* N);

	friend ostream& operator<<(ostream& izlaz, Workflow& w);
	Workflow& operator=(Workflow& w);
};

