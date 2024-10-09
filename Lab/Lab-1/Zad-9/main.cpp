#include "Picture.h"
#include <iostream>
using namespace std;

void main() {
	Picture slika1(2, 2);
	slika1.ucitaj();
	slika1.resize(4, 4);
	// slika1.Brihtness(100);
	// pisem nesto ovde ide to
	slika1.ispisi();
}