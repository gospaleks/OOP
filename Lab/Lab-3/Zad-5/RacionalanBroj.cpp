#include "RacionalanBroj.h"
#include <iostream>
#include <time.h>
using namespace std;

RacionalanBroj::RacionalanBroj()
	:Broj((char*)"Racionalan Broj") {
	a = b = 0;
}

RacionalanBroj::RacionalanBroj(int aa, int bb)
	:Broj((char*)"Racionalan Broj", (double)aa/bb), a(aa), b(bb) {
}

RacionalanBroj::RacionalanBroj(double d)
	:Broj((char*)"Racionalan Broj", d) {
	PostaviVrednost(d);
}

RacionalanBroj::~RacionalanBroj()
{
}

void RacionalanBroj::PostaviVrednost(double d)
{
	b = (rand() % 20) + 1;
	a = d * b;
}

void RacionalanBroj::Print()
{
	cout << VratiVrstu() << ": " << a << "/" << b << " = " << VratiVrednost();
	cout << endl;
}
