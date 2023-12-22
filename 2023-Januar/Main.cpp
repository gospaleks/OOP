#include "Karta.h"
#include "DnevnaKarta.h"
#include "DnevnoNocnaKarta.h"
#include "Preduzece.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	// IMA SAMO TRI KARTE MRZI ME DA DODAJEM

	
	ifstream ulaz("ulaz.txt");
	if (ulaz.good()) {

		Preduzece* p = new Preduzece(10);

		int zaUcitavanje; ulaz >> zaUcitavanje;
		for (int i = 0; i < zaUcitavanje; ++i) {

			char tipkarte;
			ulaz.ignore();
			ulaz.get(tipkarte);

			if (tipkarte == 'd') {
				int p1;
				int p2;
				int p3;
				double p4;
				double p5;
				ulaz >> p1 >> p2 >> p3 >> p4 >> p5;
				p->dodajKartu(new DnevnaKarta(p1, p2, p3, p4, p5));
			}
			else if (tipkarte == 'n') {
				int p1;
				int p2;
				int p3;
				double p4;
				double p5;
				double p6;
				int p7;
				ulaz >> p1 >> p2 >> p3 >> p4 >> p5 >> p6 >> p7;
				p->dodajKartu(new DnevnoNocnaKarta(p1, p2, p3, p4, p5, p6, p7));
			}
		}
		ulaz.close();

		// OSNOVNI PRIKAZ I BR VAZECIH KARATA
		cout << setw(25) << left << "BR VAZECIH DNEVNIH: " << p->brojVazecihKarata(21, "Dnevna-Karta") << endl;
		cout << setw(25) << left << "UKUPNA ZARADA: " << p->ukupnaZarada() << endl;
		p->prikazi(cout);

		// ovo u principu ne mora
		ofstream izlaz("izlaz.txt");
		p->prikazi(izlaz);
		izlaz.close();
		

		// KARTE SA NAJKRACIM I NAJDUZIM TRAJANJEM
		Karta* mmin = nullptr;
		Karta* mmax = nullptr;
		cout << "\nKARTE SA NAJKRACIM I NAJDUZIM TRAJANJEM:\n\n";
		p->minMax(&mmin, &mmax);
		mmin->prikazi(cout);
		mmax->prikazi(cout);


		// PRODUZENA JEDNA KARTA
		p->produziTrajanje(2, 2);
		p->prikazi(cout);

		// OBRISANA KARTA
		p->obrisiKartu(3);
		p->prikazi(cout);


		delete p;
	}


	return 0;
}
