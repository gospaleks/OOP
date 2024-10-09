#include<iostream>
#include<string.h>
using namespace std;

class Student
{
private:
	char* ime;
	char* prezime;
	int brojIndeksa;
	int maxIspiti;
	int brojPolozenih;
	int* ocene;
public:
	Student();
	Student(char* ime, char* prezime, int brojIndeksa, int maxIspiti, int brojPolozenih);

	inline void info(int* indeks, int* ispiti)
	{
		*indeks = this->brojIndeksa;
		*ispiti = this->brojPolozenih;
	}
	void dodajOcenu();
	void input();
	void prikazOcena();
	void output();
	void azuriraj();

};

