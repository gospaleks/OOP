#include "Student.h"
#include<string.h>

Student::Student()
{
	ime = new char[10];
	prezime = new char[20];
	brojIndeksa = 0;
	maxIspiti = 0;
	brojPolozenih = 0;
	ocene = nullptr;
}

// ovde bolje stavi const char* prezime jer ti onda ne treba cast-ovanje ako oces
// da prosledis literal
// veljanovski se jezi kad nema const
Student::Student(char* ime, char* prezime, int brojIndeksa, int maxIspiti, int brojPolozenih)
{
	// i ovde strlen(ime)+1
	// nmp dal ovo uopste radi
	this->ime = new char[strlen(ime)];
	strcpy(this->ime, ime);
	this->prezime = new char[strlen(prezime)];
	strcpy(this->prezime, prezime);
	this->brojIndeksa = brojIndeksa;
	this->maxIspiti = maxIspiti;
	this->brojPolozenih = brojPolozenih;
	this->ocene = new int[brojPolozenih];
}

void Student::dodajOcenu()
{
	int tempOcena;
	cout << "koja ocena se dodaje?" << endl;
	cin >> tempOcena;
	
	brojPolozenih++;
	int* temp;
	temp = new int[brojPolozenih];					//zauzmi memoriju za temp
	for (int i = 0; i < brojPolozenih-1; i++)
		temp[i] = ocene[i];
	temp[brojPolozenih-1] = tempOcena;				//kopiraj u pomocni niz
	
	delete[] ocene;									//oslobodi memoriju ocena
	
	ocene = temp;
}

void Student::input()
{
	cout << "uneti ime studenta:" << endl;
	fgets(ime, 10, stdin);
	cout << "uneti prezime studenta:" << endl;
	fgets(prezime, 20, stdin);						//unos prezimena
	
	cout << "uneti broj indeksa:" << endl;
	cin >> brojIndeksa;								//unos broja indeksa
	
	cout << "uneti max ispite:" << endl;
	cin >> maxIspiti;								//unos max ispita
	
	cout << "uneti broj polozenih ispita:" << endl;
	cin >> brojPolozenih;							//unos broja polozenih
	
	ocene = new int[brojPolozenih];

	cout << "uneti ocenu po ocenu:" << endl;
	for (int i = 0; i < brojPolozenih; i++)
		do 
		{
			cout << i << ": ";
			cin >> ocene[i]; 							//unos ocena
		} while (ocene[i] < 5 || ocene[i]>10);
}

void Student::prikazOcena()
{
	for (int i = 0; i < brojPolozenih; i++)
		cout << ocene[i] << " ";
}

void Student::output()
{
	cout << "-----------------------------------------\n";
	cout << "informacije o studentu su:" << endl;
	cout << "Ime: " << ime << endl << "Prezime: " << prezime << endl
		<< "Broj indeksa: " << brojIndeksa << endl << "Max ispiti: " << maxIspiti << endl
		<< "Broj polozenih ispita: " << brojPolozenih << endl << "Ocene su:\n";
	prikazOcena();
	cout << "-----------------------------------------\n";
}

void Student::azuriraj()
{
	cout << "Uneti novo ime: ";
	delete[] ime;
	ime = new char[10];
	getchar();
	fgets(ime, 10, stdin);

	cout << "uneti novo prezime studenta: ";
	delete[] prezime;
	prezime = new char[20];
	fgets(prezime, 20, stdin);
}
