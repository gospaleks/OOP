#include "KompleksanBroj.h"
#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;

KompleksanBroj::KompleksanBroj()
	:Broj((char*)"Kompleksan Broj") {
	a = b = 0;
}

KompleksanBroj::KompleksanBroj(int aa, int bb)
	:Broj((char*)"Kompleksan broj", sqrt(aa*aa + bb*bb)), a(aa), b(bb) {
}

KompleksanBroj::~KompleksanBroj()
{
}

void KompleksanBroj::PostaviVrednost(double d)
{
	a = b = d / sqrt(2);
	Broj::PostaviVrednost(d);
}

void KompleksanBroj::Print()
{
	cout << VratiVrstu() << ": " << showpos << a << b << "j = " << VratiVrednost();
	cout << endl;
}
