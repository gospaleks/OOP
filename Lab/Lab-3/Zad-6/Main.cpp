#include "DialogWindow.h"
#include "DocumentWindow.h"
#include <iostream>
#include <time.h> 
#include <string> 
#include <fstream> 
using namespace std;

int main() {

	Window* niz[2018];

	srand(time(0));
	for (int i = 0; i < 2018; ++i) {
		if (i % 2 == 0)
		{
			int randBroj = rand() % 122;
			if (randBroj < 48)
				randBroj += 48;

			string naslov = "DialogWindow_";
			naslov += randBroj;
			niz[i] = new DialogWindow(naslov, 0);
		}
		else
		{
			int randBroj = rand() % 122;
			if (randBroj < 48)
				randBroj += 48;

			string naslov = "DoocumentWindow_";
			naslov += randBroj;
			niz[i] = new DocumentWindow(naslov, 1);
		}
	}

	for (int i = 0; i < 2018; ++i) {
		for (int j = i + 1; j < 2018; ++j)
			if (niz[i]->jeVeci(niz[j]))
				swap(niz[i], niz[j]);
	}

	
	ofstream izlaz("izlaz.txt");
	
	for (int i = 0; i < 2018; ++i) {
		
		if (i % 4 == 0)
			niz[i]->confirm();
		if (i % 4 == 1)
			niz[i]->open();
		if (i % 4 == 2)
			niz[i]->cancel();
		if (i % 4 == 3)
			niz[i]->close();

		niz[i]->Window::draw(izlaz);
	}

	izlaz.close();

	for (int i = 0; i < 2018; ++i)
		delete niz[i];
	delete[] niz;

	
	return 0;
}