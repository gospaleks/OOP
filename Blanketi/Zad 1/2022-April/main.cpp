#include "Evidencija.h"
#include "Student.h"
#include "StudentPismeniCelina.h"
#include "StudentPismeniKol.h"
#include <iostream>
using namespace std;

void main()
{
	Evidencija* e = new Evidencija(10);

	Student* s1 = new StudentPismeniKol(19000, 13, 32, 19, 19);
	Student* s2 = new StudentPismeniKol(19001, 2, 19, 20, 19);
	Student* s3 = new StudentPismeniCelina(19002, 14, 31, 30);
	Student* s4 = new StudentPismeniCelina(19003, 10, 32, 19);
	e->dodaj(s1);
	e->dodaj(s2);
	e->dodaj(s3);
	e->dodaj(s4);

	e->prikazi(cout);

	/*e->izbaci(19000);
	e->prikazi(cout);*/

	/*e->promeni(19000, 1, 1);
	e->prikazi(cout);*/

	/*e->promeni(19002, 1);
	e->prikazi(cout);*/

	/*cout << "Najvise bodova na celom ispitu: " << endl;
	Student* s5 = e->najviseCeo();
	s5->ispisi(cout);

	cout << "Najvise poena na pismenom delu: " << endl;
	Student* s6 = e->najvisePismeni();
	s6->ispisi(cout);*/

	/*cout << "Broj studenata koji su polozili ispit: "
		<< e->brPolozili() << endl;*/
}