#include <iostream>
#include <fstream>
#include "Tekst.h"
#include "Paragraf1.h"
#include "Paragraf2.h"
using namespace std;

int main()
{
	Tekst* t = new Tekst();
	t->citaj((char*)"ulaz.txt");
	t->dodajParagraf(*(new Paragraf1((char*)"JOS neki")));
	t->dodajParagraf(*(new Paragraf2((char*)"ovo prekoraci PET")));
	t->upisi((char*)"izlaz.txt");
	delete t;
	return 0;
}