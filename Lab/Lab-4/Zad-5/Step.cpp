#include "Step.h"
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

Step::Step()
{
	naziv = nullptr;
	tip = nullptr;
}

Step::Step(char* nnaziv, char* ttip)
{
	naziv = new char[strlen(nnaziv) + 1];
	strcpy(naziv, nnaziv);

	tip = new char[strlen(ttip) + 1];
	strcpy(tip, ttip);
}

Step::~Step()
{
	if (naziv != nullptr)
		delete[] naziv;
	if (tip != nullptr)
		delete[] tip;
}

Step::Step(Step* s)
{
	naziv = new char[strlen(s->naziv) + 1];
	strcpy(naziv, s->naziv);
	tip = new char[strlen(s->tip) + 1];
	strcpy(tip, s->tip);
}

void Step::Prikazi(ostream& izlaz)
{
	izlaz << left << setw(14) << naziv << ", " << setw(8) << tip << ", ";
}


