#include "Ruza.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;

double Ruza::cenaSavrseneRuze;

Ruza::Ruza(int r, int g, int b)
	: Cvet("Ruza"), R(r), G(g), B(b) {
}

double Ruza::getCena()
{
	double naStepen = pow((255 - B), 0.25);
	return (cenaSavrseneRuze / ((255-R)*(255-G)*naStepen));
}

void Ruza::ispisi(ostream& izlaz)
{
	izlaz << "Ruza -> (" << setw(3) << R << ", " << setw(3) << G << ", " << setw(3) << B << "), CENA: " <<  getCena() << "\n";
}
