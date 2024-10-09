#include "Putovanje.h"
#include "Put.h"
#include "PutAvion.h"
#include "PutAutobus.h"
#include "Agencija.h"

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	Agencija* agencija = new Agencija();
	
	// NAPRAVI PUTOVANJE_1
	Putovanje* putovanje1 = new Putovanje(20, "30-12-2023");
	putovanje1->ucitajPutovanje("putovanje.txt");

	// NAPRAVI PUTOVANJE_2
	Putovanje* putovanje2 = new Putovanje(20, "12-01-2024");
	Put* p1 = new PutAvion((char*)"Instambul", 21, 3, 4000, (char*)"AirSerbia", 65, 3250);
	Put* p2 = new PutAutobus((char*)"Zagreb", 20, 2, 2000, 450, 203, 7, 1);
	Put* p3 = new PutAvion((char*)"New York", 25, 5, 16000, (char*)"AirSerbia", 720, 11125);
	Put* p4 = new PutAutobus((char*)"Leskovac", 20, 7, 1250, 81, 203, 7, 0);
	putovanje2->dodajPut(p1);
	putovanje2->dodajPut(p2);
	putovanje2->dodajPut(p3);
	putovanje2->dodajPut(p4);

	// DODAJ_PUTOVANJA
	agencija->dodajPutovanje(putovanje1);
	agencija->dodajPutovanje(putovanje2);

	// UPISATI JEDNO PUTOVANJE U FAJL
	ofstream izlaz("plan_putovanja.txt");
	if (izlaz.good()) {
		agencija->get(1)->prikaziDetaljePutovanja(izlaz);
	}
	izlaz.close();
	
	// OBRISATI JEDAN PUT
	agencija->get(0)->obrisiPut("Beograd");
	agencija->get(0)->prikaziDetaljePutovanja(cout);


	//agencija->prikaziSvaPutovanja(cout);
	delete agencija;



	return 0;
}