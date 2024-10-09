#include "Folder.h"
#include <string.h>
#include <iostream>
using namespace std;

Folder::Folder()
	:FileSystemElement(){
	brTrEl = 0;
	for (int i = 0; i < 2018; i++)
		niz[i] = nullptr;
}

Folder::Folder(char* iime)
	:FileSystemElement(iime, (char*)"") {
	brTrEl = 0;
	for (int i = 0; i < 2018; i++)
		niz[i] = nullptr;
}

Folder::~Folder()
{
	for (int i = 0; i < 2018; i++)
	{
		if (niz[i] != nullptr)
			delete niz[i];
	}
}

char* Folder::vratiPunoIme()
{
	if (rod == nullptr)
	{
		char* rez = new char[strlen(ime) + 1];
		strcpy(rez, ime);
		return rez;
	}
	strcat(rod->vratiPunoIme(), ime);

}

void Folder::PrintList()
{
	if (brTrEl == 0)
		cout << this->vratiPunoIme() << endl;
	else
	{
		for (int i = 0; i < 2018; ++i)
		{
			if (niz[i] != nullptr) {
				if (niz[i]->daLiJeFajl())
					cout << niz[i]->vratiPunoIme() << endl;
				else
					niz[i]->PrintList();
			}
		}
	}
}

void Folder::dodaj(FileSystemElement* podEl)
{
	int i = 0;
	while (niz[i] != nullptr)
		i++;
	niz[i] = podEl;
	niz[i]->postaviRod(this);
	brTrEl++;
}

void Folder::ukloni(int index)
{
	int i = 0;
	while (i < index-1) {
		if (niz[i] != nullptr)
			++i;
	}
	niz[i]->postaviRod(nullptr);
	niz[i] = nullptr;
	brTrEl--;
}



