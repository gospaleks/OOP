#include "ProcessQueue.h"
#include <iostream>
using namespace std;
ProcessQueue::ProcessQueue()
{
	brTrAkt = 0;
	brTrCek = 0;
	maxEl = 0;
	nizAktivni = nullptr;
	nizCekanje = nullptr;
}

ProcessQueue::ProcessQueue(int mmaxEl)
{
	brTrAkt = 0;
	brTrCek = 0;
	maxEl = mmaxEl;
	nizAktivni = new Process * [maxEl];
	for (int i = 0; i < maxEl; i++)
		nizAktivni[i] = nullptr;
	nizCekanje = new Process * [maxEl];
	for (int i = 0; i < maxEl; i++)
		nizCekanje[i] = nullptr;
}

ProcessQueue::~ProcessQueue()
{
	for (int i = 0; i < maxEl; i++)
	{
		if (nizAktivni[i] != 0)
			delete nizAktivni[i];
		if (nizCekanje[i] != 0)
			delete nizCekanje[i];
	}
	delete[] nizAktivni;
	delete[] nizCekanje;
}

void ProcessQueue::dodajProces(Process* p, int ako)
{
	if (ako == 1)
	{
		if (maxEl != brTrCek)
			nizCekanje[brTrCek++] = p;
	}
	else if(ako == 0)
		if (maxEl != brTrAkt)
			nizAktivni[brTrAkt++] = p;

}

void ProcessQueue::izbaci()
{
	for (int i = 0; i < brTrAkt; i++)
	{
		if (nizAktivni[i]->vratiStanje() == 2)
		{
			delete nizAktivni[i];
			for (int j = i; j < brTrAkt - 1; j++)
				nizAktivni[j] = nizAktivni[j + 1];
			brTrAkt--;
			--i;
		}
	}
	for (int i = 0; i < brTrCek; i++)
	{
		if (nizCekanje[i]->vratiStanje() == 2)
		{
			delete nizCekanje[i];
			for (int j = i; j < brTrCek - 1; j++)
				nizCekanje[j] = nizCekanje[j + 1];
			brTrCek--;
			--i;
		}
	}
}

void ProcessQueue::startuj(char* username, char* code)
{
	for (int i = 0; i < brTrAkt; i++)
	{
		if (nizAktivni[i]->vratiStanje() == 0)
		{
			if (nizAktivni[i]->vratiTip() == 0)
				nizAktivni[i]->start(username);
			else
				nizAktivni[i]->start(code);
		}
	}
	for (int i = 0; i < brTrCek; i++)
	{
		if (nizCekanje[i]->vratiStanje() == 0)
		{
			if (nizCekanje[i]->vratiTip() == 0)
				nizCekanje[i]->start(username);
			else
				nizCekanje[i]->start(code);
		}
	}
}

void ProcessQueue::stopiraj()
{
	for (int i = 0; i < brTrAkt; i++)
	{
		if (nizAktivni[i]->vratiStanje() == 1)
			nizAktivni[i]->stop();

		if (nizCekanje[i]->vratiStanje() == 1)
			nizCekanje[i]->stop();
	}
}

void ProcessQueue::ispisi()
{
	cout << "Max el: " << maxEl << endl;
	cout << "Niz aktivnih. Trenutni broj aktivnih: " << brTrAkt << endl;
	for (int i = 0; i < brTrAkt; ++i)
		nizAktivni[i]->prikazi();
	cout << endl << "Niz cekanja. Trenutni broj na cekanju: " << brTrCek << endl;
	for (int i = 0; i < brTrCek; ++i)
		nizCekanje[i]->prikazi();
}


