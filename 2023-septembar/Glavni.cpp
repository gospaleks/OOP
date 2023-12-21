#include <iostream>
#include <fstream>
#include "KolekcijaKupovina.h"
#include "RobaKes.h"
#include "RobaRate.h"
using namespace std;

int main()
{
	ifstream ulaz("ulaz.txt");
	if (ulaz.good())
	{
		KolekcijaKupovina k;
		k.ucitaj(ulaz);
		k.ispissvihprodaja();
		/*RobaKes* min = new RobaKes();
		RobaKes* max = new RobaKes();
		k.vratiminmax(min, max);
		cout << endl << "--------------------------------" << endl << "min max" << endl << endl;
		min->prikazi();
		max->prikazi();*/
		int br = k.vratibrojkupovina(0, 8000, 123);
		cout << endl << "--------------------------" << endl << "broj kupovina proizvoda 123 je: " << br << endl;
		float ukupnacean = k.ukupnacenaprodata(0, 8500);
		cout << endl << "--------------------------" << endl << "ukupna cena prodata je: " << ukupnacean << endl;
		float dugovanje = k.dugovanje(0);
		cout << endl << "--------------------------" << endl << "dugoavnje je: " << dugovanje << endl;
		k.ubacikupovinu(new RobaKes(123, 230, 8700, 12000, 70));
		k.ispissvihprodaja();
		k.ubacikupovinu(new RobaKes(124, 241, 8701, 13000, 60));
		k.ispissvihprodaja();
		/*k.ubacikupovinu(new RobaKes(124, 241, 8701, 13000, 60));*/
		k.vratiproizvod(5); //ne radi
		k.ispissvihprodaja();

		//NESTO JEBE, NIKO NE ZNA VISE STA, KO HOCE NEKA DEBAGIRA
		//ALI KOMPAJLUJE SE, TO JE NAJBITNIJE
		//ONLY GOD KNOWS HOW IT WORKS
	}
}