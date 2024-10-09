#include <iostream>
#include <fstream>
#include "Bioskop.h"
#include "Film.h"

using namespace std;

int main() {

	try {
		Bioskop<float> bFloat;
		cout << "Unesite minOcenu, broj elemenata i same elemente:\n";
		cin >> bFloat;

		bFloat.Obrisi(1);
		bFloat.PromeniOcenu(2, 100.0f);
		cout << "Broj filmova za ocenom 10 je:\t" << bFloat.BrojFilmovaSaOcenom(10.0f) << endl;

		float minP, maxP;
		bFloat.VratiMinMaxPodatak(&minP, &maxP);
		cout << "Filmovi sa min i max ocenom:\t" << minP << ", " << maxP << endl;

		cout << bFloat << endl << endl;
		bFloat.Sacuvaj("spisakFloat.txt");
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}

	try {
		Bioskop<Film> bFilm;
		bFilm.Ucitaj("spisakFilm.txt");
		cout << bFilm;
		bFilm.Obrisi(1);
		bFilm.PromeniOcenu(2, 100);
		cout << "Broj filmova sa ocenom 100 je:\t" << bFilm.BrojFilmovaSaOcenom(100) << endl;
		
		Film fMin;
		Film fMax;
		bFilm.VratiMinMaxPodatak(&fMin, &fMax);
		cout << "Filmovi sa min i max ocenom:\n";
		cout << fMin << endl;
		cout << fMax << endl << endl;
		cout << bFilm;
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}

	return 0;
}