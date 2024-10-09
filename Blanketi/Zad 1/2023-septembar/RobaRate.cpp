#include "RobaRate.h"
#include<iostream>
#define danasnjiDan 8754
using namespace std;

RobaRate::RobaRate()
	:RobaKes(){
	svotaplacena = brojrata = brojdana = brojplacenih = placenodosad = 0;
	rate = 1;
}

RobaRate::RobaRate(int kkod, int ssifra, int ddan, int ccena, int ppopust, int ssvota, int brata, int bdana, int bplacenih)
	:RobaKes(kkod, ssifra, ddan, ccena, ppopust){
	svotaplacena = ssvota;
	brojrata = brata;
	brojdana = bdana;
	brojplacenih = bplacenih;
	cenasapopustom = cena;
	rate = 1;
	if (dan + brojrata * brojdana <= danasnjiDan)
		placenodosad = cena;
	else
		placenodosad = ((danasnjiDan - dan) / brojdana + 1) * ((float)cena / brojrata);
		//uzimajuci u obzir da je kupac platio i na danasnji dan ako se palo da je danas placanje rate
}

void RobaRate::prikazi()
{
	cout  << "proizvod je kupljen na RATE:" << endl << "sifra proizvoda: " << kod << endl << "kod kupovine: " << sifra << endl << "dan kupovine: " << dan << endl << "cena: " << cena << endl << "pupust: " << popust << endl << "cena sa popustom: " << cenasapopustom << endl << "svota placena odmah je: " << svotaplacena << endl << "broj rata je: " << brojrata << endl << "broj dana izmedju rata je: " << brojdana << endl << "broj placenih rata je: " << brojplacenih << endl << "ukupan novac uplacen do sad je: " << placenodosad << endl << endl;
}
