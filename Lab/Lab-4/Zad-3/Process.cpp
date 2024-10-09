#include "Process.h"
#include <iostream>
using namespace std;

Process::Process()
{
	sifra = 0;
	stanje = 0;
	tip = 0;
}

Process::~Process()
{
}

Process::Process(int ssifra, int ttip)
{
	this->sifra = ssifra;
	this->stanje = 0;
	this->tip = ttip;
}

void Process::prikazi()
{
	cout << "Sifra: " << sifra << ", Stanje: " << stanje << ", Tip:  " << tip << endl;
}
