#include "RobaKes.h"
#include<iostream>
using namespace std;

RobaKes::RobaKes()
{
	kod = sifra = dan = cena = popust = cenasapopustom = rate = 0;
}

RobaKes::RobaKes(int kkod, int ssifra, int ddan, int ccena, int ppopust)
{
	kod = kkod;
	sifra = ssifra;
	dan = ddan; 
	cena = ccena;
	popust = ppopust;
	cenasapopustom = (float)cena * ((100-(float)popust) / 100);
	rate = 0;
}

void RobaKes::prikazi()
{
	cout << "proizvod je kupljen za KES:" << endl << "sifra proizvoda: " << kod << endl << "kod kupovine: " << sifra << endl << "dan kupovine: " << dan << endl << "cena: " << cena << endl << "pupust: " << popust << endl << "cena sa popustom: " << cenasapopustom << endl << endl;
}
