#include "Spisak.h"
#include "Student.h"
#include <fstream>
#include <iostream>
using namespace std;

int main() {

	try {
		Spisak<int> sInt(10);

		cout << "Unesi broj studenata pa njihove indekse: ";
		cin >> sInt;
		cout << "Inicijalni spisak:\n" << sInt << endl;

		sInt.Obrisi(2);
		cout << "Obrisan student na poziciji 2:\n" << sInt << endl;

		cout << "Pozicija studenta sa indeksom 19336 je: " << sInt.OdrediMesto(19336) << endl;

		cout << "Razlika u pozicijama izmedju 19095 i 19336: " << sInt.RazlikaIzmedju(19095, 19336) << endl;

		int maxInd, minInd;
		sInt.MinMaxIndeks(&maxInd, &minInd);
		cout << "Najveci i najmanji indeks: " << maxInd << ", " << minInd << endl << endl;

		sInt.OkreniRedosled();
		cout << "Okrenut spisak:\n" << sInt << endl << endl << endl;

		sInt.Sacuvaj("spisakInt.txt");
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}

	try {
		Spisak<Student> sStudent(10);

		sStudent.Ucitaj("spisakStudent.txt");
		cout << "Inicijalni spisak:\n" << sStudent << endl;

		sStudent.Obrisi(2);
		cout << "Obrisan student na poziciji 2:\n" << sStudent << endl;

		cout << "Pozicija studenta sa indeksom 19336 je: " << sStudent.OdrediMesto(Student(19336, "Marijana", "Rancic", 6.67)) << endl;

		cout << "Razlika u pozicijama izmedju 19095 i 19336: " << sStudent.RazlikaIzmedju(Student(19095, "Aleksandar", "Gospavic", 9.5), Student(19336, "Marijana", "Rancic", 6.67)) << endl;

		Student maxInd, minInd;
		sStudent.MinMaxIndeks(&maxInd, &minInd);
		cout << "Najveci i najmanji indeks: " << maxInd << ", " << minInd << endl << endl;

		sStudent.OkreniRedosled();
		cout << "Okrenut spisak:\n" << sStudent << endl << endl << endl;
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}


	return 0;
}
