#include <iostream>
#include <cstdlib> 
#include <time.h> 
#include <chrono>
#include <thread>
#include "RacionalanBroj.h"
#include "KompleksanBroj.h"
using namespace std;

int main() {

	Broj** niz = new Broj*[2018];

	srand(time(0));
	int opseg = 100;
	for (int i = 0; i < 2018; i+=2)
	{
		niz[i] = new RacionalanBroj(rand()%opseg);
		niz[i+1] = new KompleksanBroj(rand() % (opseg/2), rand() % (opseg/3));
	}

	for (int i = 0; i < 2018; ++i)
		for (int j = i + 1; j < 2018; ++j)
			if (niz[i]->Veci(niz[j]))
				swap(niz[i], niz[j]);

	for (int i = 0; i < 2018; ++i) {
		niz[i]->Print();
	}

	delete [] niz;

	return 0;
}