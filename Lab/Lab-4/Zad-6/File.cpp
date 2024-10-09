#include "File.h"
#include <string.h>
#include <iostream>
using namespace std;

File::File()
	:FileSystemElement(){

}

File::File(char* iime, char* eext)
	:FileSystemElement(iime, eext){

}

File::~File()
{
}

char* File::vratiPunoIme()
{
	char* rez = new char[100];
	strcpy(rez, "");
	strcat(rez, rod->vratiPunoIme());
	strcat(rez, ime);
	strcat(rez, ".");
	strcat(rez, ext);

	return rez;
}

void File::PrintList()
{
	rod->PrintList();
}


