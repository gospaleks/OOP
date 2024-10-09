#include "Displej.h"
#include <iostream>
using namespace std;

Displej::Displej()
{
	reset();
}

Displej::Displej(int ccifra)
{
	cifra = ccifra;
}

void Displej::set(int ccifra)
{
	if (ccifra >= 0 && ccifra <= 15)
		cifra = ccifra;
	else
		cifra = 0;
}

void Displej::reset()
{
	cifra = 0;
}

void Displej::inc()
{	
	cifra++;
	cifra = cifra % 16;
}

void Displej::show()
{
	cout << "Displej: " << hex << cifra << endl;
}