#include <iostream>
#include "Laptop.h"
#include "Torba.h"
using namespace std;

int main() {

	Artikal* laptop = new Laptop((char*)"HP", 68990.90, (char*)"Biznis laptop");
	Artikal* torba = new Torba((char*)"Torba1", 3500.90);
	((Torba*)torba)->put(*laptop);
	torba->showDescription();
	((Torba*)torba)->remove();
	
	delete torba;

	return 0;
}