#pragma once
#include "Student.h"
#include "StudentPismeniKol.h"
#include "StudentPismeniCelina.h"
#include <iostream>
using namespace std;

class Evidencija
{
	Student** niz;
	int maxEl;
	int top;
public:
	Evidencija();
	Evidencija(int mmaxEl);
	~Evidencija();
	void dodaj(Student* s);
	void izbaci(int brInd);
	void prikazi(ostream& izlaz);
	Student* najvisePismeni();
	Student* najviseCeo();
	void promeni(int brIndeksa, int brBodova);
	void promeni(int brIndeksa, int brBodova, int kol);
	int brPolozili();
	double prosekBodova();
};

