#include<iostream>
#include "Distributer.h"
#include "SalonPutnicka.h"
#include "SalonPutnickaDostavna.h"
using namespace std;

void main()
{
	Distributer* distributer = new Distributer(10);

	SalonPutnicka* s1 = new SalonPutnicka((char*) "Naziv1", 3, 2.1, 3.1, 15);
	SalonPutnicka* s2 = new SalonPutnicka((char*) "Naziv2", 4, 2.2, 3.2, 16);
	SalonPutnicka* s3 = new SalonPutnickaDostavna((char*) "Naziv3", 5, 2.3, 3.3, 17, 4, 81);
	SalonPutnicka* s4 = new SalonPutnickaDostavna((char*) "Naziv4", 6, 2.4, 3.4, 18, 7, 92);
	distributer->dodaj(s1);
	distributer->dodaj(s2);
	distributer->dodaj(s3);
	distributer->dodaj(s4);
	distributer->prikazi(cout);
	cout << "----------------------------------------------------" << endl;
	/*distributer->izbaci(2);
	distributer->prikazi(cout);
	cout << "----------------------------------------------------" << endl;

	distributer->uvecaj(1, (char*)"Putnicka", 3);
	distributer->prikazi(cout);
	cout << "----------------------------------------------------" << endl;

	distributer->uvecaj(2, (char*)"PutnickaDostavna", 3);
	distributer->prikazi(cout);
	cout << "----------------------------------------------------" << endl;*/

	cout << "Broj objekata koji imaju veci broj objekata od zadate granice: " << distributer->veciBrZaposlenih(4) << endl;

	cout << "Ukupan broj prodatih vozila: " << distributer->brProdatihVozila();



}