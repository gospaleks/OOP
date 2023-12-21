#include "Putovanje.h"
#include "Put.h"
#include "PutAvion.h"
#include "PutAutobus.h"
#include <string.h>
#include <iomanip>

Putovanje::Putovanje()
{
	listaPuteva = nullptr;
	brojPlaniranihPutnika = 0;
	top = 0;
	maxPuteva = 50;
	strcpy(datumPolaska, "00-00-000");
}

Putovanje::Putovanje(int _max, const char _datumPolaska[])
{
	maxPuteva = 50;
	brojPlaniranihPutnika = _max;
	strcpy(datumPolaska, _datumPolaska);
	top = 0;

	listaPuteva = new Put * [maxPuteva];
	for (int i = 0; i < maxPuteva; ++i)
		listaPuteva[i] = nullptr;

}

Putovanje::~Putovanje()
{
	if (listaPuteva != nullptr) {
		for (int i = 0; i < maxPuteva; ++i)
			if (listaPuteva[i] != nullptr)
				delete listaPuteva[i];
		delete[] listaPuteva;
	}
}

double Putovanje::cenaZaAgenciju()
{
	double rez = 0;
	for (int i = 0; i < top; ++i)
	{
		if (listaPuteva[i] != nullptr) {
			rez += listaPuteva[i]->getCenaZaAgenciju();
		}
	}

	return rez;
}

double Putovanje::cenaZaPutnika()
{
	double rez = 0;
	for (int i = 0; i < top; ++i)
	{
		if (listaPuteva[i] != nullptr) {
			rez += listaPuteva[i]->getCenaPoPutniku();
		}
	}

	return rez;
}

void Putovanje::dodajPut(Put* p)
{
	// ovde treba dodam ako prekoraci maxPuteva da se prosiri memorija
	// jer kaze ne postoji max broj puteva za putovanje
	if (p->getMaxBrPutnika() >= brojPlaniranihPutnika && top < maxPuteva) {
		listaPuteva[top++] = p;
	}
	else {
		// ovde prosirivanje () napravi metodu da npr prosiri za duplo
	}
}

void Putovanje::prikaziDetaljePutovanja(ostream& izlaz)
{
	izlaz << "DETALJI PUTOVANJA(" << datumPolaska << "):\n\n";
	for (int i = 0; i < top; ++i) {
		if (listaPuteva[i] != nullptr) {
			listaPuteva[i]->prikaziPut(izlaz);
		}
	}
	izlaz << left << setw(20) << "UK BROJ NOCENJA: " << getUkupanBrojNocenja() << endl;
	izlaz << left << setw(20) << "PLANIRANA ZARADA: " << getPlaniranaZarada() << endl;
	izlaz << "######################################-KRAJ\n\n";
}

void Putovanje::ucitajPutovanje(const char* imeFajla)
{
	ifstream ulaz(imeFajla);
	if (ulaz.good()) {
		int n; ulaz >> n;
		for (int i = 0; i < n; ++i) {
			int tip; ulaz >> tip;
			
			// tip = 1 -> avion
			// tip = 2 -> autobus
			if (tip == 1) {
				char p1[100];
				int p2;
				int p3;
				double p4;
				char p5[100];
				int p6;
				double p7;
				ulaz >> p1 >> p2 >> p3 >> p4 >> p5 >> p6 >> p7;
				this->dodajPut(new PutAvion(p1, p2, p3, p4, p5, p6, p7));
			}
			else {
				char p1[100];
				int p2;
				int p3;
				double p4;
				double p5;
				double p6;
				double p7;
				int p8;
				ulaz >> p1 >> p2 >> p3 >> p4 >> p5 >> p6 >> p7 >> p8;
				this->dodajPut(new PutAutobus(p1, p2, p3, p4, p5, p6, p7, p8));
			}
		}
		ulaz.close();
	}
}

double Putovanje::getPlaniranaZarada()
{
	return ((cenaZaPutnika() * brojPlaniranihPutnika) - cenaZaAgenciju());
}

int Putovanje::getUkupanBrojNocenja()
{
	int rez = 0;
	for (int i = 0; i < top; ++i) {
		if (listaPuteva[i] != nullptr)
			rez += listaPuteva[i]->getBrojNocenja();
	}

	return rez;
}

void Putovanje::obrisiPut(const char* _nazivGrada)
{
	bool kraj = 0;
	for (int i = 0; i < top && !kraj; ++i) {
		if (listaPuteva[i] != nullptr) {
			if (!strcmp(listaPuteva[i]->getImeGrada(), _nazivGrada)) {
				delete listaPuteva[i];
				listaPuteva[i] = nullptr;
				for (int j = i; j < top - 1; ++j)
					listaPuteva[j] = listaPuteva[j + 1];
				--top;
				listaPuteva[top] = nullptr;
				kraj = 1;
			}
		}
	}

	if (!kraj) cout << "!!! Grad ne postoji. !!!\n";
}
