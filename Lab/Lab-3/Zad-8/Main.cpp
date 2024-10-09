#include <iostream>
#include "GeometrijskaSlika.h"
#include "Krug.h"
#include "Kvadrat.h"
#include <time.h>

// treba 2018 al nmg ga cekam da mi ispise
#define MAXSIZE 10

using namespace std;

int main() {

	GeometrijskaSlika** figure;
	figure = new GeometrijskaSlika * [MAXSIZE];
	
	srand(time(0));
	for (int i = 0; i < MAXSIZE; i += 2) {
		figure[i] = new Krug(rand()%255+1, rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
		figure[i + 1] = new Kvadrat(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
	}
	
	// sortiranje
	for (int i = 0; i < MAXSIZE; ++i)
		for (int j = i + 1; j < MAXSIZE; ++j)
			if (figure[i]->jeVeca(figure[j]))
				swap(figure[i], figure[j]);

	for (int i = 0; i < MAXSIZE; i++)
		figure[i]->show();

	// treba jos nesto i u fajl... al to je to otp

	delete [] figure;

	return 0;
}