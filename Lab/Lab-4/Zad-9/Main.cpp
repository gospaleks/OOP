#include <iostream>
#include <fstream>
#include <time.h>
#include "Azdaja.h"
#include "Mantikor.h"
#include "BeliZecevi.h"
#include "Skup.h"
using namespace std;

void main()
{
	Skup* s = new Skup();
	srand(time(0));
	int i = 0;
	while (i < 2331)
	{
		double r1 = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
		double r2 = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
		double r3 = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
		double r4 = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
		s->setI(new Azdaja(r1, r2, r3, r4), i++);
		s->setI(new Mantikor(r1, r2, r3, r4), i++);
		s->setI(new BeliZecevi(r1, r2), i++);
	}
	s->sort('m');

	ofstream izlaz("izlaz.txt");
	s->ispisi(izlaz);
	izlaz.close();
}